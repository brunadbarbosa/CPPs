/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array {
	private:
		T				*_elements;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		~Array();

		Array &operator=(Array const &other);

		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;

		unsigned int size() const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

# include "Array.tpp"

#endif
