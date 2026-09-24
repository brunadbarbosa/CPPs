/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

/* std::stack is an adapter: it keeps the real container in a protected */
/* member called "c". Inheriting from it gives access to c, so we only   */
/* need to expose c's iterators.                                         */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		typedef typename Container::iterator				iterator;
		typedef typename Container::const_iterator			const_iterator;
		typedef typename Container::reverse_iterator		reverse_iterator;
		typedef typename Container::const_reverse_iterator	const_reverse_iterator;

		MutantStack();
		MutantStack(MutantStack const &other);
		~MutantStack();

		MutantStack &operator=(MutantStack const &other);

		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

# include "MutantStack.tpp"

#endif
