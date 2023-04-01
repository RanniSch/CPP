/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:29:05 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:27:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

// Constructors
AMateria::AMateria() 
{
    
}

AMateria::AMateria(const std::string& type) : _type(type)
{
    
}

// Destructor
AMateria::~AMateria()
{

}

// public member functions
const std::string& AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
