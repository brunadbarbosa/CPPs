/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 13:42:35 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/10 17:19:23 by brmaria-         ###   ########.fr       */
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
		Zombie();
		~Zombie(void);
		void	Announce(void);
		void	setName(std::string Name);
};

Zombie* zombieHorde( int N, std::string name );

#endif