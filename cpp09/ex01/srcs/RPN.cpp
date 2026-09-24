/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <sstream>
#include <cctype>
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(RPN const &other) : _stack(other._stack) {}

RPN::~RPN() {}

RPN &RPN::operator=(RPN const &other) {
	if (this != &other)
		this->_stack = other._stack;
	return (*this);
}

bool RPN::_isOperator(std::string const &token) {
	return (token.length() == 1 && std::string("+-*/").find(token[0]) != std::string::npos);
}

long RPN::_apply(char op, long left, long right) const {
	switch (op) {
		case '+':
			return (left + right);
		case '-':
			return (left - right);
		case '*':
			return (left * right);
		default:
			if (right == 0)
				throw std::runtime_error("division by zero");
			return (left / right);
	}
}

/* Every token is separated by spaces:                                 */
/*  - a number (< 10) is pushed on the stack                           */
/*  - an operator pops two numbers, computes, and pushes the result    */
/* At the end, exactly one number (the result) must be left.           */
long RPN::evaluate(std::string const &expression) {
	std::istringstream iss(expression);
	std::string token;

	while (!this->_stack.empty())
		this->_stack.pop();
	while (iss >> token) {
		if (token.length() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			this->_stack.push(token[0] - '0');
		else if (_isOperator(token)) {
			if (this->_stack.size() < 2)
				throw std::runtime_error("not enough operands");
			long right = this->_stack.top();
			this->_stack.pop();
			long left = this->_stack.top();
			this->_stack.pop();
			this->_stack.push(this->_apply(token[0], left, right));
		}
		else
			throw std::runtime_error("invalid token: " + token);
	}
	if (this->_stack.size() != 1)
		throw std::runtime_error("invalid expression");
	return (this->_stack.top());
}
