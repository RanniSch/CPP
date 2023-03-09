/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 11:31:14 by rschlott         ###   ########.fr       */
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

void    Contact::adddata(int user_index, std::string in_first, std::string in_last, std::string in_nick, int in_num, std::string in_sec)
{
    this->c_index = user_index;
    this->_firstname = in_first;
    this->_lastname = in_last;
    this->_nickname = in_nick;
    this->_phonenumber = in_num;
    this->_secret = in_sec;
}

void    Contact::putextract(void)
{
    std::cout << this->c_index << " ";
    std::cout << this->_firstname << " ";
    std::cout << this->_lastname << " ";
    std::cout << this->_nickname << " " << std::endl;
}

void    Contact::putdata(void)
{
    std::cout << "first name: " << this->_firstname << std::endl;
    std::cout << "last name: " << this->_lastname << std::endl;
    std::cout << "nickname: " << this->_nickname << std::endl;
    std::cout << "phone number: " << this->_phonenumber << std::endl;
    std::cout << "secret: " << this->_secret << std::endl;
}
