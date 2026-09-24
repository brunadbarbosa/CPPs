/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- < brmaria-@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:31:33 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 14:03:46 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}
