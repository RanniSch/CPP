/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:44:19 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 09:49:02 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//======== CONSTRUCTORS =========================================================================
BitcoinExchange::BitcoinExchange() :
	_btcExchangeRate(std::map<std::string, float>())
{
	// std::cout << BLU << "Default constructor called from BitcoinExchange" << D << "\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	// std::cout << BLU << "Copy constructor called from BitcoinExchange" << D << "\n";
	*this = src;
}


//======== OVERLOAD OPERATORS ===================================================================
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	// std::cout << BLU << "Copy assignment operator called from BitcoinExchange" << D << "\n";
	if (this != &src)
	{
		new (this) BitcoinExchange(src);
	}
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
BitcoinExchange::~BitcoinExchange()
{
	// std::cout << CY << "Destructor called from BitcoinExchange" << D << "\n";
}


//======== GETTER / SETTER ======================================================================
void	BitcoinExchange::setExchangeRate(const std::pair<std::string, float>& setExchangeRate)
{
	 this->_btcExchangeRate.insert(setExchangeRate);
}

std::map<std::string, float>	BitcoinExchange::getExchangeRateMap()
{
	return _btcExchangeRate;
}


//======== MEMBER FUNCTIONS =====================================================================

void	BitcoinExchange::checkFileCanBeOpened(std::ifstream& file)
{
	if (!file.is_open())
	{
		std::cout << "\033[31mError: File couldn't be opened!\033[0m" << std::endl;
		return ;
	}
}

void	BitcoinExchange::storeDatabase(char* infilePath)
{
	std::ifstream infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		size_t	pos = line.find(",");
		if (pos == std::string::npos)
		{
			std::cout << "\033[31mError: delimiter not found in line \"" << line << "\"\033[0m" << std::endl;
			continue;
		}
		std::string	date = line.substr(0, pos);
		std::string	numericValue = line.substr(pos + 1); // +1 is for length of comma delimiter.
		float btcNumericValueInt = static_cast<float>(atof(numericValue.c_str()));
		this->_btcExchangeRate.insert(std::pair<std::string, float > (date, btcNumericValueInt));
	}
	infile.close();
}

float	BitcoinExchange::findBtcRate(std::string date)
{
	float		btcCoinRate = 0;
	bool		dateFound = false;
	std::string	closestEarlierDate;
	float		closestEarlierRate = 0;
	std::map<std::string, float>::const_iterator it; // declare a const_iterator for the map

	for (it = _btcExchangeRate.begin(); it != _btcExchangeRate.end(); it++)
	{
		if (it->first < date) // check if the current date in the map is earlier than the desired date
		{
			if (closestEarlierDate.empty() || closestEarlierDate < it->first) // check if this date is closer than the previously found closest date
			{
				closestEarlierDate = it->first;
				closestEarlierRate = it->second;
			}
		}
		else if (it->first == date)
		{
			btcCoinRate = it->second;
			dateFound = true;
			break;
		}
	}
	if (dateFound == false)
	{
		if (!closestEarlierDate.empty())
			btcCoinRate = closestEarlierRate;
		else
			btcCoinRate = 0;
	}
	return (btcCoinRate);
}

int	BitcoinExchange::checkDateValidity(std::string date)
{
    std::string    month = date.substr(5);
    std::string    day = month.substr(3);
    if (date > "2023" || month > "12" || day > "31")
        return (-1);
    return (0);
}


void	BitcoinExchange::printBtcValue(char* infilePath)
{
	std::ifstream infile(infilePath);
	checkFileCanBeOpened(infile);
	std::string	line;
	std::getline(infile, line); // Skip the first line
	while(getline(infile, line))
	{
		const std::string& delimiter = " | ";
		size_t	pos = line.find(delimiter);
		if (pos == std::string::npos)
		{
			std::cout << "\033[31mError: bad input => " << line << "\033[0m" << std::endl;
			continue;
		}
		std::string date = line.substr(0, pos);
		int checkDate = checkDateValidity(date);
		if (checkDate < 0)
		{
			std::cout << "\033[31mError: date not valid." << "\033[0m" << std::endl;
			continue;
		}
		std::string btcCoinsNumber = line.substr(pos + delimiter.length());

		float btcCoinsNumberInt = static_cast<float>(atof(btcCoinsNumber.c_str()));
		if (btcCoinsNumberInt < 0)
		{
			std::cout << "\033[31mError: not a positive number." << "\033[0m" << std::endl;
			continue;
		}
		if (static_cast<long>(btcCoinsNumberInt) > 1000)
		{
			std::cout << "\033[31mError: too large a number." << "\033[0m" << std::endl;
			continue;
		}
		float btcCoinRate = 0;
		btcCoinRate = findBtcRate(date);
		std::cout << date << " => " << btcCoinsNumberInt << " = " << static_cast<float>(btcCoinsNumberInt * btcCoinRate) << std::endl;
	}
	infile.close();
}


//======== FUNCTIONS ============================================================================
void	printExchangeRate(const std::pair<std::string, float>& exchangeRate)
{
	std::cout << exchangeRate.first << " , " << exchangeRate.second << std::endl;
}
