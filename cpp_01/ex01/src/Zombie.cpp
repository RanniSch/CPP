/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:16:13 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 09:16:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
    //std::cout << "Zombie born" << std::endl;
    return;
}

Zombie::~Zombie(void)
{
    std::cout << this->_name << " just died" << std::endl;
    return;
}

void    Zombie::announce(void)
{
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name)
{
	this->_name = name;
}
