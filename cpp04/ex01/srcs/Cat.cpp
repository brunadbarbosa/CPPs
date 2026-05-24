/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:30:39 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/24 13:39:39 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat's Default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const &copy) : Animal(copy) {
	std::cout << "Cat's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

Cat::~Cat(void) {
	std::cout << "Cat's Destructor called" << std::endl;
}

Cat& Cat::operator=(Cat const &copy) {
	std::cout << "Cat's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

void	Cat::makeSound() const {
	std::cout << "Meoooooowwwwww" << std::endl;
}