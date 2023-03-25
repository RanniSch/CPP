/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:43:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:51:06 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat(void): WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor for " << this->_type << " called" << std::endl;
}

// Overloaded Operators
WrongCat &WrongCat::operator=(const WrongCat &src)
{
    std::cout << "WrongCat assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

// Member function
void    WrongCat::makeSound(void)const
{
    std::cout << this->getType() << ": WUFF" << std::endl;
    //std::cout << this->getType() << ": **WrongCat sounds**" << std::endl;
}
