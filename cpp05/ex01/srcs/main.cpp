/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 12:48:49 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/21 12:48:53 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

static void testConstruction(void)
{
	std::cout << "-- construction --" << std::endl;

	Form contract("Contract", 40, 60);
	std::cout << contract;

	try
	{
		Form tooHigh("Ghost", 0, 60);
		(void)tooHigh;
	}
	catch (std::exception &e)
	{
		std::cout << "sign-grade 0 rejected: " << e.what() << std::endl;
	}

	try
	{
		Form tooLow("Ghost", 40, 151);
		(void)tooLow;
	}
	catch (std::exception &e)
	{
		std::cout << "execute-grade 151 rejected: " << e.what() << std::endl;
	}
}

static void testSigning(void)
{
	std::cout << std::endl << "-- signing --" << std::endl;

	Form contract("Contract", 40, 60);
	Bureaucrat intern("Intern", 100);
	Bureaucrat boss("Boss", 10);

	intern.signForm(contract);
	std::cout << contract;

	boss.signForm(contract);
	std::cout << contract;
}

static void testCopy(void)
{
	std::cout << std::endl << "-- copy constructor --" << std::endl;

	Form original("Original", 50, 50);
	Bureaucrat boss("Boss", 1);
	boss.signForm(original);

	Form copy(original);
	std::cout << "original: " << original;
	std::cout << "copy:     " << copy;
}

int main(void)
{
	testConstruction();
	testSigning();
	testCopy();
	return (0);
}
