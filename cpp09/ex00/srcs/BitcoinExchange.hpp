/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmaria- <brmaria-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 10:00:00 by brmaria-          #+#    #+#             */
/*   Updated: 2026/09/23 10:00:00 by brmaria-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange {
	private:
		/* date (YYYY-MM-DD) -> exchange rate. Dates in this format are */
		/* ordered correctly by a plain string comparison.              */
		std::map<std::string, double>	_rates;

		static bool	_isValidDate(std::string const &date);
		static bool	_parseValue(std::string const &str, double &value);
		void		_processLine(std::string const &line) const;
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		~BitcoinExchange();

		BitcoinExchange &operator=(BitcoinExchange const &other);

		void loadDatabase(std::string const &filename);
		void processInput(std::string const &filename) const;
};

#endif
