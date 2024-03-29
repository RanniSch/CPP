/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:53 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/23 10:08:10 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap name set to " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copy;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "ClapTrap destructor for " << _name << " called!" << std::endl;
    return;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    this->_name = src._name;
    this->_hitPoints = src._hitPoints;
    this->_energyPoints = src._energyPoints;
    this->_attackDamage = src._attackDamage;

    return (*this);
}


void ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target;
        std::cout << " causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoints--;
    }  
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " ran out of energy! " << target << " is lucky!" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " ran out of hit points! " << target << " is lucky!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoints > amount)
        this->_hitPoints = this->_hitPoints - amount;
    else if (this->_hitPoints > 0)
        this->_hitPoints = 0;
    else
    {
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " was attacked and lost " << amount;
    std::cout << " hit points! There are " << this->_hitPoints << " hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0 && this->_hitPoints > 0)
    {
        this->_hitPoints = this->_hitPoints + amount;
        this->_energyPoints--;
        std::cout << "ClapTrap " << this->_name << " repairs itself by " << amount << " and has now ";
        std::cout << this->_hitPoints << " Hit points and " << this->_energyPoints << " Energy points!" << std::endl;

    }
    else if (this->_energyPoints == 0)
        std::cout << "ClapTrap " << this->_name << " ran out of energy!" << std::endl;
    else if (this->_hitPoints == 0)
        std::cout << "ClapTrap " << this->_name << " ran out of hit points!" << std::endl;
}

void	print_table(void) 
{
	std::cout << "---------------------------------------" << std::endl;
	std::cout << std::left << std::setw(10) << "NAME";
	std::cout << std::left << std::setw(10) << "HP";
	std::cout << std::left << std::setw(10) << "ENERGY";
	std::cout << std::left << std::setw(10) << "ATTACK" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}

void	ClapTrap::status(void) const 
{
    std::cout << std::left << std::setw(10) << this->_name;
	this->_hitPoints == 0 ? std::cout << std::left << std::setw(10) << this->_hitPoints :
		std::cout << std::left << std::setw(10) << this->_hitPoints;
	this->_energyPoints == 0 ? std::cout << std::left << std::setw(10) << this->_energyPoints :
		std::cout << std::left << std::setw(10) << this->_energyPoints;
	std::cout << std::left << std::setw(10) << this->_attackDamage << std::endl;
	std::cout << "---------------------------------------" << std::endl;
}
