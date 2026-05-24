/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/24 14:00:24 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/24 14:02:56 by brmaria-         ###   ########.fr       */
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
		virtual ~Brain(void);
		
		Brain &operator=(Brain const &copy);
		
		void	showIdeas(void) const;
};

#endif