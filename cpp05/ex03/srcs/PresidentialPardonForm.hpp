/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/20 13:47:29 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/20 14:07:32 by brmaria-         ###   ########.fr       */
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

class PresidentialPardonForm : public AForm {
	private:
		std::string const _target;

		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string const &target);
		PresidentialPardonForm(PresidentialPardonForm const &other);
		~PresidentialPardonForm();
		
		PresidentialPardonForm &operator=(PresidentialPardonForm const &other);

		std::string getTarget() const;
		
		virtual void execute(Bureaucrat const &bureaucrat) const;
};

std::ostream &operator<<(std::ostream &out, PresidentialPardonForm *src);
