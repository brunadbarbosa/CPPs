/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:04:06 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:25:19 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal();
		Animal(Animal const &copy);
		virtual ~Animal();

		Animal &operator=(Animal const &copy);

		std::string getType(void) const;
		void setType(std::string const type);
		
		virtual void makeSound(void) const;
};

#endif
