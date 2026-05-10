/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:04:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/10 18:24:05 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
int	main() {
	std::string Brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &Brain;
	std::string& stringREF = Brain;

	std::cout << "Address of string: " << &Brain << std::endl;
	std::cout << "Address of pointer: " << stringPTR << std::endl;
	std::cout << "Address of reference: " << &stringREF << std::endl << std::endl;

	std::cout << "Value of string: " << Brain << std::endl;
	std::cout << "Value of pointer: " << *stringPTR << std::endl;
	std::cout << "Value of reference: " << stringREF << std::endl;
}