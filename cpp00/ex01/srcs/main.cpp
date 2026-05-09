/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 13:43:11 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/09 19:10:53 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	main_header(void)
{
	std::cout << "**********************************" << std::endl;
	std::cout << "*          PHONEBOOK APP         *" << std::endl;
	std::cout << "**********************************" << std::endl << std::endl;
	std::cout << "Available commands:" << std::endl;
	std::cout << "- ADD" << std::endl;
	std::cout << "- SEARCH" << std::endl;
	std::cout << "- EXIT" << std::endl << std::endl;
}

int	main(void)
{
	PhoneBook 	Phonebook;
	std::string	Input;
	bool		InvalidCommand = false;
	
	while(1)
	{
		if (!InvalidCommand)
			main_header();
		std::cout << "Enter a command: ";
		std::getline(std::cin, Input);
		if (Input == "ADD")
		{
			Phonebook.AddContact();
			InvalidCommand = false;
		}
		else if (Input == "SEARCH")
		{
			Phonebook.SearchContact();
			InvalidCommand = false;
		}
		else if (Input == "EXIT")
			break ;
		else
		{
			std::cout << "Enter a valid command line." << std::endl;
			InvalidCommand = true;
		}
	}
}