/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:31:03 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:34:20 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog's Default constructor called" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy) : Animal(copy) {
	std::cout << "Dog's Copy assigment constructor called" << std::endl;
	this->_brain = NULL;
	*this = copy;
}

Dog::~Dog(void) {
	std::cout << "Dog's Destructor called" << std::endl;
	delete this->_brain;
}

Dog& Dog::operator=(Dog const &copy) {
	std::cout << "Dog's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	delete this->_brain;
    this->_brain = new Brain(*copy._brain);
	return (*this);
}

void	Dog::makeSound() const{
	std::cout << "Woof woof!!" << std::endl;
}

Brain	*Dog::getBrain(void) const {return (this->_brain);
}
