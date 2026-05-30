/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- < brmaria-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:00:24 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/29 17:25:34 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	public:
		Brain(void);
		Brain(Brain const &copy);
		~Brain(void);
		
		Brain &operator=(Brain const &copy);
		
		void setIdea(int index, std::string const &idea);
		std::string getIdea(int index) const;
};

#endif