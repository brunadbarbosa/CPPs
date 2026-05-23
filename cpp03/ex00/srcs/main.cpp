/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 12:06:57 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 14:18:23 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
    ClapTrap bot("R2D2");

    std::cout << "First Cenario" << std::endl << std::endl;
    bot.attack("target");
    bot.beRepaired(5);
    bot.attack("target");

    std::cout << "Second Cenario" << std::endl << std::endl;
    for (int i = 0; i < 10; i++)
        bot.attack("target");
    bot.attack("target");

    std::cout << "Third Cenario" << std::endl << std::endl;
    ClapTrap bot2("BB8");
    bot2.takeDamage(20);
    bot2.attack("target");
    bot2.beRepaired(5);

    return 0;
}