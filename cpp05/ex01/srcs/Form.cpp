/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/19 16:09:23 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/19 17:18:49 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "create Form default" << std::endl;
}

Form::Form(Form const &other) : _name(other.getName()), _isSigned(false), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade()) {
	std::cout << "create Form copy of " << other.getName() << std::endl;
	*this = other;
}

Form::Form(int signGrade, int executeGrade) : _name("default"), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "create Form default with sign-grade" << signGrade << " and execution grade " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

Form::Form(std::string const &name) : _name(name), _isSigned(false), _signGrade(150), _executeGrade(150) {
	std::cout << "create Form " << this->_name << std::endl;
}

Form::Form(std::string const &name, int signGrade, int executeGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade) {
	std::cout << "create Form " << this->_name << " with sign-grade " << signGrade << " and execution-grade " << executeGrade << std::endl;
	this->_checkGrades(signGrade, executeGrade);
}

Form::~Form() {
	std::cout << "destroy Form " << this->_name << std::endl;
}

Form &Form::operator=(Form const &other) {
	std::cout << "start assignation Form to other" << std::endl;
	if (this == &other)
		return (*this);
	return (*this);
}

std::string const Form::getName() const {
	return (this->_name);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

int Form::getSignGrade() const {
	return (this->_signGrade);
}

int Form::getExecuteGrade() const {
	return (this->_executeGrade);
}

void Form::_checkGrades(int signGrade, int executeGrade) {
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	else if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if ((int)bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooHighException();
	else if(!this->_isSigned) {
		std::cout << "\t" << bureaucrat.getName() << " signed " << this->getName() << std::endl;
		this->_isSigned = true;
	}
	else
		std::cout << "\t" << bureaucrat.getName() << " couldn't sign " << this->getName() << " because it's already signed" << std::endl;
}

const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Form *form) {
	std::string isSigned = form->getIsSigned() ? "is signed" : "isn't signed";
	out << form->getName() << " Form " << isSigned;
	out << ", Sign-grade: " << form->getSignGrade();
	out << ", execution-grade: " << form->getExecuteGrade();
	out << std::endl;
	return (out);
}
