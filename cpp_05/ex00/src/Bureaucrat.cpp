/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:27:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/29 16:56:25 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade) : _name(name)
{
    std::cout << this->getName() << " tries to be a Bureaucrat!" << std::endl;
    try
    {
        if (grade < 1)
            throw GradeTooHighException();
        else if (grade > 150)
            throw GradeTooLowException();
        else
        {
            this->_grade = grade;
            std::cout << "Bureaucrat " << this->getName() << " constructed with grade " << this->getGrade() << "!" << std::endl;
        }
    }
    catch (const std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : _name(copy.getName())
{
	std::cout << "Bureaucrat: Copy constructor called." << std::endl;
	this->_grade = copy.getGrade();
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat: Default destructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
    std::cout << "Bureaucrat: overloaded operator called." << std::endl;
    this->_grade = src.getGrade();
    return *this;
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

unsigned int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::increment()
{
	std::cout << this->getName() << " tries to increment grade." << std::endl;
    try
	{
		if ((this->getGrade() - 1) < 1)
			throw GradeTooHighException();
		else
        {
			this->_grade = this->getGrade() - 1;
            std::cout << "Decremented grade to " << this->getGrade() << std::endl;
        }
    }
	catch(const std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrement()
{
	std::cout << this->getName() << " tries to decrement grade." << std::endl;
	try
	{
		if ((this->getGrade() + 1) > 150)
			throw GradeTooLowException();
		else if ((this->getGrade()) < 1)
			throw GradeTooHighException();
		else
		{
			this->_grade = this->getGrade() + 1;
			std::cout << "Decremented grade to " << this->getGrade() << std::endl;
		}
	}
	catch(const std::exception &e)
	{
		std::cout << "Exception thrown: " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Bureaucrat's grade is too high grade is not valid!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Bureaucrat's grade is too low grade is not valid!");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &copy)
{
	return (os << copy.getName() << ", bureaucrat grade " << copy.getGrade() << std::endl);
}
