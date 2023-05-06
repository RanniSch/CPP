/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:53:58 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/06 10:29:10 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Default", 72, 45)
{
	this->setForm("RobotomyRequestForm");
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	this->setForm("RobotomyRequestForm");
    std::cout << "RobotomyRequestForm constructor for '" << target << "' called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getName(), 72, 45)
{
	std::cout << "RobotomyRequestForm copy constructor." << std::endl;
	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm destructor." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm assignement operator overload." << std::endl;
	this->_target = src._target;
	return (*this);
}

/*
* Executes for Bureaucrats with grades: sign 72, exec 45.
* The time() function returns the current calendar time as an object of type time_t.
* It is defined in the ctime header file.
* Success for even number for timex, else failure.
*/
void	RobotomyRequestForm::execute(const Bureaucrat &obj) const
{
    std::cout << obj.getName() << " attempts to execute " << this->getName() << "." << std::endl;
	try
    {
		if (this->getSigned() == false)
		    throw NotSignedYet();
	    else if (obj.getGrade() > this->executeIt())
		    throw GradeTooHighException();
	    else
        {
            time_t timex;
            time(&timex);
            //std::cout << "\033[31mTime \033[0m" << timex << std::endl;
            std::cout << "\033[31m*** Brrr brrr ~~~> drilling noises ---*\033[0m" << std::endl;
            if (timex % 2 == 0)
                std::cout << obj.getName() << " has been successfully robotomized '50%' of the time by " << this->getName() << "!" << std::endl;
            else
                std::cout << "Robotomy has failed for " << obj.getName() << "!" << std::endl;
        }
    }
    catch (const std::exception &e)
	{
		std::cout << "\033[34mException thrown: \033[0m" << 
		obj.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}

AForm *RobotomyRequestForm::clone(std::string target) const
{
	return (new RobotomyRequestForm(target));
}
