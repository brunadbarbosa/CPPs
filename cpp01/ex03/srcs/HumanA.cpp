/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:50:15 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 14:46:53 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string Name, Weapon& W) : _Weapon(W), _Name(Name) {}

HumanA::~HumanA() {}

void	HumanA::attack() {
	std::cout << _Name << " attacks with their " << _Weapon.getType()  << std::endl;
}