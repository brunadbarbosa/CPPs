/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 18:13:20 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/09 19:58:41 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	_OldestIndex = 0;
	_Count = 0;	
}

PhoneBook::~PhoneBook(void){}

void	PhoneBook::AddContact(void)
{
	_Contacts[_OldestIndex].SetContact();
	if (_Count < 8)
		_Count++;
	_OldestIndex = (_OldestIndex + 1) % 8;
}

void	PhoneBook::DisplayContacts(void)
{
	std::cout << "|    Index|First Name| Last Name|  Nickname|" << std::endl;
	for (int i = 0; i < _Count; i++)
	{
		if (_Contacts[i].IsEmpty())
			continue ;
		std::cout << "|---------|----------|----------|----------|" << std::endl;
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right << Contact::FormatWidth(_Contacts[i].GetFirstName()) << "|";
		std::cout << std::setw(10) << std::right << Contact::FormatWidth(_Contacts[i].GetLastName()) << "|";
		std::cout << std::setw(10) << std::right << Contact::FormatWidth(_Contacts[i].GetNickname()) << "|" << std::endl;
	}
	std::cout << std::endl;
}

void	PhoneBook::SearchContact(void)
{
	int	Index;
	std::string	Input;
	DisplayContacts();
	while(1)
	{
		std::cout << "Choose the contact to display full info or BACK if you want to go back: ";
		std::cin >> Input;
		std::cin.ignore();
		Index = std::atoi(Input.c_str());
		if (Input == "BACK")
			break ;
		if (Index >= 0 && Index < _Count)
			_Contacts[Index].DisplayContact();
		else
		{
			std::cout << "Please insert a valid Contact." << std::endl;
			continue ;
		}
	}
}