/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:37:09 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 14:18:45 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() : _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string Name) : _Name(Name), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "Parameterised constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy) : _Name(copy._Name), _HitPoints(copy._HitPoints), _EnergyPoints(copy._EnergyPoints), _AttackDamage(copy._AttackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const &copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	_Name = copy._Name;
	_HitPoints = copy._HitPoints;
	_EnergyPoints = copy._EnergyPoints;
	_AttackDamage = copy._AttackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (!_HitPoints)
		std::cout << "Not enough Hit Points" << std::endl;
	else if (!_EnergyPoints)
			std::cout << "Not enough Energy Points" << std::endl;
	else
	{
		_EnergyPoints--;
		std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _AttackDamage << " of damage!" << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	std::cout << "Lost " << amount << " points of HitPoints" << std::endl;
	if (amount >= _HitPoints)
	{
		_HitPoints = 0;	
		std::cout << _Name << " has been destroyed!" << std::endl;	
	}
	else
	{
		_HitPoints -= amount;
		std::cout << _Name << " took " << amount << " damage!" << std::endl;
	}
}
void ClapTrap::beRepaired(unsigned int amount) {
	if (!_HitPoints)
		std::cout << "Not enough Hit Points" << std::endl;
	else if (!_EnergyPoints)
		std::cout << "Not enough Energy Points" << std::endl;
	else
	{
		_HitPoints += amount;
    	_EnergyPoints --;
		std::cout << "Got " << amount << " points of HitPoints, but it cost 1 EnergyPoint" << std::endl;
	}
}