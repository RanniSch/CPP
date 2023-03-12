/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 13:20:59 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
    //std::cout << "Constructor called" << std::endl;
    return;
}

Contact::~Contact(void)
{
    //std::cout << "Destructor called" << std::endl;
    return;
}

/*
* Saves the typed in input from class phonebook into the private variables from class contact.
*/
void    Contact::adddata(int index, std::string in_first, std::string in_last, std::string in_nick, std::string in_num, std::string in_sec)
{
    this->c_index = index;
    this->_firstname = in_first;
    this->_lastname = in_last;
    this->_nickname = in_nick;
    this->_phonenumber = in_num;
    this->_secret = in_sec;
}

/*
* #include <iomanip>
* 'undefined' setw (int n);
* Sets the field width to be used on output operations.
* Writes user input strings into the fields.
* user_index is used to search from 1 till 8!
*/
void    Contact::putextract(void)
{
    int user_index = this->c_index + 1;

    std::cout << "|";
    std::cout << std::setw(10) << user_index << "|";
    if (this->_firstname.length() > 10)
        std::cout << std::setw(10) << this->_firstname.substr(0, 9) + "." << "|";
    else
        std::cout << std::setw(10) << this->_firstname << "|";
    if (this->_lastname.length() > 10)
        std::cout << std::setw(10) << this->_lastname.substr(0, 9) + "." << "|";
    else
        std::cout << std::setw(10) << this->_lastname << "|";
    if (this->_nickname.length() > 10)
        std::cout << std::setw(10) << this->_nickname.substr(0, 9) + "." << "|" << std::endl;
    else
        std::cout << std::setw(10) << this->_nickname << "|" << std::endl;
    std::cout << "|-------------------------------------------|" << std::endl;
}

/*
* Writes one contact into the terminal.
*/
void    Contact::putdata(void)
{
    std::cout << "" << std::endl;
    std::cout << "\033[33mCONTACT\033[0m" << std::endl;
    std::cout << "first name: " << this->_firstname << std::endl;
    std::cout << "last name: " << this->_lastname << std::endl;
    std::cout << "nickname: " << this->_nickname << std::endl;
    std::cout << "phone number: " << this->_phonenumber << std::endl;
    std::cout << "secret: " << this->_secret << std::endl;
}
