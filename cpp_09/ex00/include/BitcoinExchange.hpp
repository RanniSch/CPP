/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:41:32 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 18:26:36 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream> // for close()
//# include <string>
# include <cstring>  // for c_str()
# include <algorithm>
# include <map> // for class template map

class	BitcoinExchange {
	    public:
		        BitcoinExchange(void);
		        BitcoinExchange(const BitcoinExchange& src);
		        BitcoinExchange& operator=(const BitcoinExchange& src);
		        ~BitcoinExchange (void);

		        void							checkOpenFile(std::ifstream &infile);
		        void							storeDatabase(char* infileName);
                
                int								checkDateValidity(std::string date);
		        float							findBtcRate(std::string date);
		        void							printBtcValue(char* infileName);
		        
                std::map<std::string, float>	getExchangeRateMap();
		        void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);

	    private:
		        /*
                * class template std::map
                * Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
                * In a map, the key values (date) are generally used to sort and uniquely identify the elements, while the mapped values (numericValue) store the content associated to this key.
                * The types of key and mapped value may differ, and are grouped together in member type value_type, which is a pair type combining both:
                * typedef pair<const Key, T> value_type --> std::pair<std::string, float > (date, numericValue)
                */
                std::map<std::string, float>	_btcExchangeRate;
};

void	printExchangeRate(const std::pair<std::string, float>& exchangeRate);

#endif