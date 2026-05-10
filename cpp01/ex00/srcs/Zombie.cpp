/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:32:28 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/10 16:23:04 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string newName) : _Name(newName) {
	std::cout << _Name << " was created." << std::endl;
}

Zombie::~Zombie(void){
	std::cout << _Name << " was destroyed." << std::endl;
}

void	Zombie::Announce(void){
	std::cout << _Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}