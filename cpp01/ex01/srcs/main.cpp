/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 16:53:19 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/10 17:45:32 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie* Horde = zombieHorde(10, "Bruninha");
	for(int i = 0; i < 10; i++)
	{
		Horde[i].Announce(); 
	}
	delete[] Horde;
}