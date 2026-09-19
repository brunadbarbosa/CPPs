/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:33:05 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/19 14:52:50 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "create Bureaucrat default" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const &name) : _name(name), _grade(150) {
	std::cout << "create Bureaucrat " << this->_name << std::endl;	
}

Bureaucrat::Bureaucrat(int grade) : _name("default") {
	std::cout << "create Bureaucrat default with grade " << grade << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	std::cout << "create Bureaucrat " << this->_name << " with grade " << grade << std::endl;
	this->_setGrade(grade);
}

Bureaucrat::Bureaucrat(Bureaucrat const &other) : _name(other._name) {
	std::cout << "create Bureaucrat copy of " << other.getName() << std::endl;
	*this = other;	
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
	std::cout << "create Bureaucrat copy of " << other.getName() << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {
	std::cout << "destroying Bureaucrat " << this->_name << std::endl;
}

std::string const Bureaucrat::getName() const {
	return (this->_name);
}

size_t Bureaucrat::getGrade() const {
	return (this->_grade);
}

void	Bureaucrat::_setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

void	Bureaucrat::incrementGrade() {
	this->_setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade() {
	this->_setGrade(this->_grade + 1);
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}

std::ostream &operator<<(std::ostream &out, Bureaucrat *other) {
	out << other->getName() << ", bureaucrat grade " << other->getGrade() << std::endl;
	return (out);
}
