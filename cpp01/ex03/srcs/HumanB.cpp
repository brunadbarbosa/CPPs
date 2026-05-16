/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:05:44 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 14:47:07 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string Name) : _Weapon(NULL), _Name(Name) {}

HumanB::~HumanB() {}

void	HumanB::attack() {
	if (_Weapon == NULL)
		std::cout << _Name << " has no weapon." << std::endl;
	else
		std::cout << _Name << " attacks with their " << _Weapon->getType()  << std::endl;
}

void	HumanB::setWeapon(Weapon& W) {
	_Weapon = &W;
}