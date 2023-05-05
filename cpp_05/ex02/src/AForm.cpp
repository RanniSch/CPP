/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:00:06 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/30 13:54:51 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Default AForm"), _signed(false), _signit(75), _executeit(1), _formName("AForm")
{
    std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signit, int executeit) : _name(name), _signit(signit), _executeit(executeit)
{
    std::cout << "AForm constructor called!" << std::endl;
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

AForm::AForm(const AForm &copy) : _name(copy._name), _signed(copy._signed), _signit(copy._signit), _executeit(copy._executeit), _formName("AForm")
{
    std::cout << "AForm copy constructor!" << std::endl;
}

AForm::~AForm(void)
{
    std::cout << "AForm: Default destructor!" << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
    std::cout << "AForm: overloaded operator!" << std::endl;
    //this->_signed = src._signed;
    this->_signed = src.getSigned();
    return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool	AForm::getSigned(void) const
{
	return (this->_signed);
}

unsigned int	AForm::signIt(void) const
{
	return (this->_signit);
}

unsigned int	AForm::executeIt(void) const
{
	return (this->_executeit);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form's grade is too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form's grade is too low!");
}

const char *AForm::NotSignedYet::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream& operator<<(std::ostream &os, const AForm &copy)
{
	os << "Target = " << copy.getName()
    << " -> Bureaucrat grade needed for signature: " << copy.signIt()
    << ", grade needed for execution " << copy.executeIt()
    << ", signing status: " << copy.getSigned() << std::endl;
	return (os);
}

void	AForm::setForm(std::string typeForm)
{
	this->_formName = typeForm;
}

void    AForm::beSigned(const Bureaucrat &obj)
{
	std::cout << obj.getName() << " attempts to sign the AForm " << this->getName() << "." << std::endl;

    try
    {
        if (this->signIt() < 1 || this->executeIt() < 1)
            throw GradeTooHighException();
        else if (this->signIt() > 150 || this->executeIt() > 150)
            throw GradeTooLowException();
        else if(this->_signit >= obj.getGrade() && _signed == false)
        {
		    this->_signed = true;
            std::cout << obj.getName() << " signed " << this->getName() << "!" << std::endl;
        }
	    else if(this->_signit < obj.getGrade()) // was < before
		    throw GradeTooHighException(); // function of AForm! Was "TooLow" before
	    else if(this->_signed == true) 
		    std::cout << this->getName() << " is already signed!" << std::endl;
    }
    catch (const std::exception &e)
	{
		std::cout << "\033[33mException thrown: \033[0m" << e.what() << std::endl;
	}

	/*if (this->_signit <= 150 && this->_signit >= 1)
    {
        if(this->_signit >= copy.getGrade() && _signed == false)
        {
		    this->_signed = true;
            std::cout << this->getName() << " got signed!" << std::endl;
        }
	    else if(this->_signit < copy.getGrade()) // was < before
		    throw GradeTooHighException(); // function of AForm! Was "TooLow" before
	    else if(this->_signed == true) 
		    std::cout << this->getName() << " is already signed!" << std::endl;
    }
    else
        std::cout << this->getName() << " cannot be signed as its grade is invalid!" << std::endl;*/
}

std::string	AForm::getFormType()const
{
	return (this->_formName);
}

void	AForm::execute(const Bureaucrat &executor)const
{
	try
    {
        if (this->getSigned() == false)
	    	throw NotSignedYet();
	    else if (this->signIt() < executor.getGrade())
	    	throw GradeTooHighException();
	    else
        {
	    	std::cout << this->getName() << " is being executed !" << std::endl;
	    }
    }
    catch (const std::exception &e)
    {
        std::cout << "\033[33mException thrown: \033[0m" << e.what() << std::endl;
    }
}