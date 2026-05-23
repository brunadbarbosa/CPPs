/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 16:31:27 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/23 16:44:44 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public: 
		FragTrap();
		FragTrap(std::string Name);
		FragTrap(FragTrap const &copy);

		FragTrap& operator=(FragTrap const &copy);
		
		~FragTrap();
		void highFivesGuys(void);
};

#endif