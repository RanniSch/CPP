/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:48:59 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/30 14:34:34 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
* Constructors 
*
* Inherits (manipulates) the constructors and destructors from ClapTrap,
* is created and destroyed before ClapTrap.
*/
ScavTrap::ScavTrap(void): ClapTrap()
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardingGate = false;
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    this->_guardingGate = false;
    std::cout << "ScavTrap name set to " << this->_name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy)
{
    this->_guardingGate = copy._guardingGate;
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

// Destructor
ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor for " << this->_name << " called!" << std::endl;
    return;
}

// Overloaded operator
ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}

// member functions
void ScavTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ScavTrap " << this->_name << " attacks " << target;
        std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }  
    else if (this->_energyPoints == 0)
        std::cout << "ScavTrap " << this->_name << " ran out of energy! " << target << " is lucky!" << std::endl;
    else
        std::cout << "ScavTrap " << this->_name << " ran out of hit points! " << target << " is lucky!" << std::endl;
}

/*
* prints out message that ScavTrap is in Gate keeper mode.
*/
void ScavTrap::guardGate(void)
{
    if (this->_guardingGate == false)
    {
        this->_guardingGate = true;
        std::cout << "ScavTrap is now in Gate keeper mode for " << this->_name << std::endl;
    }
    else
        std::cout << "ScavTrap is already in Gate keeper mode" << std::endl;
}
