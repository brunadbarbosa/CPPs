/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/17 13:18:07 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/17 16:09:23 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FractionalBits = 8;

Fixed::Fixed() {
	_RawBits = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int Number) {
	_RawBits = Number * 256;
}

Fixed::Fixed(const float Float) {
	_RawBits = roundf(Float * 256);
}

int Fixed::getRawBits( void ) const {
	return _RawBits;
}

void Fixed::setRawBits( int const raw ) {
	_RawBits = raw;
}

Fixed::Fixed(const Fixed &Other) {
	_RawBits = Other._RawBits;
}

Fixed &Fixed::operator=(const Fixed &Other)  {
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

bool Fixed::operator>(const Fixed &Other) const {
	return _RawBits > Other._RawBits;
}
	
bool Fixed::operator<(const Fixed &Other) const {
	return _RawBits < Other._RawBits;
}

bool Fixed::operator>=(const Fixed &Other) const {
	return _RawBits >= Other._RawBits;
}

bool Fixed::operator<=(const Fixed &Other) const {
	return _RawBits <= Other._RawBits;
}

bool Fixed::operator==(const Fixed &Other) const {
	return _RawBits == Other._RawBits;
}

bool Fixed::operator!=(const Fixed &Other) const {
	return _RawBits != Other._RawBits;
}

Fixed Fixed::operator+(const Fixed &Other) const {
	return Fixed(toFloat() + Other.toFloat());
}

Fixed Fixed::operator-(const Fixed &Other) const {
	return Fixed(toFloat() - Other.toFloat());
}

Fixed Fixed::operator*(const Fixed &Other) const {
	return Fixed(toFloat() * Other.toFloat());
}

Fixed Fixed::operator/(const Fixed &Other) const {
	return Fixed(toFloat() / Other.toFloat());
}

Fixed &Fixed::operator++(void) {
	_RawBits++;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed	Temp(*this);
	_RawBits++;
	return Temp;
}

Fixed &Fixed::operator--(void) {
	_RawBits--;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed	Temp(*this);
	_RawBits--;
	return Temp;
}

Fixed	&Fixed::min(Fixed &Other, Fixed &Other2) {
	if (Other < Other2)
		return Other;
	return Other2;
}

const Fixed	&Fixed::min(const Fixed &Other, const Fixed &Other2) {
	if (Other < Other2)
		return Other;
	return Other2;
}

Fixed	&Fixed::max(Fixed &Other, Fixed &Other2) {
	if (Other > Other2)
		return Other;
	return Other2;
}

const Fixed	&Fixed::max(const Fixed &Other, const Fixed &Other2) {
	if (Other > Other2)
		return Other;
	return Other2;
}