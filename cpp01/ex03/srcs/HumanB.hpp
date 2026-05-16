/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 12:00:09 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 12:04:18 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
private:
	Weapon*			_Weapon;
	std::string		_Name;
public:
	HumanB(std::string Name);
	~HumanB();
	void		attack(void);
	void		setWeapon(Weapon& W);
};

#endif