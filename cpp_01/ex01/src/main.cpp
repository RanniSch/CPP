/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:29:46 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 09:15:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#include <string>
#include <iostream>

Zombie  *zombieHorde(int N, std::string name);

/*
* First instance of the class Zombie is called "Peter" and the second "Hans".
* The constructor of the instance saves the name into the private variable.
*
* *newZombie function is a heap (dynamisch), randomChump is a stack (automatisch)!
* Heap kann dynamisch während der Ausführung wachsen, bis der komplette PC voll ist. 
* Stack ist wie ein Array und vorgegeben, wie viele Einträge er hat.
* Heap is usefull when I know when dieing should be done. Stack -> dieing automatically when class not used anymore.
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*/
int main(void)
{
    int N;
    Zombie  *horde;
    std::string name;
    std::string n;

   
    std::cout << "Number of horde (1-9): ";
    std::cin >> n;
    N = int(n[0]) - 48;
    //N = 13;

    name = "Peter";
    horde = zombieHorde(N, name);
    std::cout << "Horde: " << horde << std::endl;
    for (int i = 0; i < N; i++)
    {
        horde[i].announce();
    }
    delete[] horde;
    return (0);
}
