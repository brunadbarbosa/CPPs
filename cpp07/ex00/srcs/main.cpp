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
#include <string>
#include "whatever.hpp"

int main(void) {
	int a = 2;
	int b = 3;

	::swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
	std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
	std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;

	/* equal values: the second one must be returned */
	int x = 42;
	int y = 42;
	std::cout << std::endl << "equal values:" << std::endl;
	std::cout << "&min(x, y) == &y: " << (&::min(x, y) == &y ? "OK" : "KO") << std::endl;
	std::cout << "&max(x, y) == &y: " << (&::max(x, y) == &y ? "OK" : "KO") << std::endl;

	double e = 4.2;
	double f = -4.2;
	::swap(e, f);
	std::cout << std::endl << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
	std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
	return (0);
}
