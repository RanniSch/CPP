/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 14:17:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
* std Namespace is libary where also string is defined
*/
int main (void) 
{
    std::string vorname_1 = "Tim";
    std::string nachname_1 = "Beinert";
    std::string vorname_2 = "Ranja";
    std::string nachname_2 = "Schlotte";
    //char    vorname_1 = 'T';
    //char    nachname_1 = 'B';
    //char    vorname_2 = 'R';
    //char    nachname_2 = 'S';

    Contact person1(vorname_1, nachname_1);
    Contact person2(vorname_2, nachname_2);

    person1.getdata();
    person1.putdata();

    return (0);
}
