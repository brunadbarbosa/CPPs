/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:03:57 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/09 19:24:41 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

std::string Contact::GetFirstName(void) const
{
	return _FirstName;
}

std::string Contact::GetLastName(void) const
{
	return _LastName;
}

std::string Contact::GetNickname(void) const
{
	return _Nickname;
}

bool Contact::IsEmpty(void) const
{
	return _FirstName.empty();
}

std::string	Contact::GetValidInput(std::string Prompt)
{
	std::string Input;
	do 
	{
		std::cout << Prompt;
		std::getline(std::cin, Input);
		if (Input.empty())
			std::cout << "Field cannot be empty." << std::endl;
	}while (Input.empty());
	return Input;
}

bool Contact::SetContact(void)
{
	_FirstName = GetValidInput("First Name: ");
	_LastName = GetValidInput("Last Name: ");
	_Nickname = GetValidInput("Nickname: ");
	_PhoneNumber = GetValidInput("Phone Number: ");
	_Secret = GetValidInput("Darkest Secret: ");
	return true;
}

std::string Contact::FormatWidth(std::string Field)
{
	if (Field.length() > 10)
		return Field.substr(0, 9) + ".";
	return Field;
}

void Contact::DisplayContact(void) const
{
	std::cout << "**********************************" << std::endl;
	std::cout << "*          CONTACT VIEWER        *" << std::endl;
	std::cout << "**********************************" << std::endl << std::endl;
	std::cout << "First Name: " << _FirstName << std::endl;
	std::cout << "Last Name: " << _LastName << std::endl;
	std::cout << "Nickname: " << _Nickname << std::endl;
	std::cout << "Phone Number: " << _PhoneNumber << std::endl;
	std::cout << "Secret: " << _Secret << std::endl;
}