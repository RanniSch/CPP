/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 15:18:24 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/*
* std Namespace is libary where also string is defined
*/
int main (void) 
{ 
    Contact person[3];  // create instances, also quasi 8 Telefonbucheinträge werden erstellt

    for (int i = 0; i < 3; i++)
    {
        person[i].getdata();
    }
    for (int j = 0; j < 3; j++)
        person[j].putdata();

    return (0);
}
