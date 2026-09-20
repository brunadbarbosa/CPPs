/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:32:17 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/20 15:32:35 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string const _target;

		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &other);
		~ShrubberyCreationForm();
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);

		std::string getTarget() const;
		
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, ShrubberyCreationForm *src);