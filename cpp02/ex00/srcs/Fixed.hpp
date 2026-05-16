/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 20:02:23 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 20:15:38 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_RawBits;
	static const int	_FractionalBits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &Other);
	Fixed	&operator = (const Fixed &Other);
	int getRawBits( void ) const;
	void setRawBits( int const raw );
};

#endif