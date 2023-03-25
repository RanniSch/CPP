/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:27:05 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 08:42:59 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal(void): _type("default")
{
    std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Animal::~Animal(void)
{
    std::cout << "Animal destructor for " << this->_type << " called" << std::endl;
}

// Overloaded operator
Animal &Animal::operator=(const Animal &src)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;
    return (*this);
}

// member function
void Animal::makeSound(void)const
{
    std::cout << this->getType() << ": this animal doesn't make noises" << std::endl;
}

// Getter
std::string Animal::getType(void)const
{
    return (this->_type);
}
