/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 11:09:47 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 11:29:28 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string Type) : _Type(Type) {
	
}

Weapon::~Weapon() {}

const std::string& Weapon::getType() {
	return _Type;
}

void Weapon::setType(std::string Type) {
	_Type = Type;
}