/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 15:31:33 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cerrno>
#include <cctype>
#include <cmath>
#include <climits>
#include <cfloat>
#include <limits>

/* ---------------------- Orthodox Canonical Form ---------------------- */
/* The class only has a static method, so it must not be instantiable:  */
/* every constructor, the destructor and the operator= are private.     */

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

/* ------------------------------ Helpers ------------------------------ */

enum e_type {
	TYPE_CHAR,
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_INVALID
};

static bool isNan(double value) {
	return (value != value);
}

static bool isInf(double value) {
	return (value == std::numeric_limits<double>::infinity()
		|| value == -std::numeric_limits<double>::infinity());
}

/* 'a' or a (a single non digit character) */
static bool isChar(std::string const &s) {
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return (true);
	return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

/* [+-]digits */
static bool isInt(std::string const &s) {
	size_t i = 0;

	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return (false);
	for (; i < s.length(); i++)
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return (false);
	return (true);
}

/* [+-]digits.digits (exactly one '.', at least one digit) */
static bool isDecimal(std::string const &s) {
	size_t i = 0;
	int dots = 0;
	int digits = 0;

	if (s.empty())
		return (false);
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (; i < s.length(); i++) {
		if (s[i] == '.')
			dots++;
		else if (std::isdigit(static_cast<unsigned char>(s[i])))
			digits++;
		else
			return (false);
	}
	return (dots == 1 && digits > 0);
}

static bool isPseudoFloat(std::string const &s) {
	return (s == "nanf" || s == "inff" || s == "+inff" || s == "-inff");
}

static bool isPseudoDouble(std::string const &s) {
	return (s == "nan" || s == "inf" || s == "+inf" || s == "-inf");
}

static bool isFloat(std::string const &s) {
	if (isPseudoFloat(s))
		return (true);
	return (s.length() > 1 && s[s.length() - 1] == 'f'
		&& isDecimal(s.substr(0, s.length() - 1)));
}

static bool isDouble(std::string const &s) {
	return (isPseudoDouble(s) || isDecimal(s));
}

static e_type detectType(std::string const &s) {
	if (s.empty())
		return (TYPE_INVALID);
	if (isChar(s))
		return (TYPE_CHAR);
	if (isInt(s))
		return (TYPE_INT);
	if (isFloat(s))
		return (TYPE_FLOAT);
	if (isDouble(s))
		return (TYPE_DOUBLE);
	return (TYPE_INVALID);
}

/* Adds ".0" to integral values (42 -> 42.0), keeps the others as they are */
static std::string formatDecimal(double value) {
	std::ostringstream oss;

	if (value == std::floor(value) && std::fabs(value) < 1e16)
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << value;
	return (oss.str());
}

/* ------------------------------ Printers ----------------------------- */

static void printChar(double value) {
	std::cout << "char: ";
	if (isNan(value) || isInf(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
}

static void printInt(double value) {
	std::cout << "int: ";
	if (isNan(value) || isInf(value) || value < INT_MIN || value > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

static void printFloat(double value) {
	std::cout << "float: ";
	if (isNan(value))
		std::cout << "nanf" << std::endl;
	else if (isInf(value))
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
	else if (std::fabs(value) > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << formatDecimal(static_cast<double>(static_cast<float>(value))) << "f" << std::endl;
}

static void printDouble(double value) {
	std::cout << "double: ";
	if (isNan(value))
		std::cout << "nan" << std::endl;
	else if (isInf(value))
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << formatDecimal(value) << std::endl;
}

static void printAll(double value) {
	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

static void printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

/* ---------------------------- Conversions ---------------------------- */
/* Each literal is first converted to its real type, and only then      */
/* explicitly converted (static_cast) to the other types.               */

static void fromChar(std::string const &s) {
	char c = (s.length() == 3) ? s[1] : s[0];

	printAll(static_cast<double>(c));
}

static void fromInt(std::string const &s) {
	errno = 0;
	long value = std::strtol(s.c_str(), NULL, 10);

	if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
		/* does not fit in an int: still displayable as float/double */
		double asDouble = std::strtod(s.c_str(), NULL);
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		printFloat(asDouble);
		printDouble(asDouble);
		return ;
	}
	int i = static_cast<int>(value);
	printAll(static_cast<double>(i));
}

static void fromFloat(std::string const &s) {
	/* strtof is C++11, so the literal is read as a double and then cast */
	errno = 0;
	double d = std::strtod(s.c_str(), NULL);

	if (!isPseudoFloat(s) && (errno == ERANGE || std::fabs(d) > FLT_MAX)) {
		printImpossible();
		return ;
	}
	float f = static_cast<float>(d);
	printAll(static_cast<double>(f));
}

static void fromDouble(std::string const &s) {
	errno = 0;
	double d = std::strtod(s.c_str(), NULL);

	if (errno == ERANGE && !isPseudoDouble(s)) {
		printImpossible();
		return ;
	}
	printAll(d);
}

void ScalarConverter::convert(std::string const &literal) {
	switch (detectType(literal)) {
		case TYPE_CHAR:
			fromChar(literal);
			break ;
		case TYPE_INT:
			fromInt(literal);
			break ;
		case TYPE_FLOAT:
			fromFloat(literal);
			break ;
		case TYPE_DOUBLE:
			fromDouble(literal);
			break ;
		default:
			printImpossible();
	}
}
