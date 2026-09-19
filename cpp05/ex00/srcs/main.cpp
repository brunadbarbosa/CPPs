/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:32:59 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/19 14:53:10 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		titleHeader("BASIC TEST");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *theDefault = new Bureaucrat();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to increment grade");
			theDefault->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to decrement grade");
			theDefault->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;
		try
		{
			debugMessageAction("try to decrement grade");
			theDefault->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theDefault;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theDefault;
	}
	pressEnter();
	{
		titleHeader("CALL WITH VALID NUMBER");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *validNumber = new Bureaucrat(1);

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to decrement grade");
			validNumber->decrementGrade();
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to increment grade");
			validNumber->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;
		try
		{
			debugMessageAction("try to increment grade");
			validNumber->incrementGrade();
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << validNumber;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete validNumber;
	}
	pressEnter();
	{
		titleHeader("CALL WITH HIGH INVALID NUMBERS");

		Bureaucrat *theHighest = NULL;
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theHighest = new Bureaucrat(0);
		}
		catch(Bureaucrat::GradeTooHighException &e)
		{
			exceptionError("Error: ", e.what());
		}
		if (theHighest)
		{
			debugMessageStatus(WITHOUT_NEWLINE);
			std::cout << theHighest;
			debugMessageDestructors(WITHOUT_NEWLINE);
			delete theHighest;
		}
	}
	pressEnter();
	{
		titleHeader("CALL WITH LOW INVALID NUMBERS");
		Bureaucrat *theLowest = NULL;
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theLowest = new Bureaucrat(151);
		}
		catch(Bureaucrat::GradeTooLowException &e)
		{
			exceptionError("Error: ", e.what());
		}
		if (theLowest)
		{
			debugMessageStatus(WITHOUT_NEWLINE);
			std::cout << theLowest;
			debugMessageDestructors(WITHOUT_NEWLINE);
			delete theLowest;
		}
	}
	pressEnter();
	{
		titleHeader("DEEP COPY TESTS");

		debugMessageConstructors(WITHOUT_NEWLINE);
		Bureaucrat *theOriginal = new Bureaucrat("First Class", 111);

		debugMessageAction("try to increment grade");
		theOriginal->incrementGrade();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theOriginal;

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theCopy = new Bureaucrat(*theOriginal);

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theOriginal;

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theCopy;

		debugMessageAction("try to decrement grade");
		theCopy->decrementGrade();

		debugMessageStatus(WITHOUT_NEWLINE);
		std::cout << theCopy;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theCopy;
	}
	pressEnter();
}