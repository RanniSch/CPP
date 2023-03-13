/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:10:02 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 21:09:51 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->setType(type);
    //std::cout << "Weapon constructor called" << std::endl;
    return;
}

Weapon::~Weapon(void)
{
    //std::cout << "Weapon destroyed" << std::endl;
    return;
}

const std::string& Weapon::getType(void)
{
    const std::string &type = this->_type;
    return (type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
