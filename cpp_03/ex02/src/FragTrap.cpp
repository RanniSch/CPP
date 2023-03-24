/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:09:59 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 08:56:02 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
* Constructors
* Inherits (manipulates) the constructors and destructors from ClapTrap,
* is created and destroyed before ClapTrap.
*/
FragTrap::FragTrap(void): ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    std::cout << "FragTrap name set to " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Destructor
FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor for " << this->_name << "called!" << std::endl;
}

// Overloaded operator
FragTrap &FragTrap::operator=(const FragTrap &src)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}

/*
* member functions
* function displays a positive high fives request on the standard output.
*/
void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_name << ": Wanna have a high five? WHAAAAM *+0+* here you go!" << std::endl;
}
