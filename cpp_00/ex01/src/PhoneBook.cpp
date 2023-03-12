/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:16 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 13:16:14 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
* After creating new PhoneBook _num_entries = 0 until first entry set.
*/
PhoneBook::PhoneBook(void)
{
    //std::cout << "PhoneBook constructor called" << std::endl;
    this->_num_entries = -1;
    return;
}

/*
* destructor of PhoneBook
*/
PhoneBook::~PhoneBook(void)
{
    //std::cout << "PhoneBook destructor called" << std::endl;
    return;
}

/*
* writing data of one phonebook contact.
* empty fields are forbidden!
*/
int    PhoneBook::input_data(void)
{
    std::string in_first;
    std::string in_last;
    std::string in_nick;
    std::string in_num;
    std::string in_sec;
    
    std::cout << "\033[33mEmpty fields are forbidden!\033[0m" << std::endl;
    while (in_first == "" && std::cin.eof() == false)
    {
        std::cout << "Enter first name: ";
        std::getline(std::cin, in_first);
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
    } 
    while (in_last == "" && std::cin.eof() == false)
    {
        std::cout << "Enter last name: ";
        std::getline(std::cin, in_last);
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
    }
    while (in_nick == "" && std::cin.eof() == false)
    {
        std::cout << "Enter nickname: ";
        std::getline(std::cin, in_nick);
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
    }
    while (in_num == "" && std::cin.eof() == false)
    {
        int number = -5;
        std::cout << "Enter phone number: ";
        std::getline(std::cin, in_num);
        for (unsigned long i = 0; i < in_num.length(); i++)
        {
            number = int(in_num[i]) - 48;
            if (number < 0 || number > 9)
            {
                std::cout << "\033[31mWrite only numbers from 0 to 9!\033[0m" << std::endl;
                in_num = "";
            }
        }
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
    }
    while (in_sec == "" && std::cin.eof() == false)
    {
        std::cout << "Enter secret: ";
        std::getline(std::cin, in_sec);
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
    }
    PhoneBook::_new_contact_to_array(in_first, in_last, in_nick, in_num, in_sec);
    return (0);
}

/*
* overwrites first contact with second and so on, when array has
* already 8 contacts and a new one is ADDed.
*/
void    PhoneBook::_replace_oldest_contact(void)
{
    for (int i = 0; i < 7; i++)
    {
        this->persons[i] = this->persons[i + 1];
        this->persons[i].c_index = this->persons[i + 1].c_index - 1;
    }    
}

/*
* ADD: writes contact details into array
* int index will be passed to function adddata in Contact class
* 
* instead if calling function from class Contact like this
* Contact::adddata(index, in_first, in_last, in_nick, in_num, in_sec);
* we can call the same function through the specific instance
* Persons[_num_entries].adddata(index, in_first, in_last, in_nick, in_num, in_sec);
*/
void    PhoneBook::_new_contact_to_array(std::string in_first, std::string in_last, std::string in_nick, std::string in_num, std::string in_sec)
{
    if (this->_num_entries < 7)
    {
        this->_num_entries++;
        persons[_num_entries].adddata(this->_num_entries, in_first, in_last, in_nick, in_num, in_sec);
    }
    else
    {
        std::cout << "\033[31mYour oldest contact got replaced by the new one!\033[0m" << std::endl;
        PhoneBook::_replace_oldest_contact();
        persons[_num_entries].adddata(this->_num_entries, in_first, in_last, in_nick, in_num, in_sec);
    }
}

/*
* if there are saved contacts it displays the extract.
* Then asks for input the index and checks for a valid input. If input invalid, asks to put valid input.
*/
int    PhoneBook::search_data(void)
{   
    if (PhoneBook::_display_extract())
    {
        std::cout << "Write index: ";
        std::getline(std::cin, _user_input);
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            return (-1);
        }
        while (!PhoneBook::_display_data(_user_input))
        {
            if (std::cin.eof() == true)
            {
                std::cout << "" << std::endl;
                std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
                exit (0);
            }
            std::cout << "Write index: ";
            std::getline(std::cin, _user_input);
            if (std::cin.eof() == true)
            {
                std::cout << "" << std::endl;
                std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
                return (-1);
            }
        }
    }
    return (0);
}

/*
* displays the extract of all entries after SEARCH, when min one exists.
* Else it returns false to main.
*/
bool    PhoneBook::_display_extract(void)
{
    if (this->_num_entries >= 0)
    {
        std::cout << "|-------------------------------------------|" << std::endl;
	    std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	    std::cout << "|----------|----------|----------|----------|" << std::endl;
        for (int i = 0; i <= this->_num_entries; i++)
           persons[i].putextract();
    }
    else
    {
        std::cout << "\033[31mNo entries found! Write ADD and add a contact.\033[0m" << std::endl;
        return (false);
    }
    return (true); 
}

/*
* checks if string is bigger than one char. If not
* converts string to int. ATTENTION '- 48' due to ASCII
* displays whole data of one specific entry after index was put in and is valid.
* if not valid recursive process.
*/
bool    PhoneBook::_display_data(std::string _user_input)
{
    int user_index = -5;
    int index;

    if (_user_input.length() > 1)
    {
        std::cout << "\033[31mNo entry found! Write an existing index.\033[0m" << std::endl;
        return (false);
    }
    else
        user_index = int(_user_input[0]) - 48;
    
    index = user_index - 1;
    if (index >= 0 && index <= this->_num_entries)
        persons[index].putdata();
    else
    {
        std::cout << "\033[31mNo entry found! Write an existing index.\033[0m" << std::endl;
        return (false);
    }
    return (true);
}

/*
* user prompt instructions.
*/
void	PhoneBook::show_instruction(void)
{
	std::cout << "\033[36mWelcome!" << std::endl;
    std::cout << "This phonebook can store up to 8 contacts!" << std::endl;
    std::cout << "Enter the command 'ADD', 'SEARCH' or 'EXIT'\033[0m" << std::endl;
    std::cout << "to add a contact, search for a contact or leave the phonebook!\033[0m" << std::endl;
}
