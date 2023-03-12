/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:52:31 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 21:48:47 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
* HEAP
* the constructor of Zombie class turns raw storage into an initialized object.
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*
* Zombie is a pointer that points to the name of the Zombie. Zombie is the class and *ptr the variable like char *ptr.
* new Zombie(name) erstellt eine neue Instanz der Klasse mit dem Parameter "name" for the constructor.
*/

Zombie *newZombie(std::string name) 
{
	Zombie *ptr = new Zombie(name);
    return (ptr);
}
