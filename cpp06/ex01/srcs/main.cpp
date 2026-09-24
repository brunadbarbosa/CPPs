/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main(void) {
	Data data;

	data.id = 42;
	data.name = "brmaria-";
	data.value = 4.2;

	uintptr_t raw = Serializer::serialize(&data);
	Data *ptr = Serializer::deserialize(raw);

	std::cout << "original address:     " << &data << std::endl;
	std::cout << "serialized (integer): " << raw << std::endl;
	std::cout << "deserialized address: " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "OK: deserialize(serialize(&data)) == &data" << std::endl;
	else
		std::cout << "KO: pointers are different" << std::endl;

	std::cout << "ptr->id:    " << ptr->id << std::endl;
	std::cout << "ptr->name:  " << ptr->name << std::endl;
	std::cout << "ptr->value: " << ptr->value << std::endl;

	Data *nullData = Serializer::deserialize(Serializer::serialize(NULL));
	std::cout << "NULL round trip: " << (nullData == NULL ? "OK" : "KO") << std::endl;
	return (0);
}
