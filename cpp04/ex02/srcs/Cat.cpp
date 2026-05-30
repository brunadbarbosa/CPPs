/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- < brmaria-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:30:39 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/29 17:31:04 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat's Default constructor called" << std::endl;
	this->type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout << "Cat's Copy assigment constructor called" << std::endl;
	this->_brain = nullptr;
	*this = copy; 
}

Cat::~Cat(void) {
	std::cout << "Cat's Destructor called" << std::endl;
	delete this->_brain;
}

Cat& Cat::operator=(Cat const &copy) {
	std::cout << "Cat's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->type = copy.getType();
    delete this->_brain;
    this->_brain = new Brain(*copy._brain);
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meoooooowwwwww" << std::endl;
}

Brain	*Cat::getBrain(void) const {return (this->_brain);}
