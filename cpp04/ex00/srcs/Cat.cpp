/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:30:39 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 20:40:24 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Cat's Default constructor called" << std::endl;
}

Cat::Cat(Cat const &copy) {
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
	this->type = copy.getType();
	return (*this);
}

void	Cat::makeSound() {
	std::cout << "Meoooooowwwwww" << std::endl;
}