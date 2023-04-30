/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:00:06 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/30 12:17:26 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Default Form"), _signed(false), _signit(75), _executeit(1)
{
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signit, int executeit) : _name(name), _signit(signit), _executeit(executeit)
{
    std::cout << "Form constructor called!" << std::endl;
    try
    {
        if (this->signIt() < 1 || this->executeIt() < 1)
            throw GradeTooHighException();
        else if (this->signIt() > 150 || this->executeIt() > 150)
            throw GradeTooLowException();
    }
    catch (const std::exception &e)
	{
		std::cout << "\033[33mException thrown: \033[0m" << e.what() << std::endl;
	}
}

Form::Form(const Form &copy) : _name(copy._name), _signed(copy._signed), _signit(copy._signit), _executeit(copy._executeit)
{
    std::cout << "Form copy constructor!" << std::endl;
}

Form::~Form(void)
{
    std::cout << "Form: Default destructor!" << std::endl;
}

Form &Form::operator=(Form const &src)
{
    std::cout << "Form: overloaded operator!" << std::endl;
    this->_signed = src._signed;
    return (*this);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool	Form::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	Form::signIt(void) const
{
	return (this->_signit);
}

unsigned int	Form::executeIt(void) const
{
	return (this->_executeit);
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form: Grade is too high, maximum grade achievable: 1");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form: Grade is too low, minimum grade required: 150");
}

std::ostream& operator<<(std::ostream &os, const Form &copy)
{
	os << copy.getName() << ", form grade needed for signature " << copy.getSigned() << ", grade needed for execution " << copy.executeIt() << ", status: " << copy.signIt() << std::endl;
	return (os);
}

void    Form::beSigned(const Bureaucrat &copy)
{
	std::cout << "Attempt to sign the form." << std::endl;
	if(this->_signit >= copy.getGrade() && _signed == false)
		this->_signed = true;
	else if(this->_signit < copy.getGrade()) // was < before
		throw GradeTooHighException(); // function of Form! Was "TooLow" before
	else if(this->_signed == true) 
		std::cout << this->getName() << " is already signed!" << std::endl;

    /*std::cout << "Attempt to sign the form." << std::endl;
	if(this->_signit = copy.getGrade() && _signed == false)
		this->_signed = true;
	else if(this->_signit > copy.getGrade())
		throw GradeTooLowException();
    else if(this->_signit < copy.getGrade()) // or < 1
        throw GradeTooHighException();
	else if(this->_signed == true) 
		std::cout << this->getName() << " is already signed!" << std::endl;*/
}
