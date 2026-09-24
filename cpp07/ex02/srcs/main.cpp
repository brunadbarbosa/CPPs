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
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750

/* ----- test given with the subject ----- */
static int subjectTest(void) {
	Array<int> numbers(MAX_VAL);
	int *mirror = new int[MAX_VAL];
	std::srand(std::time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = std::rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i]) {
			std::cerr << "didn't save the same value!!" << std::endl;
			delete[] mirror;
			return (1);
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = std::rand();
	}
	delete[] mirror;
	return (0);
}

/* ----- extra tests ----- */
static void extraTests(void) {
	std::cout << "--- empty array ---" << std::endl;
	Array<int> empty;
	std::cout << "size: " << empty.size() << std::endl;
	try {
		empty[0] = 1;
	}
	catch (const std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}

	std::cout << "--- default initialization (new int()) ---" << std::endl;
	Array<int> zeros(5);
	for (unsigned int i = 0; i < zeros.size(); i++)
		std::cout << zeros[i] << " ";
	std::cout << std::endl;

	std::cout << "--- deep copy ---" << std::endl;
	Array<std::string> original(3);
	original[0] = "a";
	original[1] = "b";
	original[2] = "c";
	Array<std::string> copy(original);
	Array<std::string> assigned;
	assigned = original;
	original[0] = "CHANGED";
	std::cout << "original[0]: " << original[0] << std::endl;
	std::cout << "copy[0]:     " << copy[0] << std::endl;
	std::cout << "assigned[0]: " << assigned[0] << std::endl;

	std::cout << "--- const array ---" << std::endl;
	Array<std::string> const constArray(copy);
	for (unsigned int i = 0; i < constArray.size(); i++)
		std::cout << constArray[i] << " ";
	std::cout << std::endl;
	try {
		std::cout << constArray[3] << std::endl;
	}
	catch (const std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
}

int main(int, char **) {
	if (subjectTest() != 0)
		return (1);
	extraTests();
	return (0);
}
