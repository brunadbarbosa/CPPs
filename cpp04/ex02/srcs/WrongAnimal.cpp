/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:00:40 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/24 13:14:32 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal's Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy) {
	std::cout << "WrongAnimal's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal's Destructor called" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}
void WrongAnimal::setType(std::string const type) {
	this->type = type;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const &copy) {
	std::cout << "WrongAnimal's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

void	WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal's sound..." << std::endl;
}