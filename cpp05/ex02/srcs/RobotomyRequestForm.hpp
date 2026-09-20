/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 15:31:22 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/20 15:31:46 by brmaria-         ###   ########.fr       */
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

class RobotomyRequestForm : public AForm {
	private:
		std::string const _target;

		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string const &target);
		RobotomyRequestForm(RobotomyRequestForm const &other);
		~RobotomyRequestForm();
		
		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		std::string getTarget() const;
		
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, RobotomyRequestForm *src);