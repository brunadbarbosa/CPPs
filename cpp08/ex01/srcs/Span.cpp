/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <numeric>

Span::Span() : _maxSize(0) {}

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(Span const &other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span::~Span() {}

Span &Span::operator=(Span const &other) {
	if (this == &other)
		return (*this);
	this->_maxSize = other._maxSize;
	this->_numbers = other._numbers;
	return (*this);
}

void Span::addNumber(int number) {
	if (this->_numbers.size() >= this->_maxSize)
		throw SpanFullException();
	this->_numbers.push_back(number);
}

/* Sort a copy: the shortest span is always between two neighbours.       */
/* The values are copied into longs so INT_MAX - INT_MIN does not overflow */
unsigned int Span::shortestSpan() const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	std::vector<long> sorted(this->_numbers.begin(), this->_numbers.end());
	std::sort(sorted.begin(), sorted.end());

	std::vector<long> differences(sorted.size());
	std::adjacent_difference(sorted.begin(), sorted.end(), differences.begin());
	/* differences[0] is just a copy of sorted[0], so it is skipped */
	return (static_cast<unsigned int>(*std::min_element(differences.begin() + 1, differences.end())));
}

unsigned int Span::longestSpan() const {
	if (this->_numbers.size() < 2)
		throw NoSpanException();
	long min = *std::min_element(this->_numbers.begin(), this->_numbers.end());
	long max = *std::max_element(this->_numbers.begin(), this->_numbers.end());
	return (static_cast<unsigned int>(max - min));
}

unsigned int Span::size() const {
	return (this->_numbers.size());
}

unsigned int Span::maxSize() const {
	return (this->_maxSize);
}

const char *Span::SpanFullException::what() const throw() {
	return ("Span: the span is already full");
}

const char *Span::NoSpanException::what() const throw() {
	return ("Span: not enough numbers to find a span");
}
