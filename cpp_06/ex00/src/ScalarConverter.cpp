/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:54:50 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 13:45:33 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/*
* Static member variables initialization
* Provide declarations for static member variables outside the class definition
* in order for them to be initialized and stored in memory.
*/
std::string	ScalarConverter::_input;
Types		ScalarConverter::_type;

/*
* Private constructors & private overloaded operator
*/
ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called." << std::endl;
}

ScalarConverter::ScalarConverter(std::string const &setInput)
{
	std::cout << "ScalarConverter parameterized constructor called!" << std::endl;
	this->_input = setInput;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	std::cout << "ScalarConverter: Copy constructor called." << std::endl;
	*this = copy;
	//this->_input = copy.setInput(); // for deep copy?
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	std::cout << "ScalarConverter: overloaded operator called." << std::endl;
	this->_input = src._input;
	this->_type = src._type;
	return (*this);
}

/*
* Public destructor
*/
ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter: Default destructor called." << std::endl;
}

/*
* Initiation of the private constructors:
* Calls the private constructors from within the class and returns a pointer
* to the newly created instance.
*/
ScalarConverter*	ScalarConverter::createInstance(void)
{
	return (new ScalarConverter());
}

ScalarConverter*	ScalarConverter::createParameterizedInstance(std::string const &setInput)
{
	return (new ScalarConverter(setInput));
}

ScalarConverter*	ScalarConverter::createDefaultCopyInstance(const ScalarConverter &copy)
{
	return (new ScalarConverter(copy));
}

/*
* Setter and Getter
* The setters take the input from main and saves it in the private variables.
* The getters return this saved input when functions are called.
*/
void	ScalarConverter::setInput(std::string setInput)
{
	_input = setInput;
}

std::string	ScalarConverter::getInput(void)
{
	return (_input);
}

void	ScalarConverter::setType(Types setType)
{
	_type = setType;
}

Types	 ScalarConverter::getType(void)
{
	return (_type);
}

/*
* All the member functions
*/
void	ScalarConverter::convert(std::string const &input)
{
	checkType(input);
	createConv(input);
}

void	ScalarConverter::checkType(std::string const &input)
{
	if (input == "nan" || input == "nanf" )
		_type = NANx;
	else if (input == "-inf" || input == "inf" || input == "+inf" || input == "-inff" || input == "+inff" )
		_type = INFx;
	else if (isInt(input) == true)
		_type = INT;
	else if (isFloat(input) == true)
		_type = FLOAT;
	else if (isDouble(input) == true)
		_type = DOUBLE;
	else if (isChar(input) == true)
		_type = CHAR;
	else
		_type = NOT_VALID;
}

void	ScalarConverter::createConv(std::string const &input)
{
	switch (_type)
	{
	    case -1:
		    createConvFromNotValid();
		    break;
	    case 0:
		    createConvFromChar(input);
		    break;
	    case 1:
		    createConvFromInt(input);
		    break;
	    case 2:
		    createConvFromFloat(input);
		    break;
	    case 3:
		    createConvFromDouble(input);
		    break;
	    case 4:
		    createConvFromNANx(input);
		    break;
	    case 5:
		    createConvFromINFx(input);
		    break;
	    default:
		    std::cout << "\033[31mError: fatal!\033[0m" << std::endl;
		    break;
	}
}


bool	ScalarConverter::isChar(std::string const &input)
{
	bool	isChar = false;

	if (input.length() == 1)
		isChar = true;
	else
		isChar = false;
	return (isChar);
}

/*
* counting from 1:
* line 4: strtol is used to check for potential integer overflow.
* line 4: endptr is a pointer where conversion to long ended (at the dot for instance).
* line 5: checks if conversion failed(empty string). Last character of the string is not null terminator
* line 7: check for INT overflow.
*/
bool	ScalarConverter::isInt(std::string const &input)
{
	bool	isInt = false;
	char	*endptr;

	int longValue = std::strtol(input.c_str(), &endptr, 10);
	if (endptr == input.c_str() || *endptr != '\0')
		isInt = false;
	else if (longValue < INT_MIN && longValue > INT_MAX)
		isInt = false;
	else
		isInt = true;
	return (isInt);
}

/*
* line 4: endptr is a pointer where the conversion to float stopped.
* line 5: Checks if conversion failed(empty string). Check that input is not the float 'f'.
* line 7:  Checks that there are no characters after suffix f.
*/
bool ScalarConverter::isFloat(std::string const &input)
{
	bool isFloat = false;
	char* endptr;
    
	std::strtof(input.c_str(), &endptr);
	if (endptr == input.c_str() || *endptr != 'f')
		isFloat = false;
	else if (*endptr == 'f' && (endptr + 1 && *(endptr + 1) != '\0'))
		isFloat = false;
	else
		isFloat = true;
	return (isFloat);
}

/*
* line 5: endptr is a pointer where the conversion stopped.
* line 9: Checks if conversion failed(emptys tring). Last character of the string is not null terminator
*/
bool ScalarConverter::isDouble(std::string const &input)
{
	bool	isDouble = false;
	char*	endptr;
	size_t	pos;

	std::strtod(input.c_str(), &endptr);
	pos = input.find('.');
	if (pos == std::string::npos)
		isDouble = false;	
	else if (endptr == input.c_str() || *endptr != '\0')
		isDouble = false;
	else
		isDouble = true;
	return (isDouble);
}


