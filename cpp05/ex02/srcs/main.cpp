/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:55:24 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/22 12:23:32 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void testShrubbery(void)
{
	std::cout << "-- shrubbery creation form --" << std::endl << std::endl;

	Bureaucrat rookie("Rookie", 150);
	Bureaucrat farmer("Farmer", 100);
	ShrubberyCreationForm form("North_Pole");

	std::cout << form;
	farmer.signForm(form);
	std::cout << form;
	rookie.executeForm(form);
	farmer.executeForm(form);
}

static void testRobotomy(void)
{
	std::cout << std::endl << "-- robotomy request form --" << std::endl << std::endl;

	Bureaucrat doctor("Dr. Madness", 1);
	Bureaucrat assistant("Assistant", 72);
	RobotomyRequestForm form("experiment");

	std::cout << form;
	assistant.signForm(form);
	std::cout << form;
	assistant.executeForm(form);
	for (int i = 0; i < 4; i++)
		doctor.executeForm(form);
}

static void testPresidentialPardon(void)
{
	std::cout << std::endl << "-- presidential pardon form --" << std::endl << std::endl;

	Bureaucrat president("President", 1);
	Bureaucrat vicePresident("Vice President", 25);
	PresidentialPardonForm form("Vice President's Son");

	std::cout << form;
	president.executeForm(form);
	vicePresident.signForm(form);
	std::cout << form;
	vicePresident.executeForm(form);
	president.executeForm(form);
}

int main(void)
{
	testShrubbery();
	testRobotomy();
	testPresidentialPardon();
	return (0);
}
