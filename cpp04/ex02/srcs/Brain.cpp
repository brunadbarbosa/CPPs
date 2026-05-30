/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- < brmaria-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:03:41 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/29 17:25:23 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain's Default constructor called" << std::endl;
}

Brain::Brain(Brain const &copy) {
	std::cout << "Brain's Copy constructor called" << std::endl;
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

void Brain::setIdea(int index, std::string const &idea) {
    if (index >= 0 && index < 100)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if (index >= 0 && index < 100)
        return ideas[index];
    return "";
}
