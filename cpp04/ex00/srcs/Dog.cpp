/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:31:03 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 20:41:42 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Dog's Default constructor called" << std::endl;
}

Dog::Dog(Dog const &copy) {
	std::cout << "Dog's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

Dog::~Dog(void) {
	std::cout << "Dog's Destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const &copy) {
	std::cout << "Dog's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
	return (*this);
}

void	Dog::makeSound() {
	std::cout << "AU AU" << std::endl;
}