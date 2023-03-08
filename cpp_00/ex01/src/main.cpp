/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 08:11:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 10:16:23 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

int main (void) 
{
    //char    vorname_1[] = "Tim";
    //char    nachname_1[] = "Beinert";
    //char    vorname_2[] = "Ranja";
    //char    nachname_2[] = "Schlotte";
    char    vorname_1 = 'T';
    char    nachname_1 = 'B';
    char    vorname_2 = 'R';
    char    nachname_2 = 'S';

    Contact person1(vorname_1, nachname_1);
    Contact person2(vorname_2, nachname_2);

    return (0);
}
