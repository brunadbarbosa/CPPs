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
#include <list>
#include <vector>
#include <string>
#include "MutantStack.hpp"

static void subjectTest(void) {
	std::cout << "--- subject test (MutantStack) ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}

/* Same test with std::list: the output must be identical */
static void listTest(void) {
	std::cout << "--- same test (std::list) ---" << std::endl;
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::list<int> s(mstack);
}

static void extraTests(void) {
	std::cout << "--- reverse iteration ---" << std::endl;
	MutantStack<std::string> words;
	words.push("first");
	words.push("second");
	words.push("third");
	for (MutantStack<std::string>::reverse_iterator it = words.rbegin(); it != words.rend(); ++it)
		std::cout << *it << std::endl;

	std::cout << "--- modify through iterators ---" << std::endl;
	MutantStack<int> numbers;
	for (int i = 1; i <= 5; i++)
		numbers.push(i);
	for (MutantStack<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
		*it *= 10;
	std::cout << "top: " << numbers.top() << std::endl;

	std::cout << "--- copy and const iteration ---" << std::endl;
	MutantStack<int> const copy(numbers);
	numbers.pop();
	for (MutantStack<int>::const_iterator it = copy.begin(); it != copy.end(); ++it)
		std::cout << *it << " ";
	std::cout << "(copy size " << copy.size() << ", original size " << numbers.size() << ")" << std::endl;

	std::cout << "--- assignment ---" << std::endl;
	MutantStack<int> assigned;
	assigned = numbers;
	std::cout << "assigned top: " << assigned.top() << ", size: " << assigned.size() << std::endl;

	std::cout << "--- other underlying container (std::vector) ---" << std::endl;
	MutantStack<int, std::vector<int> > vstack;
	vstack.push(42);
	vstack.push(21);
	for (MutantStack<int, std::vector<int> >::iterator it = vstack.begin(); it != vstack.end(); ++it)
		std::cout << *it << std::endl;
}

int main(void) {
	subjectTest();
	listTest();
	extraTests();
	return (0);
}
