/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:52:31 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 21:06:23 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
* the constructor of Zombie class turns raw storage into an initialized object.
*
* When new is used to allocate memory, the object's constructor is called after the memory is allocated.
* Use the delete operator to deallocate the memory allocated by the new operator.
*/

Zombie *newZombie(std::string name) 
{
	Zombie *ptr = new Zombie(name);
    return (ptr);
}
