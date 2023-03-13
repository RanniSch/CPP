/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 07:23:47 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 09:11:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
* HEAP
* the constructor of Zombie class turns raw storage into a Horde of initialized objects.
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*
* horde is a pointer that points to the horde of Zombie. Zombie is the class and *horde the variable like char *ptr.
* new Zombie(N) erstellt neue Instanzen an Klassen mit dem Parameter "N" for the constructor.
* Then each Instanz gehts the name.
* 
* Zombies werden irgendwo im gesamten PC gespeichert. In Zeile 30 weiß das Programm noch nicht, wie viel memory es braucht,
* erst in Zeile 33.
* After initialisate the zombies and give them a name (line 35).
* Pointer points to the instances of class Zombie.
*/
Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i].setName(name);
    return (horde);
}
