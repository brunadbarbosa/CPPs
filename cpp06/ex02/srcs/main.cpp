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
#include <cstdlib>
#include <ctime>
#include "identify.hpp"

class Unknown : public Base {};

int main(void) {
	std::srand(std::time(NULL));
	std::rand(); /* the first value barely changes between close seeds */

	for (int i = 0; i < 5; i++) {
		Base *p = generate();

		std::cout << "identify(Base *): ";
		identify(p);
		std::cout << "identify(Base &): ";
		identify(*p);
		std::cout << std::endl;
		delete p;
	}

	Unknown unknown;
	std::cout << "Base that is not A, B or C:" << std::endl;
	identify(&unknown);
	identify(unknown);

	std::cout << "NULL pointer: ";
	identify(static_cast<Base *>(NULL));
	return (0);
}
