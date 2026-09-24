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
#include <exception>
#include "RPN.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	try {
		RPN rpn;

		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (std::exception const &e) {
		std::cerr << "Error" << std::endl;
		return (1);
	}
	return (0);
}
