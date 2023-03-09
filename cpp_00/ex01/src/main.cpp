/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 13:33:18 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <stdlib.h>

/*
* std Namespace is libary where also string is defined
* running main with getline(cin, command): reads an entire line and returns num of
* chars read, incl delimiter char, excl terminating null byte ('\0') on success.
* 
* compare(): public member function of string class, which compares the value of 
* the string object to the sequence of characters specified by its arguments.
*
* bool eof() const: public member fct. Returns true if the eofbit error state flag
* is set for the stream. Flag is set by all standard input operations when 
* End-of-File is reached in the sequence associated with the stream.
*/
int main (void) 
{
    PhoneBook my_pb;
    bool run = true;
    std::string command;
    int user_index;
    
    my_pb.show_instruction();
    //std::cout << "\033[33m$>\033[0m";

    while (run && std::getline(std::cin, command))
    {
        if (std::cin.eof() == true)
        {
            std::cout << "You pressed ^D. Exiting phonebook!" << std::endl;
            exit (0);
        }
        else if (command.compare("ADD") == 0)
            my_pb.input_data();
        else if (command.compare("SEARCH") == 0)
        {
            if (my_pb.display_extract())
            {
                std::cout << "Write index: ";
                std::cin >> user_index;
                while (!my_pb.display_data(user_index))
                    std::cin >> user_index;
            }   
        }
        else if (command.compare("EXIT") == 0)
        {
            //std::cout << "\033[34mGood Bye.\033[0m" << std::endl;
            std::cout << "Good Bye!" << std::endl;
			run = false;
            //PhoneBook.~PhoneBook(void);
			continue ;
        }
        else
            std::cout << "Wrong input!" << std::endl;
        command.clear();
		my_pb.show_instruction();
		//std::cout << "\033[33m$>\033[0m";    
    }
    /*if (run)
	{
		std::cout << "You pressed ^D, exiting now." << command << std::endl
		<< "\033[34mHope i served you well. Good Bye.\033[0m" << std::endl;
	}*/
    return (0);
}
