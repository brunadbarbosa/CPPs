/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iterator>
# include <exception>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_numbers;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const &other);
		~Span();

		Span &operator=(Span const &other);

		void addNumber(int number);

		/* adds a whole range of iterators in a single call */
		template <typename InputIterator>
		void addRange(InputIterator first, InputIterator last) {
			if (static_cast<unsigned long>(std::distance(first, last))
				> this->_maxSize - this->_numbers.size())
				throw SpanFullException();
			this->_numbers.insert(this->_numbers.end(), first, last);
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;

		unsigned int size() const;
		unsigned int maxSize() const;

		class SpanFullException : public std::exception {
			public:
				virtual const char *what() const throw();
		};

		class NoSpanException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};

#endif
