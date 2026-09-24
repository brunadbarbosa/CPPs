/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>
#include <climits>
#include "Span.hpp"

static void subjectTest(void) {
	std::cout << "--- subject test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

static void exceptionTests(void) {
	std::cout << "--- exceptions ---" << std::endl;
	Span sp(2);
	try {
		sp.shortestSpan();
	}
	catch (std::exception const &e) {
		std::cout << "0 numbers: " << e.what() << std::endl;
	}
	sp.addNumber(1);
	try {
		sp.longestSpan();
	}
	catch (std::exception const &e) {
		std::cout << "1 number:  " << e.what() << std::endl;
	}
	sp.addNumber(2);
	try {
		sp.addNumber(3);
	}
	catch (std::exception const &e) {
		std::cout << "full:      " << e.what() << std::endl;
	}
	try {
		std::vector<int> tooMany(5, 42);
		Span small(3);
		small.addRange(tooMany.begin(), tooMany.end());
	}
	catch (std::exception const &e) {
		std::cout << "range too big: " << e.what() << std::endl;
	}
}

static void limitsTest(void) {
	std::cout << "--- INT_MIN / INT_MAX (no overflow) ---" << std::endl;
	Span sp(3);
	sp.addNumber(INT_MIN);
	sp.addNumber(INT_MAX);
	sp.addNumber(0);
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest:  " << sp.longestSpan() << std::endl;
}

static void bigTest(unsigned int n) {
	std::cout << "--- " << n << " random numbers (addRange) ---" << std::endl;
	std::vector<int> numbers;
	for (unsigned int i = 0; i < n; i++)
		numbers.push_back(std::rand());

	Span sp(n);
	sp.addRange(numbers.begin(), numbers.end());
	std::cout << "size:     " << sp.size() << std::endl;
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest:  " << sp.longestSpan() << std::endl;
}

static void rangeFromListTest(void) {
	std::cout << "--- addRange from a std::list ---" << std::endl;
	std::list<int> lst;
	for (int i = 0; i < 10; i++)
		lst.push_back(i * i);
	Span sp(10);
	sp.addRange(lst.begin(), lst.end());
	std::cout << "shortest: " << sp.shortestSpan() << std::endl;
	std::cout << "longest:  " << sp.longestSpan() << std::endl;

	std::cout << "--- copy is independent ---" << std::endl;
	Span a(3);
	a.addNumber(1);
	a.addNumber(10);
	Span b(a);
	b.addNumber(11);
	std::cout << "a.size() = " << a.size() << ", b.size() = " << b.size() << std::endl;
	std::cout << "a.shortestSpan() = " << a.shortestSpan()
		<< ", b.shortestSpan() = " << b.shortestSpan() << std::endl;
}

int main(void) {
	std::srand(std::time(NULL));

	subjectTest();
	exceptionTests();
	limitsTest();
	rangeFromListTest();
	bigTest(10000);
	bigTest(100000);
	return (0);
}
