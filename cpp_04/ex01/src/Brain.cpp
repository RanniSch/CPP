/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:12:10 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:58:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain(void)
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copy;
}

// Destructor
Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
}

/*
* Overloaded operator
*
* In Deep copy, an object is created by copying data of all variables, and it also allocates
* similar memory resources with the same value to the object. In order to perform Deep copy,
* we need to explicitly define the copy constructor and assign dynamic memory as well, if required.
* Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
*/
Brain &Brain::operator=(const Brain &src)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this == &src)
        return (*this);
    
    for (int i = 0; i < 100; i++)
    {
        if (src._ideas[i].length() > 0)
            this->setIdea(i, src.getIdea(i));
    }
    return (*this);
}

// Getter
const std::string Brain::getIdea(size_t i)const
{
    if (i < 100)
        return (this->_ideas[i]);
    else
        return ("vanished. There are maximum 100 ideas per brain");
}

const std::string *Brain::getIdeaAddress(size_t i)const
{
    if (i < 100)
    {
        const std::string   &stringAdr = this->_ideas[i];
        return (&stringAdr);
    }
    else
        return (NULL);
}

// Setter
void Brain::setIdea(size_t i, std::string idea)
{
    if (i < 100)
        this->_ideas[i] = idea;
    else
        std::cout << "Too many ideas set. There are maximum 100 ideas per brain" << std::endl;
}
