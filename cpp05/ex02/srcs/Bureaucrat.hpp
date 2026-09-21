/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:33:02 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/21 12:55:52 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		std::string const	_name;
		size_t				_grade;
		void	_setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name);
		Bureaucrat(int grade);
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat();
		
		Bureaucrat &operator=(Bureaucrat const &other);

		std::string const getName() const;
		size_t getGrade() const;
		void signForm(AForm &form);
		void executeForm(AForm const &form) const;

		void	incrementGrade();
		void	decrementGrade();
		
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};
