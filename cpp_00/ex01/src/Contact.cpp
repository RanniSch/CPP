/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 14:18:14 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact (std::string input_firstname, std::string input_lastname) : _firstname(input_firstname), _lastname(input_lastname)
{
    std::cout << "Constructor called" << std::endl;

    std::cout << "first name: " << this->_firstname << std::endl;
    std::cout << "last name: " << this->_lastname << std::endl;

    return;
}

Contact::~Contact()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Contact::getdata()
{
    std::cout << "Enter phone number: ";
    std::cin >> _phonenumber;
}

void    Contact::putdata()
{
    std::cout << _phonenumber << std::endl;  
}
