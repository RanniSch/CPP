/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:44:19 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 19:12:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//======== CONSTRUCTORS =========================================================================

/*
* std::map<std::string, float>()
* std::map is a sorted associative container that contains key-value pairs with unique keys.
*/
BitcoinExchange::BitcoinExchange(void) : _btcExchangeRate(std::map<std::string, float>())
{
	std::cout << "BitcoinExchange default constructor called!" << std::endl;
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
BitcoinExchange::~BitcoinExchange(void)
{
    std::cout << "BitcoinExchange destructor called!" << std::endl;
}


//======== GETTER / SETTER ======================================================================
void	BitcoinExchange::setExchangeRate(const std::pair<std::string, float> &setExchangeRate)
{
	 this->_btcExchangeRate.insert(setExchangeRate);
}

std::map<std::string, float>	BitcoinExchange::getExchangeRateMap()
{
	return (_btcExchangeRate);
}


//======== MEMBER FUNCTIONS =====================================================================

/*
* is_open() -> true if a file is open and associated with this stream object, false otherwise.
*/
void	BitcoinExchange::checkOpenFile(std::ifstream &infile)
{
	if (!infile.is_open())
	{
		std::cout << "\033[31mError: Couldn't open file!\033[0m" << std::endl;
		return ;
	}
}

/*
* std::ifstream -> Input stream class to operate on files.
*
* open() -> opening a file in read mode.
*
* getline (istream& infile, string& line);
* Extracts characters from infile and stores them into line until the newline character '\n' is found.
* The extraction also stops if the end of file is reached.
* If the delimiter is found, it is extracted and discarded (i.e. it is not stored and the next input operation will begin after it).
* Note that any content in line before the call is replaced by the newly extracted sequence.
*
* public static member constant std::string::npos
* static member constant value with the greatest possible value for an element of type size_t.
* This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
* As a return value, it is usually used to indicate no matches.
* 18446744073709551615 means -1 -> so no "|" found
*
* public member function std::string::substr -> string substr (0, indexNum) const;
* Returns a newly constructed string object with its value initialized to a copy of a substring of this object.
* The substring is the portion of the object that starts at character position 0 and spans indexNum characters (or until the end of the string, whichever comes first).
*
* static_cast<float>
* Converts variable j to type float. This allows the compiler to generate a division with an answer of type float.
* 
* atof() -> convert a char array to double; float btcNumericValueInt = std::stof(numericValue) would be easier but doesn't compile on c++98.
*
* c_str() -> str to array with a spot for each element.
* Converts a string to an array of characters and terminates this array with a null character at the end.
*
* public member function std::map::insert
* Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
* Because element keys in a map are unique, the insertion operation checks whether each inserted element has a key equivalent
* to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).
*
* close() -> Closes the file currently associated with the object, disassociating it from the stream.
*/
void	BitcoinExchange::storeDatabase(char* infileName)
{
	std::ifstream infile;
    
    infile.open(infileName);
	checkOpenFile(infile);
	
    std::string	line;
	std::getline(infile, line); // Skip the first line "date | value"
	while(getline(infile, line))
	{
		//size_t	indexNum = line.find(","); // for data.csv
        size_t	indexNum = line.find("|"); // for input.txt
        //std::cout << "indexNum:_" << indexNum << std::endl; // for testing
		if (indexNum == std::string::npos)
		{
			//std::cout << "indexNum: " << indexNum << std::endl; // for testing
            //std::cout << "\033[31mError: Comma not found in line \"" << line << "\"\033[0m" << std::endl; // for testing
			continue;
		}
		std::string	date = line.substr(0, indexNum);
		std::string	value = line.substr(indexNum + 1); // +1 to start (safe) substr from after comma delimiter until end of line (for the values).
		//std::cout << "value:_" << value << std::endl; // for testing
        float numericValue = static_cast<float>(atof(value.c_str()));
        //std::cout << "numericValue:_" << numericValue << std::endl; // for testing
		this->_btcExchangeRate.insert(std::pair<std::string, float > (date, numericValue));
    }
	infile.close();
}

/*
* Functions checks for western date standard and returns -1 if date is invalid.
*/
int	BitcoinExchange::checkDateValidity(std::string date)
{
    std::string    month = date.substr(5);
    std::string    day = month.substr(3);
    if (date > "2023" || month > "12" || day > "31")
        return (-1);
    return (0);
}

float	BitcoinExchange::findBtcRate(std::string date)
{
	float		btcRate = 0;
	bool		dateFound = false;
	std::string	closestEarlierDate;
	float		closestEarlierRate = 0;
	std::map<std::string, float>::const_iterator it; // declare a const_iterator "it" for the map; it->first "date" & it->second "value"

	for (it = _btcExchangeRate.begin(); it != _btcExchangeRate.end(); it++)
	{
        std::cout << "it->first_" << it->first << " date_" << date << std::endl;
        if (it->first < date) // check if the current date (looping iterator it points to first, which is the date) in the map is earlier than the desired (incoming) date.
		{
			if (closestEarlierDate.empty() || closestEarlierDate < it->first) // check if this date is closer than the previously found closest date
			{
				closestEarlierDate = it->first;     // it->first -> "date" of infile
                std::cout << "cED1_" << closestEarlierDate << "_" << std::endl;
				closestEarlierRate = it->second;    // it->second -> "value" of infile
                std::cout << "cER2_" << closestEarlierRate << "_" << std::endl;
			}
		}
		else if (it->first == date)     // it->first -> "date" of infile
		{
			btcRate = it->second;   // value of infile
            std::cout << "Rate1:_" << btcRate << std::endl;
			dateFound = true;
			break;
		}
	}
	if (dateFound == false)
	{
		std::cout << "drin" << std::endl;
        if (!closestEarlierDate.empty())
			btcRate = closestEarlierRate;
		else
			btcRate = 0;
	}
    std::cout << "Rate:_" << btcRate << std::endl;
	return (btcRate);
}

void	BitcoinExchange::printBtcValue(char* infileName)
{
	std::ifstream infile;

    infile.open(infileName);
	checkOpenFile(infile);
    
	std::string	line;
	std::getline(infile, line); // Skips the first line "date | value"
	while(getline(infile, line))
	{
		const std::string& delimiter = " | ";
		size_t	indexNum = line.find(delimiter);
		if (indexNum == std::string::npos)
		{
			std::cout << "\033[31mError: bad input => " << line << "\033[0m" << std::endl;
			continue;
		}
		std::string date = line.substr(0, indexNum);
		int checkDate = checkDateValidity(date);
		if (checkDate < 0)
		{
			std::cout << "\033[31mError: date not valid." << "\033[0m" << std::endl;
			continue;
		}
		std::string btcNumber = line.substr(indexNum + delimiter.length());

		float btcNumberInt = static_cast<float>(atof(btcNumber.c_str()));
		if (btcNumberInt < 0)
		{
			std::cout << "\033[31mError: not a positive number." << "\033[0m" << std::endl;
			continue;
		}
		if (static_cast<long>(btcNumberInt) > 1000)
		{
			std::cout << "\033[31mError: too large a number." << "\033[0m" << std::endl;
			continue;
		}
		float btcRate = 0;
        std::cout << "incoming date_" << date << std::endl;
		btcRate = findBtcRate(date);
		std::cout << date << " => " << btcNumberInt << " = " << static_cast<float>(btcNumberInt * btcRate) << std::endl;
	}
	infile.close();
}


//======== FUNCTIONS ============================================================================
void	printExchangeRate(const std::pair<std::string, float>& exchangeRate)
{
	std::cout << exchangeRate.first << " , " << exchangeRate.second << std::endl;
}
