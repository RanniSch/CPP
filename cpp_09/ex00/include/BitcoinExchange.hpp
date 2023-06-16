/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:41:32 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 23:15:52 by rschlott         ###   ########.fr       */
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
		        // Constructors
                BitcoinExchange(void);
		        BitcoinExchange(const BitcoinExchange& copy);
                
                // Destructor
                ~BitcoinExchange (void);

                // Overload operator
		        BitcoinExchange& operator=(const BitcoinExchange& src);

                // Setter and getter
                void    						setExchangeRate(const std::pair<std::string, float>& exchangeRate);
                std::map<std::string, float>	getExchangeRateMap(void);
                
                // Public member functions
		        void							checkOpenFile(std::ifstream &infile);
		        void							dataExchangeRate(char* datafileName);
                
                int								checkDateValidity(std::string date);
		        float							findBtcRate(std::string date);
		        void							printBtcValue(char* infileName);


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

#endif