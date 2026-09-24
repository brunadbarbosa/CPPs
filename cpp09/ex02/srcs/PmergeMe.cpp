/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <climits>
#include <cctype>
#include <ctime>

PmergeMe::PmergeMe() : _vectorTime(0), _dequeTime(0) {}

PmergeMe::PmergeMe(PmergeMe const &other) {
	*this = other;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &other) {
	if (this == &other)
		return (*this);
	this->_input = other._input;
	this->_vector = other._vector;
	this->_deque = other._deque;
	this->_vectorTime = other._vectorTime;
	this->_dequeTime = other._dequeTime;
	return (*this);
}

/* ------------------------------ Parsing ------------------------------ */

int PmergeMe::_parseNumber(std::string const &token) {
	size_t i = 0;
	long value = 0;

	if (token[i] == '+')
		i++;
	if (i == token.length())
		throw std::runtime_error("invalid number");
	for (; i < token.length(); i++) {
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			throw std::runtime_error("invalid number");
		value = value * 10 + (token[i] - '0');
		if (value > INT_MAX)
			throw std::runtime_error("number too large");
	}
	if (value == 0)
		throw std::runtime_error("not a positive number");
	return (static_cast<int>(value));
}

/* Accepts "./PmergeMe 3 5 9" and also "./PmergeMe "3 5 9"" */
void PmergeMe::parse(int argc, char **argv) {
	for (int i = 1; i < argc; i++) {
		std::istringstream iss(argv[i]);
		std::string token;
		bool empty = true;

		while (iss >> token) {
			this->_input.push_back(_parseNumber(token));
			empty = false;
		}
		if (empty)
			throw std::runtime_error("empty argument");
	}
	if (this->_input.empty())
		throw std::runtime_error("no numbers");
}

/* ----------------------- Ford-Johnson (vector) ----------------------- */
/*                                                                      */
/* 1. Make pairs (a, b) with b <= a. An odd element is left aside.      */
/* 2. Recursively sort the larger elements (the a's) with the same      */
/*    algorithm.                                                        */
/* 3. Main chain = b1, a1, a2, ... an (b1 <= a1, so it goes first).     */
/* 4. Insert the other b's with binary search, in the order given by    */
/*    the Jacobsthal numbers (b3 b2, b5 b4, b11 ... b6, ...). Each b_k   */
/*    only needs to be searched before its a_k, and this order keeps    */
/*    every search range at 2^x - 1 elements = minimum comparisons.     */
/*                                                                      */
/* The chain stores indices into "values", so every b always knows     */
/* where its own a is (even with duplicate values). The function        */
/* returns the order used, so the caller can find the partners after    */
/* the recursive call: after sorting, values[k] == old values[order[k]] */

static size_t binarySearchVector(std::vector<int> const &values,
	std::vector<size_t> const &chain, size_t end, int value) {
	size_t low = 0;
	size_t high = end;

	while (low < high) {
		size_t middle = low + (high - low) / 2;
		if (value < values[chain[middle]])
			high = middle;
		else
			low = middle + 1;
	}
	return (low);
}

std::vector<size_t> PmergeMe::_sortVector(std::vector<int> &values) {
	size_t const n = values.size();
	std::vector<size_t> chain;

	if (n < 2) {
		if (n == 1)
			chain.push_back(0);
		return (chain);
	}

	/* 1. pairs */
	size_t const pairs = n / 2;
	std::vector<int> larger;
	std::vector<size_t> largerIndex;
	std::vector<size_t> smallerIndex;
	for (size_t i = 0; i < pairs; i++) {
		size_t small = 2 * i;
		size_t big = 2 * i + 1;
		if (values[small] > values[big])
			std::swap(small, big);
		smallerIndex.push_back(small);
		largerIndex.push_back(big);
		larger.push_back(values[big]);
	}

	/* 2. recursive sort of the larger elements */
	std::vector<size_t> largerOrder = _sortVector(larger);

	/* 3. main chain: b1, a1 ... an */
	chain.push_back(smallerIndex[largerOrder[0]]);
	for (size_t k = 0; k < pairs; k++)
		chain.push_back(largerIndex[largerOrder[k]]);

	/* pending b2 ... bn (+ the odd element, which has no a: bound = n) */
	std::vector<size_t> pending;
	std::vector<size_t> bound;
	for (size_t k = 1; k < pairs; k++) {
		pending.push_back(smallerIndex[largerOrder[k]]);
		bound.push_back(largerIndex[largerOrder[k]]);
	}
	if (n % 2 == 1) {
		pending.push_back(n - 1);
		bound.push_back(n);
	}

	/* 4. insertion in Jacobsthal order: 1, 3, 5, 11, 21, 43, ... */
	size_t const total = pending.size() + 1;
	size_t previous = 1;
	size_t current = 3;
	while (previous < total) {
		size_t last = std::min(current, total);
		for (size_t b = last; b > previous; b--) {
			size_t p = b - 2;
			size_t end = chain.size();
			if (bound[p] != n)
				end = std::find(chain.begin(), chain.end(), bound[p]) - chain.begin();
			size_t position = binarySearchVector(values, chain, end, values[pending[p]]);
			chain.insert(chain.begin() + position, pending[p]);
		}
		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}

	/* 5. write the sorted values back */
	std::vector<int> sorted;
	sorted.reserve(n);
	for (size_t k = 0; k < n; k++)
		sorted.push_back(values[chain[k]]);
	values = sorted;
	return (chain);
}

