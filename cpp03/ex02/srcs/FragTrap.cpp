/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:39:21 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 17:26:04 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Name) : ClapTrap(Name) {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "FragTrap " << _Name << " constructed!" << std::endl;
}

FragTrap::FragTrap(FragTrap const &copy) : ClapTrap(copy) {
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(FragTrap const &copy) {
	ClapTrap::operator=(copy);
	std::cout << "FragTrap copy assignment called" << std::endl;
	return *this;
}
	
FragTrap::~FragTrap() {
	std::cout << "FragTrap " << _Name << " destructed!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap is asking for an amazing highfive!" << std::endl;
}
