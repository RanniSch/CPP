/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:36:45 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:27:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

// Constructors
Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice &copy) : AMateria("ice")
{
	*this = copy;
}

// Destructor
Ice::~Ice()
{

}

// Overloaded operator
Ice& Ice::operator=(const Ice &src)
{
	this->_type = src._type;
    return (*this);
}

// Public member functions
/*
* The member function clone() will return a new instance of the same type (clone an Ice Materia, gets a new Ice Materia).
*/
AMateria* Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
