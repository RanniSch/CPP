/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:41:18 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 19:12:19 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

// Constructors
WrongAnimal::WrongAnimal(void): _type("wrong_default")
{
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor for " << this->_type << " called" << std::endl;
}

// Overloaded operator
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &src)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    //if (this == &src)
    //    return (*this);
    this->_type = src._type;
    return (*this);
}

// member function
void WrongAnimal::makeSound(void)const
{
    std::cout << this->getType() << ": this WrongAnimal doesn't make noises" << std::endl;
}

// Getter
std::string WrongAnimal::getType(void)const
{
    return (this->_type);
}
