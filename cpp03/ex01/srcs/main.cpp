/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:06:57 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 16:25:17 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap bot("R2D2");
    std::cout << "\n--- First Scenario ---\n" << std::endl;
    bot.attack("target");
    bot.beRepaired(5);
    bot.attack("target");

    std::cout << "\n--- Second Scenario ---\n" << std::endl;
    for (int i = 0; i < 10; i++)
        bot.attack("target");
    bot.attack("target");

    std::cout << "\n--- Third Scenario ---\n" << std::endl;
    ClapTrap bot2("BB8");
    bot2.takeDamage(20);
    bot2.attack("target");
    bot2.beRepaired(5);

    std::cout << "\n--- ScavTrap Scenario ---\n" << std::endl;
    {
        ScavTrap scav("Wall-E");
        scav.guardGate();
        scav.attack("target");
        scav.takeDamage(50);
        scav.beRepaired(20);
    }
    std::cout << "\n--- ScavTrap out of scope ---\n" << std::endl;

    return 0;
}