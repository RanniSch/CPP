/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:10:12 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 21:16:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_nameB = name;
    this->_is_armed = false;
    //std::cout << "HumanB called" << std::endl;
    return;
}

HumanB::~HumanB(void)
{
    //std::cout << "HumanB destroyed" << std::endl;
    return;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->_weapon = &weapon;
    this->_is_armed = true;
    this->_weapon->getType();
}

void HumanB::attack(void)
{
    if (this->_is_armed)
    {
        std::cout << this->_nameB << " attacks with their";
        std::cout << this->_weapon->getType() << std::endl;
    }
    else
        std::cout << "boxing session" << std::endl;
}
