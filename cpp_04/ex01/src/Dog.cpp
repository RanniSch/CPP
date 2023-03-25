/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:42:37 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:45:54 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog(void): Animal()
{
    std::cout << "Dog constructor called" << std::endl;
    this->_type = "Dog";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "Brain allocation failed" << std::endl;
        exit(1);
    }
}

Dog::Dog(const Dog &copy): Animal(copy)
{
    std::cout << "Dog copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Dog::~Dog(void)
{
    delete(this->_brain);
    std::cout << "Dog destructor for " << this->_type << " called" << std::endl;
}

// Overloaded operator
Dog &Dog::operator=(const Dog &src)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    this->_type = src._type;

    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "Brain allocation failed" << std::endl;
        exit(1);
    }
    *this->_brain = *src._brain;
    return (*this);
}

// member function
void    Dog::makeSound(void)const
{
    std::cout << this->getType() << ": WUFF" << std::endl;
}

// Getter
void	Dog::getIdeas(size_t i)const
{
	std::cout << "\tIdea " << i << " of the Dog is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setter
void	Dog::setIdeas(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}
