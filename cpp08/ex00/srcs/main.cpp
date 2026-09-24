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
#include <deque>
#include <string>
#include "easyfind.hpp"

template <typename T>
static void test(T &container, int value, std::string const &name) {
	try {
		typename T::iterator it = easyfind(container, value);
		std::cout << name << ": found " << *it
			<< " at position " << std::distance(container.begin(), it) << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << name << ": " << value << " -> " << e.what() << std::endl;
	}
}

int main(void) {
	int values[] = {10, 20, 30, 20, 40};

	std::vector<int> vec(values, values + 5);
	std::list<int> lst(values, values + 5);
	std::deque<int> deq(values, values + 5);

	std::cout << "--- vector ---" << std::endl;
	test(vec, 20, "vector");
	test(vec, 40, "vector");
	test(vec, 42, "vector");

	std::cout << "--- list ---" << std::endl;
	test(lst, 10, "list");
	test(lst, -1, "list");

	std::cout << "--- deque ---" << std::endl;
	test(deq, 30, "deque");
	test(deq, 0, "deque");

	std::cout << "--- modify through the returned iterator ---" << std::endl;
	*easyfind(vec, 30) = 300;
	test(vec, 300, "vector");

	std::cout << "--- const container ---" << std::endl;
	std::vector<int> const constVec(values, values + 5);
	try {
		std::vector<int>::const_iterator it = easyfind(constVec, 40);
		std::cout << "const vector: found " << *it << std::endl;
		easyfind(constVec, 99);
	}
	catch (std::exception const &e) {
		std::cout << "const vector: 99 -> " << e.what() << std::endl;
	}

	std::cout << "--- empty container ---" << std::endl;
	std::vector<int> empty;
	test(empty, 1, "empty vector");
	return (0);
}
