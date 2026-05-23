/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:18:07 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/17 13:44:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FractionalBits = 8;

Fixed::Fixed() {
	_RawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int Number) {
	_RawBits = Number * 256;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float Float) {
	_RawBits = roundf(Float * 256);
	std::cout << "Float constructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return _RawBits;
}

void Fixed::setRawBits( int const raw ) {
	std::cout << "setRawBits member function called" << std::endl;
	_RawBits = raw;
}

Fixed::Fixed(const Fixed &Other) {
	std::cout << "Copy constructor called" << std::endl;
	_RawBits = Other._RawBits;
}

Fixed &Fixed::operator=(const Fixed &Other)  {
	std::cout << "Copy assignment operator called" << std::endl;
	_RawBits = Other._RawBits;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &Fixed) {
	out << Fixed.toFloat();
	return out;
}

float Fixed::toFloat( void ) const {
	return _RawBits / 256.0f;
}

int Fixed::toInt( void ) const {
	return _RawBits / 256;
}