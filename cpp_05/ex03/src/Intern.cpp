/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:35:17 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 10:10:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &copy)
{
	copy.hm();
    std::cout << "Intern copy constructor." << std::endl;
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor." << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
    std::cout << "Intern assignement operator overload." << std::endl;
	src.hm();
	return (*this);
}

void	Intern::hm(void) const
{
	std::cout << " ";
}

/*
* Mallocs new AForm form and returns pointer to it.
* Needs to be deleted when done using!
*/
AForm	*Intern::makeForm(std::string const name, std::string const target)
{
	std::string		array[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm			*form;
	int				i;

	for (i = 0; i < 3; i++)
		if (name == array[i])
			break;
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
	}
    try
	{
		if (form == NULL)
			throw Intern::InvalidFormException();
		std::cout << "Intern creates form: " << name << "!" << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << "Intern wasn't able to create a " << name << ", because " << e.what() << std::endl;
	}
	return (form);
}

const char *Intern::InvalidFormException::what() const throw()
{
	return ("Form doesn't exist!");
}
