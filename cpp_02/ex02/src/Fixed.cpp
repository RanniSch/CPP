/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:01 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/21 08:10:23 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fpValue(0)
{
    //std::cout << "Default constructor called" << std::endl;
    return;
}

/*
* Constructor converts input to the const fixed point value.
*/
Fixed::Fixed(const int input)
{
    //std::cout << "Int constructor called" << std::endl;
    this->_fpValue = input << this->_fracBits;
}

/*
* Constructor converts a const floating-point number to the correspondig fixed-point value.
* float roundf( float arg ): Computes the nearest integer value to arg (in floating-point format), 
* rounding halfway cases away from zero, regardless of the current rounding mode.
*/
Fixed::Fixed(const float input)
{
    //std::cout << "Float constructor called" << std::endl;
    this->_fpValue = roundf(input * (1 << this->_fracBits));
}

Fixed::Fixed(const Fixed &copy)
{
    //std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
    return;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &src)
        this->_fpValue = src.getRawBits();
    
    return (*this);
}


/*
* 6 Overloaded Comparison Operators
*/
bool	Fixed::operator>(Fixed fixed) const
{
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator<(Fixed fixed) const
{
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>=(Fixed fixed) const
{
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<=(Fixed fixed) const
{
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator==(Fixed fixed) const
{
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!=(Fixed fixed) const
{
	return (this->toFloat() != fixed.toFloat());
}


/*
* 4 Overloaded Arithmetic Operators
*/
float	Fixed::operator+(Fixed fixed) const
{
	return (this->toFloat() + fixed.toFloat());
}

float	Fixed::operator-(Fixed fixed) const
{
	return (this->toFloat() - fixed.toFloat());
}

float	Fixed::operator*(Fixed fixed) const
{
	return (this->toFloat() * fixed.toFloat());
}

float	Fixed::operator/(Fixed fixed) const
{
	return (this->toFloat() / fixed.toFloat());
}


/*
* 4 increment/decrement (pre-increment and post-increment, pre-decrement and post-decrement)
*/
Fixed	Fixed::operator++(void)
{
	this->_fpValue++;
	return (*this);
}

Fixed	Fixed::operator--(void)
{
	this->_fpValue--;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed temp = *this;
	++this->_fpValue;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed temp = *this;
	--this->_fpValue;
	return (temp);
}


/*
* converts the fixed-point value to a floating-point value.
*/
float Fixed::toFloat(void) const
{
    return ((float)this->_fpValue / (float)(1 << this->_fracBits));
}

/*
* converts the fixed-point value to an integer value.
*/
int Fixed::toInt(void) const
{
    return (this->_fpValue >> this->_fracBits);
}

/*
* A static member function min that takes as parameters two references on fixed-point
* numbers, and returns a reference to the smallest one.
*/
Fixed	&Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

/*
* A static member function min that takes as parameters two references to constant
* fixed-point numbers, and returns a reference to the smallest one.
*/
const Fixed	&Fixed::min(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

/*
* A static member function max that takes as parameters two references on fixed-point
* numbers, and returns a reference to the greatest one.
*/
Fixed	&Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

/*
* A static member function max that takes as parameters two references to constant
* fixed-point numbers, and returns a reference to the greatest one.
*/
const Fixed	&Fixed::max(const Fixed &first, const Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

/*
* Returns the raw value of the fixed-point value.
*/
int Fixed::getRawBits(void) const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->_fpValue);
}

/*
* Sets the raw value of the fixed-point number.
*/
void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    this->_fpValue = raw;
}

/*
* An overload of the insertion («) operator that inserts a floating-point representation
* of the fixed-point number into the output stream object passed as parameter.
* std::ostream class is an output stream that inserts fromatted output (operator<<).
*/
std::ostream    &operator<<(std::ostream &ostream, Fixed const &myClass)
{
    ostream << myClass.toFloat();
    return (ostream);
}
