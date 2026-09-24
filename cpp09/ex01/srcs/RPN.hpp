/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <list>
# include <string>

class RPN {
	private:
		/* std::stack is only an adapter: std::list is the real container */
		std::stack<long, std::list<long> >	_stack;

		static bool	_isOperator(std::string const &token);
		long		_apply(char op, long left, long right) const;
	public:
		RPN();
		RPN(RPN const &other);
		~RPN();

		RPN &operator=(RPN const &other);

		long evaluate(std::string const &expression);
};

#endif
