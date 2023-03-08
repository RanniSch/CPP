/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 10:15:27 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Contact::Contact (char _firstname[10], char _lastname[10])
Contact::Contact (char input_firstname, char input_lastname) : _firstname(input_firstname), _lastname(input_lastname)
{
    std::cout << "Constructor called" << std::endl;

    std::cout << "first and last name set" << std::endl;
    //this->_firstname = _firstname[10];
    std::cout << "first name: " << this->_firstname << std::endl;
    //this->_lastname = _lastname[10];
    std::cout << "last name: " << this->_lastname << std::endl;

    return;
}

Contact::~Contact()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

/*void    Contact::getdata()
{
    
}*/