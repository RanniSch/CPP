/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:10:08 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/29 15:46:54 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon):_weapon(weapon)
{
    this->_nameA = name;
    this->_weapon.getType();
    //std::cout << "HumanA called" << std::endl;
    return;
}

HumanA::~HumanA(void)
{
    //std::cout << "HumanA destroyed" << std::endl;
    return;
}

void HumanA::attack(void)
{
    std::cout << this->_nameA << " attacks with their ";
    std::cout << this->_weapon.getType() << std::endl;
}
