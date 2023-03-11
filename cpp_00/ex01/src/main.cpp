/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/11 17:49:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
    
    my_pb.show_instruction();

    while (run)
    {
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            break ;
        }
        std::cout << "\33[35mWrite ADD, SEARCH or EXIT: \33[0m";
        std::cin >> command;  // handle no input!!!
        if (command == "EXIT")
        {
            std::cout << "\033[34mGood Bye!\033[0m" << std::endl;
            //PhoneBook.~PhoneBook(void);
			break ;
        }
        else if (command == "ADD")
        {
            if (my_pb.input_data() == -1)
                break ;
        }
        else if (command == "SEARCH")
            my_pb.search_data();
        //command.clear();    
    }
    if (command != "EXIT" && std::cin.eof() == false)
		std::cout << "\033[34mYou pressed ^D, exiting now. Good Bye.\033[0m" << command << std::endl;
    return (0);
    /*while (run && std::getline(std::cin, command))
    {

        //std::cout << "Write ADD, SEARCH or EXIT: ";
        if (command.compare("ADD") == 0)
            my_pb.input_data();
        else if (command.compare("SEARCH") == 0)
        {
            if (my_pb.display_extract())
            {
                std::cout << "Write index: ";
                std::cin >> user_index;
                my_pb.display_data(user_index);
                std::cin >> user_index;
                //while (!my_pb.display_data(user_index))
                //    std::cin >> user_index;
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
        else if (std::cin.eof() == true)
        {
            std::cout << "You pressed ^D. Exiting phonebook!" << std::endl;
            exit (0);
        }
        command.clear();
		//my_pb.show_instruction();
		//std::cout << "\033[33m$>\033[0m";    
    }*/
}
