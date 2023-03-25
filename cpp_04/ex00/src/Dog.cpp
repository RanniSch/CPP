/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:42:37 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 08:42:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void): Animal()
{
    this->_type = "Dog";
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Dog::~Dog(void)
{
    std::cout << "Dog destructor for " << this->_type << " called" << std::endl;
}

// Overloaded operator
Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

// member function
void    Dog::makeSound(void)const
{
    std::cout << this->getType() << ": WUFF" << std::endl;
}
