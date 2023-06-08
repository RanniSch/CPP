/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:43:53 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "\n\033[32m########## Intern 1: ShrubberyCreationForm ##########\033[0m" << "\n\n";
	Bureaucrat	Tom("Tom", 2);
	Intern	intern_1;
	AForm	*form_1;

	form_1 = intern_1.makeForm("ShrubberyCreationForm", "palm_tree");
	form_1->beSigned(Tom);
	Tom.signForm(*form_1);
	Tom.executeForm(*form_1);


	std::cout << "\n\033[32m########## Intern 2: RobotomyRequestForm ##########\033[0m" << "\n\n";
	Bureaucrat	Jerry("Jerry", 2);
	Intern	intern_2;
	AForm	*form_2;

	form_2 = intern_2.makeForm("RobotomyRequestForm", "palm_tree");
	form_2->beSigned(Jerry);
	Jerry.signForm(*form_2);
	Jerry.executeForm(*form_2);

	std::cout << "\n\033[32m########## Intern 3: PresidentialPardonForm ##########\033[0m" << "\n\n";
	Bureaucrat	Carl("Carl", 2);
	Intern	intern_3;
	AForm	*form_3;

	form_3 = intern_3.makeForm("PresidentialPardonForm", "Ford Perfect");
	form_3->beSigned(Carl);
	Carl.signForm(*form_3);
	Carl.executeForm(*form_3);

	delete form_1;
	delete form_2;
	delete form_3;
	return 0;
}

/*int	main()
{
	std::string					test = "test";
	std::string					fordPrefect = "Ford Prefect";
	std::string					slartibartfast = "Slartibartfast";
	Bureaucrat					Bob("Bob", 150);
	Bureaucrat					Linda("Linda", 4);
	Intern						poorIntern;
	ShrubberyCreationForm		SCF(test);
	RobotomyRequestForm			RRF(fordPrefect);
	PresidentialPardonForm		PPF(slartibartfast);

	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF << "\n";

	std::cout << "\n########################### Intern at work! #####################\n";

	AForm					*form_1;
	AForm					*form_2;
	form_1 = poorIntern.makeForm("ShrubberyCreationForm", "hi");
	form_2 = poorIntern.makeForm("PresidentialPardonForm", "hi");
	Linda.signForm(*form_1);
	Linda.executeForm(*form_2);

	
	Bob.signForm(SCF);
	Linda.signForm(SCF);
	Bob.executeForm(SCF);
	for (int i = Bob.getGrade(); i > 137; i--)
		Bob.increment();
	Bob.executeForm(SCF);

	std::cout << "\n###################### Back to not signing... ##############################\n";
	
	Bob.signForm(RRF);
	Linda.signForm(RRF);
	Bob.signForm(PPF);
	Linda.signForm(PPF);

	std::cout << "\n###################### Linda will handle this ######################\n";

	Linda.executeForm(RRF);
	Linda.executeForm(PPF);
	
	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << SCF;
	std::cout << RRF;
	std::cout << PPF << "\n";
	delete form_1;
	delete form_2;
	return (0);
}*/