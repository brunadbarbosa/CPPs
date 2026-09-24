/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) : _rates(other._rates) {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
	if (this != &other)
		this->_rates = other._rates;
	return (*this);
}

/* ------------------------------ Helpers ------------------------------ */

static std::string trim(std::string const &str) {
	size_t start = str.find_first_not_of(" \t\r\n");
	size_t end = str.find_last_not_of(" \t\r\n");

	if (start == std::string::npos)
		return ("");
	return (str.substr(start, end - start + 1));
}

static bool isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

/* YYYY-MM-DD, with a real month and a real day for that month */
bool BitcoinExchange::_isValidDate(std::string const &date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return (false);
	for (size_t i = 0; i < date.length(); i++) {
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month < 1 || month > 12 || day < 1)
		return (false);
	if (month == 2 && isLeapYear(year))
		return (day <= 29);
	return (day <= daysInMonth[month - 1]);
}

/* [+-]digits[.digits] -> value. Returns false if it is not a number. */
bool BitcoinExchange::_parseValue(std::string const &str, double &value) {
	size_t i = 0;
	int dots = 0;
	int digits = 0;

	if (str.empty())
		return (false);
	if (str[i] == '+' || str[i] == '-')
		i++;
	for (; i < str.length(); i++) {
		if (str[i] == '.')
			dots++;
		else if (std::isdigit(static_cast<unsigned char>(str[i])))
			digits++;
		else
			return (false);
	}
	if (dots > 1 || digits == 0)
		return (false);
	value = std::strtod(str.c_str(), NULL);
	return (true);
}

/* ------------------------------ Database ----------------------------- */

void BitcoinExchange::loadDatabase(std::string const &filename) {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open database.");
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");
	/* first line is the header "date,exchange_rate" */
	while (std::getline(file, line)) {
		line = trim(line);
		if (line.empty())
			continue ;
		size_t comma = line.find(',');
		double rate;
		if (comma == std::string::npos
			|| !_isValidDate(line.substr(0, comma))
			|| !_parseValue(line.substr(comma + 1), rate)
			|| rate < 0)
			throw std::runtime_error("Error: bad line in database => " + line);
		this->_rates[line.substr(0, comma)] = rate;
	}
	if (this->_rates.empty())
		throw std::runtime_error("Error: empty database.");
}

/* -------------------------------- Input ------------------------------ */

void BitcoinExchange::_processLine(std::string const &line) const {
	size_t separator = line.find(" | ");

	if (separator == std::string::npos) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	std::string date = line.substr(0, separator);
	std::string valueStr = trim(line.substr(separator + 3));
	double value;

	if (!_isValidDate(date)) {
		std::cout << "Error: bad input => " << date << std::endl;
		return ;
	}
	if (!_parseValue(valueStr, value)) {
		std::cout << "Error: bad input => " << line << std::endl;
		return ;
	}
	if (value < 0) {
		std::cout << "Error: not a positive number." << std::endl;
		return ;
	}
	if (value > 1000) {
		std::cout << "Error: too large a number." << std::endl;
		return ;
	}

	/* upper_bound gives the first date AFTER the one we want:  */
	/* going one step back gives the exact date or the closest  */
	/* lower one. If it is already begin(), there is no lower.  */
	std::map<std::string, double>::const_iterator it = this->_rates.upper_bound(date);
	if (it == this->_rates.begin()) {
		std::cout << "Error: no data before => " << date << std::endl;
		return ;
	}
	--it;
	std::cout << std::setprecision(10) << date << " => " << value << " = " << value * it->second << std::endl;
}

void BitcoinExchange::processInput(std::string const &filename) const {
	std::ifstream file(filename.c_str());
	std::string line;

	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	if (!std::getline(file, line))
		return ;
	/* skip the header "date | value" (only if the first line is the header) */
	if (trim(line) != "date | value")
		this->_processLine(trim(line));
	while (std::getline(file, line)) {
		line = trim(line);
		if (line.empty())
			continue ;
		this->_processLine(line);
	}
}
