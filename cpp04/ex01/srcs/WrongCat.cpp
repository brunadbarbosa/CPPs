/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 13:00:45 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/24 13:39:47 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat's Default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &copy) :WrongAnimal(copy) {
	std::cout << "WrongCat's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat's Destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const &copy) {
	std::cout << "WrongCat's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	return (*this);
}

void	WrongCat::makeSound() const {
	std::cout << "Meoooooowwwwww" << std::endl;
}