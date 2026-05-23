/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:09:09 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/17 13:52:22 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_RawBits;
		static const int	_FractionalBits;
	public:
		Fixed();
		~Fixed();
		Fixed(const int Number);
		Fixed(const float Float);
		Fixed(const Fixed &Other);
		Fixed	&operator = (const Fixed &Other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed);

#endif