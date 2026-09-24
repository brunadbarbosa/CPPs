/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* Not instantiable: everything in the Orthodox Canonical Form is private */

Serializer::Serializer() {}

Serializer::Serializer(Serializer const &other) {
	(void)other;
}

Serializer &Serializer::operator=(Serializer const &other) {
	(void)other;
	return (*this);
}

Serializer::~Serializer() {}

/* reinterpret_cast: the bits of the address are reinterpreted as an     */
/* integer (and back). No real conversion happens, so the value is kept. */

uintptr_t Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}
