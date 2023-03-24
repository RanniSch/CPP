/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:47:23 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 19:12:13 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

// Constructors
Cat::Cat(void): Animal()
{
    this->_type = "Cat";
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Cat::~Cat(void)
{
    std::cout << "Cat destructor for " << this->_type << " called" << std::endl;
}

// Overloaded Operators
Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat assignment operator called" << std::endl;
    //if (this == &src)
    //    return (*this);
    this->_type = src._type;
    return (*this);
}

void    Cat::makeSound(void)const
{
    std::cout << this->getType() << ": MIAU" << std::endl;
}
