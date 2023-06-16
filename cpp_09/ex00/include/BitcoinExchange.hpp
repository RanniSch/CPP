/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:41:32 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 09:43:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <string>
# include <cstring>  
# include <algorithm>
# include <map>

class	BitcoinExchange {
	    public:
		        BitcoinExchange();
		        BitcoinExchange(const BitcoinExchange& src);
		        BitcoinExchange& operator=(const BitcoinExchange& src);
		        ~BitcoinExchange();

		        void							checkFileCanBeOpened(std::ifstream& file);
		        void							storeDatabase(char* infilePath);
		        float							findBtcRate(std::string date);
		        int								checkDateValidity(std::string date);
		        void							printBtcValue(char* infilePath);
		        std::map<std::string, float>	getExchangeRateMap();
		        void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);

	    private:
		        std::map<std::string, float>	_btcExchangeRate;
};

void	printExchangeRate(const std::pair<std::string, float>& exchangeRate);

#endif