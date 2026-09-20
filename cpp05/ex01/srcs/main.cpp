#include "Bureaucrat.hpp"
#include "Form.hpp"

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

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theDefault = new Bureaucrat();
		Form *theForm = new Form();

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theDefault;
		std::cout << theForm;
		try
		{
			debugMessageAction("try to sign the form");
			theForm->beSigned(*theDefault);
		}
		catch(Form::GradeTooHighException &e)
		{
			exceptionError("Permission denied: ", e.what());
			exceptionError(theDefault->getName() + " can't sign ", theForm->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theForm;

		debugMessageDestructors(WITH_NEWLINE);
		delete theForm;
		delete theDefault;
	}
	pressEnter();
	{
		titleHeader("TEST GRADE LEVEL");

		debugMessageConstructors(WITH_NEWLINE);
		Bureaucrat *theAssistent = new Bureaucrat("Assistent", 100);
		Bureaucrat *theBoss = new Bureaucrat("Boss", 1);
		Form *theContract = new Form("Contract", 99, 99);

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theAssistent << theBoss << theContract;

		try
		{
			debugMessageAction("try to sign the form");
			theContract->beSigned(*theAssistent);
			theAssistent->signForm(*theContract);
		}
		catch(Form::GradeTooHighException &e)
		{
			exceptionError("Permission denied: ", e.what());
			exceptionError(theAssistent->getName() + " can't sign ", theContract->getName());
		}
		try
		{
			debugMessageAction("try to sign the form");
			theBoss->signForm(*theContract);
			// theContract->beSigned(*theBoss);
		}
		catch(Form::GradeTooLowException &e)
		{
			exceptionError("Permission denied: ", e.what());
			exceptionError(theBoss->getName() + " can't sign ", theContract->getName());
		}
		debugMessageStatus(WITH_NEWLINE);
		std::cout << theContract;
		try
		{
			debugMessageAction("try to sign the form");
			theBoss->signForm(*theContract);
			// theContract->beSigned(*theBoss);
		}
		catch(Form::GradeTooLowException &e)
		{
			exceptionError("Permission denied: ", e.what());
			exceptionError(theBoss->getName() + " can't sign ", theContract->getName());
		}

		debugMessageDestructors(WITH_NEWLINE);
		delete theAssistent;
		delete theBoss;
		delete theContract;
	}
	pressEnter();
	{
		titleHeader("TEST INVALID GRADE");
		Form *theHighest = NULL;
		Form *theLowest = NULL;
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theHighest = new Form("Highest", 0, 1);
		}
		catch(Form::GradeTooHighException &e)
		{
			exceptionError("Invalid grade: ", e.what());
		}
		try
		{
			debugMessageConstructors(WITHOUT_NEWLINE);
			theLowest = new Form("Lowest", 1, 151);
		}
		catch(Form::GradeTooLowException &e)
		{
			exceptionError("Invalid grade: ", e.what());
		}
		if (theHighest)
		{
			debugMessageStatus(WITHOUT_NEWLINE);
			std::cout << theHighest;
			debugMessageDestructors(WITHOUT_NEWLINE);
			delete theHighest;
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

		debugMessageConstructors(WITH_NEWLINE);
		Form *theOriginal = new Form("Xerox", 100, 110);

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theOriginal;

		debugMessageConstructors(WITH_NEWLINE);
		Form *theCopy = new Form(*theOriginal);

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theOriginal;

		debugMessageStatus(WITH_NEWLINE);
		std::cout << theCopy;

		debugMessageDestructors(WITHOUT_NEWLINE);
		delete theCopy;

	}
	pressEnter();
}