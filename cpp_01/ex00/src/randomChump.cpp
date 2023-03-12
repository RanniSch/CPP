/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:09:36 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 21:49:04 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
* STACK
* Wenn Prozess beendet, löscht der destructor automatisch die Klassen, die erstellt wurden.
* Constructor wird automatisch bei Klassenerstellung aufgerufen.
* Zombie is the class (like int or char) and zombie is the object variable with the input parameter
* "name" for the constructor.
*/
void    randomChump(std::string name)
{
    Zombie zombie(name);
    zombie.announce();
}
