/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 17:37:25 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/20 17:38:42 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
	std::cout << "create Intern" << std::endl;
}

Intern::Intern(Intern const &other)
{
	std::cout << "create Intern copy" << std::endl;
	*this = other;
}

Intern::~Intern()
{
	std::cout << "destroy Intern" << std::endl;
}

Intern &Intern::operator=(Intern const &other)
{
	std::cout << "start assignation Intern to other" << std::endl;
	if (this == &other)
		return(*this);
	return(*this);
}

static AForm *makePresidential(std::string const &target){return (new PresidentialPardonForm(target));}
static AForm *makeRobotomy(std::string const &target){return (new RobotomyRequestForm(target));}
static AForm *makeShrubbery(std::string const &target){return (new ShrubberyCreationForm(target));}

AForm *Intern::makeForm(std::string const &form, std::string const &target)
{
	AForm *(*formGenerator[])(std::string const &target) = {&makePresidential, &makeRobotomy, &makeShrubbery};
	std::string const formNames[] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	for (int i = 0; i < 3; i++)
	{
		if (form == formNames[i])
		{
			AForm *generatedForm = formGenerator[i](target);
			std::cout << "Intern creates " << form << std::endl;
			return (generatedForm);
		}
	}
	std::cout << "\t" << "Intern can't make " << form << std::endl;
	return (NULL);
}
