/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 13:29:48 by rschlott         ###   ########.fr       */
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

    std::cout << "\33[35mWrite ADD, SEARCH or EXIT: \33[0m";
    while (run)
    {
        if (std::cin.eof() == true)
        {
            std::cout << "" << std::endl;
            std::cout << "\033[34mYou pressed ^D. Exiting phonebook!\033[0m" << std::endl;
            break ;
        }
        std::getline(std::cin, command);
        if ((command == "" && std::cin.eof() == false) || (command != "EXIT" && command != "ADD" && command != "SEARCH"))
            std::cout << "\33[35mWrite ADD, SEARCH or EXIT: \33[0m";
        if (command == "EXIT")
        {
            std::cout << "\033[34mGood Bye!\033[0m" << std::endl;
			break ;
        }
        else if (command == "ADD")
        {
            if (my_pb.input_data() == -1)
                break ;
            std::cout << "\33[35mWrite ADD, SEARCH or EXIT: \33[0m";
        }
        else if (command == "SEARCH")
        {
            if (my_pb.search_data() == -1)
                break;
            std::cout << "\33[35mWrite ADD, SEARCH or EXIT: \33[0m";
        }  
    }
    if (command != "EXIT" && std::cin.eof() == false)
		std::cout << "\033[34mYou pressed ^D, exiting now. Good Bye.\033[0m" << command << std::endl;
    return (0);
}
