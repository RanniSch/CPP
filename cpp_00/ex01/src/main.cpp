/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 11:46:09 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
* std Namespace is libary where also string is defined
*/
int main (void) 
{
    for (int i = 0; i < 3; i++)
    {
        person[i].getdata();
    }
    for (int j = 0; j < 3; j++)
        person[j].putdata();

    return (0);
}


/*
ADD

PhoneBook::new_contact_to_array;

void    input_data(void)
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

SEARCH

PhoneBook::display_extract(void);

enter index number --> int user_index;
PhoneBook::display_data(int user_index);

*/
