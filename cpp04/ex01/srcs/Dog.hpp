/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:09:04 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:25:34 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
	private:
		Brain *_brain;
	public:
		Dog(void);
		Dog(Dog const &copy);

		Dog &operator=(Dog const &copy);
		
		virtual ~Dog(void);
		void makeSound() const;
		Brain *getBrain(void) const;
};

#endif
