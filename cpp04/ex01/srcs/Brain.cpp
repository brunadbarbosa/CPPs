/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:03:41 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/24 14:24:19 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain's Default constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain's Copy assigment constructor called" << std::endl;
	*this = copy; 
}

Brain::~Brain(void) {
	std::cout << "Brain's Destructor called" << std::endl;
}

Brain& Brain::operator=(Brain const &copy) {
	std::cout << "Brain's assignation operator called" << std::endl;
	if (this == &copy)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

void	Brain::showIdeas(void) const {
	std::cout << "Brain's sound..." << std::endl;
}