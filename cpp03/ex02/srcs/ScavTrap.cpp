/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:32:09 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 16:23:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string Name) : ClapTrap(Name) {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "ScavTrap " << _Name << " constructed!" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy) : ClapTrap(copy) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &copy) {
	ClapTrap::operator=(copy);
	std::cout << "ScavTrap copy assignment called" << std::endl;
	return *this;
}
	
ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _Name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
		if (!_HitPoints)
		std::cout << "Not enough Hit Points" << std::endl;
	else if (!_EnergyPoints)
			std::cout << "Not enough Energy Points" << std::endl;
	else
	{
		_EnergyPoints--;
		std::cout << "ScavTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " of damage!" << std::endl;
	}
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _Name << " is now in Gate keeper mode!" << std::endl;
}