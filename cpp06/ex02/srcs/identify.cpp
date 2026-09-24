/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	/* uses the high bits of rand(): "rand() % 3" is not random enough on macOS */
	switch (std::rand() / (RAND_MAX / 3 + 1)) {
		case 0:
			std::cout << "generate: A" << std::endl;
			return (new A());
		case 1:
			std::cout << "generate: B" << std::endl;
			return (new B());
		default:
			std::cout << "generate: C" << std::endl;
			return (new C());
	}
}

/* dynamic_cast on a pointer returns NULL when the real type does not match */
void identify(Base *p) {
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

/* dynamic_cast on a reference cannot return NULL, so it throws instead    */
/* (std::bad_cast lives in <typeinfo>, which is forbidden -> catch (...)) */
void identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (...) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (...) {}
	std::cout << "Unknown type" << std::endl;
}
