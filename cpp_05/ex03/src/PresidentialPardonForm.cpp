/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:04:59 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:21:34 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Default", 25, 5)
{
	this->setForm("PresidentialPardonForm");
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	this->setForm("PresidentialPardonForm");
    std::cout << "PresidentialPardonForm constructor for '" << target << "' called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getName(), 25, 5)
{
	std::cout << "PresidentialPardonForm copy constructor." << std::endl;
	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm destructor." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm assignement operator overload." << std::endl;
	this->_target = src._target;
	return (*this);
}

/*
* Execute for Bureaucrats with grades: sign 25, exec 5.
* Informs that <target> has been pardoned by Zaphod Beeblebrox.
*/
void	PresidentialPardonForm::execute(const Bureaucrat &obj) const
{
    std::cout << obj.getName() << " attempts to execute " << this->getName() << "." << std::endl;
	try
    {
		if (this->getSigned() == false)
		    throw NotSignedYet();
	    else if (obj.getGrade() > this->executeIt())
		    throw GradeTooHighException();
	    else
            std::cout << "\033[33m" << obj.getName() << " has been pardoned by Zaphod Beeblebrox! (File: " << this->getName() << ")\033[0m" << std::endl;
    }
    catch (const std::exception &e)
	{
		std::cout << "\033[34mException thrown: \033[0m" << 
		obj.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}

AForm *PresidentialPardonForm::clone(std::string target) const
{
	return (new PresidentialPardonForm(target));
}