void	ScalarConverter::createConvFromNotValid(void)
{
	std::cout << "\033[31mError: Input cannot be converted! It needs to be of scalar type: char, int, float or double.\033[0m\n" << std::endl;
}

void	ScalarConverter::createConvFromChar(std::string const &input)
{
	char c = input[0];
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	std::cout << "\033[36m- into char: " << c << std::endl;
	std::cout << "- into int: " << static_cast<int>(c) << std::endl;
	std::cout << "- into float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << std::endl;
	std::cout << "- into double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << "\033[0m" << std::endl;
}

void	ScalarConverter::createConvFromInt(std::string const &input)
{
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	
    long int	longInt = strtol(_input.c_str(), NULL, 10);
	if (longInt > INT_MAX || longInt < INT_MIN)
	{
		std::cout << "\033[31mError: Integer overflow.\033[0m\n" << std::endl;
		return ;
	}
	int	i = longInt;
	if (i <= CHAR_MAX && i >= CHAR_MIN)
	{
		if (i >= 32 && i <= 127)
			std::cout << "\033[36m- into char: " << static_cast<char>(i) << "\033[0m" << std::endl;
		else
			std::cout << "\033[36m- into char: Non displayable\033[0m" << std::endl;
	}
	else
		std::cout << "\033[36m- into char: impossible" << "\033[0m" << std::endl;
	std::cout << "\033[36m- into int: " << i << std::endl;
	std::cout << "- into float: " << std::fixed << std::setprecision(1) << static_cast<float>(i) << "f" << std::endl;
	std::cout << "- into double: " << std::fixed << std::setprecision(1) << static_cast<double>(i) << "\033[0m" << std::endl;
}

void	ScalarConverter::createConvFromFloat(std::string const &input)
{
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	
    char *endptr;
    
	float	f = strtof(_input.c_str(), &endptr);
	if (f <= CHAR_MAX && f >= CHAR_MIN)
	{
		if (f >= 32 && f <= 127)
			std::cout << "\033[36m- into char: " << static_cast<char>(f) << "\033[0m" << std::endl;
		else
			std::cout << "\033[36m- into char: Non displayable\033[0m" << std::endl;
	}
	else
		std::cout << "\033[36m- into char: impossible" << "\033[0m" << std::endl;
	if (f < (float)INT_MIN || f > (float)INT_MAX)   // typecasting float or "error: implicit conversion from 'int' to 'float' changes value from 2147483647 to 2147483648 [-Werror,-Wimplicit-int-float-conversion]"
		std::cout << "\033[36m- into int: impossible" << "\033[0m" << std::endl;
	else
		std::cout << "\033[36m- into int: " << static_cast<int>(f) << "\033[0m" << std::endl;
	std::cout << "\033[36m- into float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "- into double: " << std::fixed << std::setprecision(1) << static_cast<double>(f) << "\033[0m" << std::endl;
}

void	ScalarConverter::createConvFromDouble(std::string const &input)
{
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	
    double d = strtod(_input.c_str(), NULL);
    
	if (d <= CHAR_MAX && d >= CHAR_MIN)
	{
		if (d >= 32 && d <= 127)
			std::cout << "\033[36m- into char: " << static_cast<char>(d) << "\033[0m" << std::endl;
		else
			std::cout << "\033[36m- into char: Non displayable" << "\033[0m" << std::endl;
	}
	else
		std::cout << "\033[36m- into char: impossible" << "\033[0m" << std::endl;
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "\033[36m- into int: impossible" << "\033[0m" << std::endl;
	else
		std::cout << "\033[36m- into int: " << static_cast<int>(d) << "\033[0m" << std::endl;
	std::cout << "\033[36m- into float: " << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
	std::cout << "- into double: " << std::fixed << std::setprecision(1) << d << "\033[0m" << std::endl;
}

void	ScalarConverter::createConvFromNANx(std::string const &input)
{
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	std::cout << "\033[36m- into char: impossible" << std::endl;
	std::cout << "- into int: impossible\033[0m" << std::endl;
	
    if (_input == "nanf")
	{
		float f = std::numeric_limits<float>::quiet_NaN();
		std::cout << "\033[36m- into float: " << f << "f" << std::endl;
		std::cout << "- into double: " << static_cast<double>(f) << "\033[0m\n" << std::endl;
	}
	else if (_input == "nan")
	{
		double d = std::numeric_limits<float>::quiet_NaN();
		std::cout << "\033[36m- into float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "- into double: " << d << "\033[0m" << std::endl;
	}
}

void	ScalarConverter::createConvFromINFx(std::string const &input)
{
	std::cout << "\033[32m\n----- Input to cast: " << input << " -----\033[0m" << std::endl;
	std::cout << "\033[36m- into char: impossible" << std::endl;
	std::cout << "- into int: impossible\033[0m" << std::endl;

	if (input == "-inff" || input == "+inff" )
	{
		float f = std::numeric_limits<float>::infinity();
		if (input.at(0) == '-')
			f = -f;
		std::cout << "\033[36m- into float: " << f << "f" << std::endl;
		std::cout << "- into double: " << static_cast<double>(f) << "\033[0m" << std::endl;
	}
	if (input == "-inf" || input == "inf" || input == "+inf")
	{
		double d = std::numeric_limits<float>::infinity();
		if (input.at(0) == '-')
			d = -d;
		std::cout << "\033[36m- into float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "- into double: " << d << "\033[0m" << std::endl;
	}
}
