/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 14:15:44 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/09 19:36:58 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>


class Contact {
	
	public:
		Contact(void);
		~Contact(void);
		
		bool	IsEmpty(void) const;
		bool	SetContact(void);
		void	DisplayContact(void) const;

		std::string GetFirstName(void)const;
		std::string GetLastName(void)const;
		std::string GetNickname(void)const;
		
		static std::string FormatWidth(std::string Field);
	
	private: 
		std::string _FirstName;
		std::string _LastName;
		std::string _Nickname;
		std::string _PhoneNumber;
		std::string _Secret;
		std::string GetValidInput(std::string Prompt);
};

#endif