/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:52:53 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:59:19 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

// Constructors
Character::Character()
{

}

Character::Character(const std::string &name): _name(name), _nEquiped(0)
{
	for (int i = 0; i < Character::kInventorySize; i++)
    	this->_inventory[i] = NULL;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

// Overloaded operators
Character::~Character()
{
	for (int i = 0; i < this->_nEquiped; i++)
        delete (this->_inventory[i]);
}

Character &Character::operator=(const Character &src)
{
	this->_name = src._name;
	this->_nEquiped = src._nEquiped;
	for (int i = 0; i < Character::kInventorySize; i++) {
		//this->_inventory[i] = src._inventory[i]; // shallow copy
		this->_inventory[i] = src._inventory[i]->clone(); // deep copy
	}
	return (*this);
}

// Public member functions
const std::string& Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria *m)
{
	if (this->_nEquiped < Character::kInventorySize)
    {
		this->_inventory[this->_nEquiped] = m; // shallow copy
		this->_nEquiped++;
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < this->_nEquiped)
    {
		delete (this->_inventory[idx]);
		int i = idx;
		for (; i < this->_nEquiped - 1; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[i] = NULL;
		--(this->_nEquiped);
	}
}

void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < this->_nEquiped)
		this->_inventory[idx]->use(target);
    else
		std::cout << "can't use materia, index " << idx << " is empty" << std::endl;
}
