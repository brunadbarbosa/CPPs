/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 14:23:53 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 16:21:45 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string Name);
		ScavTrap(ScavTrap const &copy);

		ScavTrap& operator=(ScavTrap const &copy);
		
		~ScavTrap();
		
		void attack(const std::string& target);
		void guardGate();
};

#endif