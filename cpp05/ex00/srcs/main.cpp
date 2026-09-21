/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:47:57 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/21 12:48:04 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

static void testConstruction(void)
{
	std::cout << "-- construction --" << std::endl;

	Bureaucrat a("Alice", 42);
	std::cout << a;

	try
	{
		Bureaucrat tooHigh("Ghost", 0);
		(void)tooHigh;
	}
	catch (std::exception &e)
	{
		std::cout << "grade 0 rejected: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat tooLow("Ghost", 151);
		(void)tooLow;
	}
	catch (std::exception &e)
	{
		std::cout << "grade 151 rejected: " << e.what() << std::endl;
	}
}

static void testIncrementDecrement(void)
{
	std::cout << std::endl << "-- increment / decrement --" << std::endl;

	Bureaucrat b("Bob", 3);
	std::cout << b;
	b.decrementGrade();
	std::cout << "after decrementGrade(): " << b;
	b.incrementGrade();
	b.incrementGrade();
	std::cout << "after incrementGrade() twice: " << b;
}

static void testGradeBoundaries(void)
{
	std::cout << std::endl << "-- boundaries (grade 1 and grade 150) --" << std::endl;

	Bureaucrat top("Top", 1);
	try
	{
		top.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "incrementGrade() on grade 1: " << e.what() << std::endl;
	}

	Bureaucrat bottom("Bottom", 150);
	try
	{
		bottom.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "decrementGrade() on grade 150: " << e.what() << std::endl;
	}
}

static void testCopy(void)
{
	std::cout << std::endl << "-- copy constructor / assignment --" << std::endl;

	Bureaucrat original("Original", 10);
	Bureaucrat copy(original);
	original.incrementGrade();

	std::cout << "original after incrementGrade(): " << original;
	std::cout << "copy (must stay untouched):       " << copy;
}

int main(void)
{
	testConstruction();
	testIncrementDecrement();
	testGradeBoundaries();
	testCopy();
	return (0);
}