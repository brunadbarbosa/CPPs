/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:42:35 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/10 16:36:38 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class	Zombie {
	private:
		std::string _Name;
	public:
		Zombie(std::string Name);
		~Zombie(void);
		void	Announce(void);
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);
#endif