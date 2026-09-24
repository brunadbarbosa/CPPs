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
#include <string>
#include <cctype>
#include "iter.hpp"

template <typename T>
void print(T const &value) {
	std::cout << value << " ";
}

template <typename T>
void increment(T &value) {
	value++;
}

void toUpper(std::string &str) {
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(static_cast<unsigned char>(str[i]));
}

int main(void) {
	int numbers[] = {1, 2, 3, 4, 5};
	size_t const numbersLength = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "int array:            ";
	::iter(numbers, numbersLength, print<int>);
	std::cout << std::endl;

	::iter(numbers, numbersLength, increment<int>);
	std::cout << "after increment:      ";
	::iter(numbers, numbersLength, print<int>);
	std::cout << std::endl;

	std::string words[] = {"hello", "from", "iter"};
	::iter(words, 3, toUpper);
	std::cout << "string array (upper): ";
	::iter(words, 3, print<std::string>);
	std::cout << std::endl;

	int const constNumbers[] = {10, 20, 30};
	std::cout << "const int array:      ";
	::iter(constNumbers, 3, print<int>);
	std::cout << std::endl;

	double decimals[] = {1.5, 2.5};
	::iter(decimals, 2, increment<double>);
	std::cout << "double array:         ";
	::iter(decimals, 2, print<double>);
	std::cout << std::endl;

	std::cout << "empty / NULL array:   ";
	::iter(static_cast<int *>(NULL), 3, print<int>);
	std::cout << "(nothing printed)" << std::endl;
	return (0);
}
