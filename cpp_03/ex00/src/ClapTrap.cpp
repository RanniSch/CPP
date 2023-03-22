/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:53 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/22 08:48:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
    return;
}

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "name set" << std::endl;
    this->_name = name;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "Copy assignment operator called" << std::endl;
    ?
}


void attack(const std::string &target)
{
    --this->_energyPoints;
    if (this->_energyPoints >= 0)
        std::cout << "ClapTrap " << this->_name << " attacks" << target;
    else
    {
        std::cout << "ClapTrap " << this->_name << " ran out of energy!" << std::endl;
        exit (0);
    }
}

void takeDamage(unsigned int amount)
{
    this->_hitPoints = this->_hitPoints - amount;
    this->_attackDamage = amount;
    std::cout << "causing" << this->_attackDamage << "points of damage!" << std::endl;
    if (this->_hitPoints <= 0)
    {
        std::cout << "Target has no Hit points left!" << std::endl;
        exit (0);
    }
}

void beRepaired(unsigned int amount)
{
    this->_hitPoints = this->_hitPoints + amount;
    --this->_energyPoints;
    if (this->_energyPoints >= 0)
    {
        std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " and has now ";
        std::cout << this->_hitPoints << " Hit points and " << this->_energyPoints << " Energy points!" << std::endl;
    }
    else
    {
        std::cout << "ClapTrap " << this->_name << " ran out of energy!" << std::endl;
        exit (0);
    }
}