/* ------------------------ Ford-Johnson (deque) ----------------------- */
/* Same algorithm, implemented separately for std::deque.               */

static size_t binarySearchDeque(std::deque<int> const &values,
	std::deque<size_t> const &chain, size_t end, int value) {
	size_t low = 0;
	size_t high = end;

	while (low < high) {
		size_t middle = low + (high - low) / 2;
		if (value < values[chain[middle]])
			high = middle;
		else
			low = middle + 1;
	}
	return (low);
}

std::deque<size_t> PmergeMe::_sortDeque(std::deque<int> &values) {
	size_t const n = values.size();
	std::deque<size_t> chain;

	if (n < 2) {
		if (n == 1)
			chain.push_back(0);
		return (chain);
	}

	/* 1. pairs */
	size_t const pairs = n / 2;
	std::deque<int> larger;
	std::deque<size_t> largerIndex;
	std::deque<size_t> smallerIndex;
	for (size_t i = 0; i < pairs; i++) {
		size_t small = 2 * i;
		size_t big = 2 * i + 1;
		if (values[small] > values[big])
			std::swap(small, big);
		smallerIndex.push_back(small);
		largerIndex.push_back(big);
		larger.push_back(values[big]);
	}

	/* 2. recursive sort of the larger elements */
	std::deque<size_t> largerOrder = _sortDeque(larger);

	/* 3. main chain: b1, a1 ... an */
	chain.push_back(smallerIndex[largerOrder[0]]);
	for (size_t k = 0; k < pairs; k++)
		chain.push_back(largerIndex[largerOrder[k]]);

	/* pending b2 ... bn (+ the odd element, which has no a: bound = n) */
	std::deque<size_t> pending;
	std::deque<size_t> bound;
	for (size_t k = 1; k < pairs; k++) {
		pending.push_back(smallerIndex[largerOrder[k]]);
		bound.push_back(largerIndex[largerOrder[k]]);
	}
	if (n % 2 == 1) {
		pending.push_back(n - 1);
		bound.push_back(n);
	}

	/* 4. insertion in Jacobsthal order: 1, 3, 5, 11, 21, 43, ... */
	size_t const total = pending.size() + 1;
	size_t previous = 1;
	size_t current = 3;
	while (previous < total) {
		size_t last = std::min(current, total);
		for (size_t b = last; b > previous; b--) {
			size_t p = b - 2;
			size_t end = chain.size();
			if (bound[p] != n)
				end = std::find(chain.begin(), chain.end(), bound[p]) - chain.begin();
			size_t position = binarySearchDeque(values, chain, end, values[pending[p]]);
			chain.insert(chain.begin() + position, pending[p]);
		}
		size_t next = current + 2 * previous;
		previous = current;
		current = next;
	}

	/* 5. write the sorted values back */
	std::deque<int> sorted;
	for (size_t k = 0; k < n; k++)
		sorted.push_back(values[chain[k]]);
	values = sorted;
	return (chain);
}

/* ------------------------------ Sorting ------------------------------ */
/* The time includes the data management (filling the container) and   */
/* the sort itself.                                                     */

static double elapsedMicroseconds(std::clock_t start, std::clock_t end) {
	return (static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC);
}

void PmergeMe::sort() {
	std::clock_t start = std::clock();
	this->_vector.assign(this->_input.begin(), this->_input.end());
	_sortVector(this->_vector);
	this->_vectorTime = elapsedMicroseconds(start, std::clock());

	start = std::clock();
	this->_deque.assign(this->_input.begin(), this->_input.end());
	_sortDeque(this->_deque);
	this->_dequeTime = elapsedMicroseconds(start, std::clock());
}

/* ------------------------------ Display ------------------------------ */

void PmergeMe::display() const {
	std::cout << "Before:";
	for (size_t i = 0; i < this->_input.size(); i++)
		std::cout << " " << this->_input[i];
	std::cout << std::endl;

	std::cout << "After:";
	for (size_t i = 0; i < this->_vector.size(); i++)
		std::cout << " " << this->_vector[i];
	std::cout << std::endl;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << this->_input.size()
		<< " elements with std::vector : " << this->_vectorTime << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_input.size()
		<< " elements with std::deque  : " << this->_dequeTime << " us" << std::endl;
}
