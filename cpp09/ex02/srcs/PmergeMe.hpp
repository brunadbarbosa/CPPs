/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe {
	private:
		std::vector<int>	_input;
		std::vector<int>	_vector;
		std::deque<int>		_deque;
		double				_vectorTime;
		double				_dequeTime;

		static int					_parseNumber(std::string const &token);
		static std::vector<size_t>	_sortVector(std::vector<int> &values);
		static std::deque<size_t>	_sortDeque(std::deque<int> &values);
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &other);
		~PmergeMe();

		PmergeMe &operator=(PmergeMe const &other);

		void parse(int argc, char **argv);
		void sort();
		void display() const;
};

#endif
