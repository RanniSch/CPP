/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:16 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 11:55:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

/*
* After creating new PhoneBook _num_entries = 0 until first entry set.
*/
void    PhoneBook::PhoneBook(void)
{
    std::cout << "PhoneBook constructor called" << std::endl;
    // maybe initializing each contact of class Contact
    this->_num_entries = 0;
    return;
}

/*
* destructor of PhoneBook
*/
void    PhoneBook::~PhoneBook(void)
{
    std::cout << "PhoneBook destructor called" << std::endl;
    return;
}

/*
* overwrites first contact with second and so on, when array has
* already 8 contacts and a new one is ADDed.
*/
void    PhoneBook::replace_oldest_contact(void)
{
    for (int i = 0; i < 7; i++)
    {
        this->persons[i] = this->persons[i + 1];
        this->persons[i].c_index = this->persons[i + 1].c_index - 1;
    }    
}

/*
* writes contact details into array
* int index will be passed to function adddata in Contact class
* 
* instead if calling function from class Contact like this
* Contact::adddata(index, in_first, in_last, in_nick, in_num, in_sec);
* we can call the same function through the specific instance
* Persons[_num_entries].adddata(index, in_first, in_last, in_nick, in_num, in_sec);
*
* user_index is used for SEARCH and starts at 1!
*/
void    PhoneBook::new_contact_to_array(std::string in_first, std::string in_last, std::string in_nick, int in_num, std::string in_sec)
{
    int user_index;

    user_index = this->_num_entries + 1;
    if (this->_num_entries < 8)
    {
        persons[_num_entries].adddata(user_index, in_first, in_last, in_nick, in_num, in_sec);
        this->_num_entries++;
    }
    else
    {
        PhoneBook::replace_oldest_contact(void);
        persons[_num_entries].adddata(user_index, in_first, in_last, in_nick, in_num, in_sec);
    }
}

/*
* displays the extract of all entries after SEARCH, when min one exists.
*/
void    PhoneBook::display_extract(void)
{
    if (this->_num_entries > 0)
    {
        for (int i = 0; i <= this->_num_entries; i++)
           persons[_num_entries].putextract(void); 
    }
    else
        std::cout << "No entries found! Write ADD and add a contact." << std::endl;
}

/*
* displays whole data of one specific entry after index was put in and is valid.
*/
void    PhoneBook::display_data(int user_index)
{
    index = user_index - 1;
    if (user_index >= 0 && user_index <= this->_num_entries)
        persons[index].putdata(void);
    else
        std::cout << "No entry found! Write an existing index." << std::endl;
}
