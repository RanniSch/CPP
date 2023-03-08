/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 15:18:21 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*Contact::Contact (std::string input_firstname, std::string input_lastname) : _firstname(input_firstname), _lastname(input_lastname)
{
    std::cout << "Constructor called" << std::endl;

    std::cout << "first name: " << this->_firstname << std::endl;
    std::cout << "last name: " << this->_lastname << std::endl;

    return;
}*/

Contact::Contact()
{
    std::cout << "Constructor called" << std::endl;
    this->c_exists = false;
    return;
}

Contact::~Contact()
{
    std::cout << "Destructor called" << std::endl;
    return;
}

void    Contact::getdata()
{
    std::cout << "Enter first name: ";
    std::cin >> _firstname;
    std::cout << "Enter last name: ";
    std::cin >> _lastname;
    std::cout << "Enter nickname: ";
    std::cin >> _nickname;
    std::cout << "Enter phone number: ";
    std::cin >> _phonenumber;
    std::cout << "Enter secret: ";
    std::cin >> _secret;
}

void    Contact::putdata()
{
    std::cout << _firstname << " ";
    std::cout << _lastname << " ";
    std::cout << _nickname << " ";
    std::cout << _phonenumber << " ";
    std::cout << _secret << " " << std::endl;  
}
