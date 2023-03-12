/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:29:46 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 21:07:03 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *newZombie(std::string);

/*
* First instance of the class Zombie is called "Peter" and the second "Hans".
* The constructor of the instance saves the name into the private variable.
*
* *newZombie function is a stack, randomChump is a heap!
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*/
int main(void)
{
    Zombie  *Zombie[2];

    Zombie[0] = newZombie("Peter");
    Zombie[0]->announce();
    Zombie[1] = newZombie("Hans");
    Zombie[1]->announce();
    delete Zombie[0];
    delete Zombie[1];

    
    return (0);
}
