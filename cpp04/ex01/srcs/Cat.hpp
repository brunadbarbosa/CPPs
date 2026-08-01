/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 20:11:14 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/30 11:25:29 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat const &copy);

		Cat &operator=(Cat const &copy);
		
		virtual ~Cat(void);
		void makeSound(void) const;
		Brain *getBrain(void) const;
};

#endif
