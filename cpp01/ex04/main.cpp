/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/16 15:39:24 by brmaria-          #+#    #+#             */
/*   Updated: 2026/05/16 16:37:19 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	if (argc == 4)
	{
		std::ifstream	Infile(argv[1]);
		std::string		OutfileName = std::string(argv[1]) + ".replace";
		std::ofstream	Outfile(OutfileName.c_str());
		std::string		s1 = argv[2];
		std::string		s2 = argv[3];
		std::string		Line;
		if (!Infile || !s1[0])
		{
			if (!Infile)
				std::cout << "File not valid. Add a valid one." << std::endl;
			else if (!s1[0])
				std::cout << "s1 empty. Add a valid one." << std::endl;
			return -1;
		}
		while(std::getline(Infile, Line))
		{
			size_t	Pos = 0;
			while ((Pos = Line.find(s1, Pos)) != std::string::npos)
			{
				Line.erase(Pos, s1.length());
				Line.insert(Pos, s2);
				Pos+= s2.length();
			}
			Outfile << Line << "\n";
		}
	}
	else
		std::cout << "There's not enough arguments" << std::endl;
	return 0;
}