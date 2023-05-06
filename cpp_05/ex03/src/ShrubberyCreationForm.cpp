/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:24:39 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/06 10:28:33 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Default", 145, 137)
{
	this->setForm("ShrubberyCreationForm");
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, 145, 137)
{
	this->setForm("ShrubberyCreationForm");
    std::cout << "ShrubberyCreationForm constructor for '" << target << "' called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getName(), 145, 137)
{
	std::cout << "ShrubberyCreationForm copy constructor." << std::endl;
	
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "ShrubberyCreationForm destructor." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm assignement operator overload." << std::endl;
	this->_target = src._target;
	return (*this);
}

/*
* Executes for Bureaucrats with grades: sign 145, exec 137.
* Creates a file <target>_shrubbery in the working directory
* and writes ASCII trees inside it.
*/
void	ShrubberyCreationForm::execute(const Bureaucrat &obj) const
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
		    std::string	name;
		    std::string	line; // nötig?
		    name = this->getName();
        
		    name.append("_shrubbery");
		    std::ofstream execFile(name.c_str());
		    execFile << "       _-_" << std::endl;
		    execFile << "   / ~~   ~~ \\" << std::endl;
		    execFile << " /~~         ~~\\" << std::endl;
		    execFile << "{               }" << std::endl;
		    execFile << " *  _-     -_  *" << std::endl;
		    execFile << "      \\\\ //  " << std::endl;
		    execFile << "       | |    " << std::endl;
		    execFile << "       | |     " << std::endl;
		    execFile << "       | |     " << std::endl;
		    execFile << "      // \\\\" << std::endl; 
		    execFile.close();
		    std::cout << obj.getName() << " successfully executed file " << name << "!" << std::endl;
		}
    }
    catch (const std::exception &e)
	{
		std::cout << "\033[34mException thrown: \033[0m" << 
		obj.getName() << " couldn't execute " << this->getName() << " because " << e.what() << std::endl;
	}
}

AForm *ShrubberyCreationForm::clone(std::string target) const
{
	return (new ShrubberyCreationForm(target));
}
