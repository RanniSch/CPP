/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:33:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:27:21 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

// Constructors
Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &copy) : AMateria("cure")
{
	*this = copy;
}

// Destructor
Cure::~Cure()
{
    
}

// Overloaded operator
Cure& Cure::operator=(const Cure &src)
{
	this->_type = src._type;
    return (*this);
}

// Public member functions
/*
* The member function clone() will return a new instance of the same type (clone a Cure Materia, gets a new Cure Materia).
*/
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
