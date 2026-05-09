/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 16:38:45 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/09 18:18:28 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"


class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	AddContact(void);
		void	DisplayContacts(void);
		void	SearchContact(void);
	private:
		Contact	_Contacts[8];
		int	_OldestIndex;
		int	_Count;
};

#endif