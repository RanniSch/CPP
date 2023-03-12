/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:29:46 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 21:50:47 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string);
void    randomChump(std::string name);

/*
* First instance of the class Zombie is called "Peter" and the second "Hans".
* The constructor of the instance saves the name into the private variable.
*
* *newZombie function is a heap, randomChump is a stack!
* Heap is usefull when I know when dieing should be done. Stack -> dieing automatically when class not used anymore.
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*/
int main(void)
{
    Zombie  *zombie[4];

    zombie[0] = newZombie("Peter");
    zombie[0]->announce();
    zombie[1] = newZombie("Hans");
    zombie[1]->announce();
    delete zombie[0];
    delete zombie[1];
    zombie[2] = newZombie("Elsi");
    zombie[2]->announce();
    zombie[3] = newZombie("Doerte");
    zombie[3]->announce();
    delete zombie[2];
    delete zombie[3];

    randomChump("green1");
    randomChump("green2");
    randomChump("green3");
    randomChump("green4");
    return (0);
}
