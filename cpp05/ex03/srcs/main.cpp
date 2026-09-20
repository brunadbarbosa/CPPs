/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:55:24 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/20 15:55:27 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"
#define PURPLE	"\033[35m"
#define WITHOUT_NEWLINE	0
#define WITH_NEWLINE	1

void	pressEnter(void)
{
	std::cout << std::endl << "press ENTER to continue" << std::endl;
	std::cin.ignore();
	std::cout << "\033c";
}

void debugMessageConstructors(int newline)
{
	std::cout << std::endl;
	std::cout << BLUE << "constructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageStatus(int newline)
{
	std::cout << std::endl;
	std::cout << PURPLE << "status> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageDestructors(int newline)
{
	std::cout << std::endl;
	std::cout << YELLOW << "destructors> " << RESET;
	if (newline)
		std::cout << std::endl;
}

void debugMessageAction(std::string action)
{
	std::cout << std::endl;
	std::cout << GREEN << "action> " << RESET;
	if (action.length())
		std::cout << action << std::endl;
}

void exceptionError(std::string message, std::string exception)
{
	std::cerr << RED << "\t" << message << exception << RESET << std::endl;
}

void titleHeader(const std::string& message)
{
    std::cout << "\033c";
    int standartSize = 34;
    int messageSize = message.length();
    int spaces = (standartSize - messageSize) / 2;

    std::cout << "************************************" << std::endl << "*";
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << message;
	for (int i = 0; i < spaces; i++)
		std::cout << " ";
	std::cout << "*" << std::endl << "************************************" << std::endl;
}

int	main(void)
{
	{
		titleHeader("SHRUBBERY TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theDefault = new Bureaucrat();
		Bureaucrat *theFarmer = new Bureaucrat("Sta. Klaus", 100);
		AForm *theForm = new ShrubberyCreationForm("North_Pole");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theFarmer;
		std::cout << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theFarmer);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theFarmer->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			theDefault->executeForm(*theForm);
			std::cout << "\t" << theDefault->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theDefault->getName() + " can't execute ", theForm->getName());
		}
		try
		{
			debugMessageAction("try to execute the form");
			theFarmer->executeForm(*theForm);
			std::cout << "\t" << theFarmer->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theFarmer->getName() + " can't execute ", theForm->getName());
		}

		debugMessageDestructors(WITH_NEWLINE);
		delete theFarmer;
		delete theDefault;
		delete theForm;
	}
	pressEnter();
	{
		titleHeader("ROBOTOMY TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theMadDoctor = new Bureaucrat("Dr. Madness", 1);
		Bureaucrat *theMadAssistent = new Bureaucrat("Mad Assistent", 72);
		AForm *theForm = new RobotomyRequestForm("experiment");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theMadDoctor << theMadAssistent << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theMadAssistent);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theMadAssistent->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			theMadAssistent->executeForm(*theForm);
			std::cout << "\t" << theMadAssistent->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theMadAssistent->getName() + " can't execute ", theForm->getName());
		}
		for (int i = 0; i < 4; i++)
		{
			try
			{
				debugMessageAction("try to execute the form");
				theMadDoctor->executeForm(*theForm);
				std::cout << "\t" << theMadDoctor->getName() << " executed " << theForm->getName() << std::endl;
			}
			catch(Bureaucrat::GradeTooLowException &e)
			{
				exceptionError("permission denied: ", e.what());
				exceptionError(theMadDoctor->getName() + " can't execute ", theForm->getName());
			}
		}
		debugMessageDestructors(WITH_NEWLINE);
		delete theMadDoctor;
		delete theMadAssistent;
		delete theForm;
	}
	pressEnter();
	{
		titleHeader("PRESIDENTIAL PARDON TEST");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *thePresident = new Bureaucrat("President", 1);
		Bureaucrat *theVicePresident = new Bureaucrat("Vice President", 25);
		AForm *theForm = new PresidentialPardonForm("Vice President's Son");

		debugMessageStatus(WITH_NEWLINE);
		std::cout << thePresident << theVicePresident << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			thePresident->executeForm(*theForm);
			std::cout << "\t" << thePresident->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(AForm::FormNotSignedException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(thePresident->getName() + " can't execute ", theForm->getName());
		}
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theVicePresident);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theVicePresident->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;
		try
		{
			debugMessageAction("try to execute the form");
			theVicePresident->executeForm(*theForm);
			std::cout << "\t" << theVicePresident->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(theVicePresident->getName() + " can't execute ", theForm->getName());
		}
		try
		{
			debugMessageAction("try to execute the form");
			thePresident->executeForm(*theForm);
			std::cout << "\t" << thePresident->getName() << " executed " << theForm->getName() << std::endl;
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("permission denied: ", e.what());
			exceptionError(thePresident->getName() + " can't execute ", theForm->getName());
		}
		debugMessageDestructors(WITH_NEWLINE);
		delete thePresident;
		delete theVicePresident;
		delete theForm;
	}
	pressEnter();
}