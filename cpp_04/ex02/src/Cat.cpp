/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:47:23 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 16:27:38 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat(void): Animal()
{
    std::cout << "Cat constructor called" << std::endl;
    this->_type = "Cat";
    this->_brain = new Brain();
    if (this->_brain == NULL)
    {
        std::cout << "Brain allocation failed" << std::endl;
        exit(1);
    }
}

Cat::Cat(const Cat &copy): Animal(copy)
{
    std::cout << "Cat copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Cat::~Cat(void)
{
    delete(this->_brain);
    std::cout << "Cat destructor for " << this->_type << " called" << std::endl;
}

// Overloaded Operators
Cat &Cat::operator=(const Cat &src)
{
    std::cout << "Cat assignment operator called" << std::endl;
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
void    Cat::makeSound(void)const
{
    std::cout << this->getType() << ": MIAU" << std::endl;
}

// Getter
void	Cat::getIdeas(size_t i)const
{
	std::cout << "\tIdea " << i << " of the Cat is: \"" << this->_brain->getIdea(i) << "\" at the address " << this->_brain->getIdeaAddress(i) << std::endl;
}

// Setter
void	Cat::setIdeas(size_t i, std::string idea)
{
		this->_brain->setIdea(i, idea);
}
