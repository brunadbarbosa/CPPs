/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:07:08 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:26:34 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal's Default constructor called" << std::endl;
}

Animal::Animal(Animal const &copy) {
	std::cout << "Animal's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

Animal::~Animal(void) {
	std::cout << "Animal's Destructor called" << std::endl;
}

std::string Animal::getType(void) const {
	return this->type;
}
void Animal::setType(std::string const type) {
	this->type = type;
}

Animal& Animal::operator=(Animal const &copy) {
	std::cout << "Animal's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

void	Animal::makeSound(void) const {
	std::cout << "Animal's sound..." << std::endl;
}
