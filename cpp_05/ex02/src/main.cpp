/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/05 06:16:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
//#include "RobotomyRequestForm.hpp"
//#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		ShrubberyCreationForm	test0;
		ShrubberyCreationForm	test1("Shrubb");
		//std::cout << test0;
		//std::cout << test1;
		//RobotomyRequestForm		test2("Robotomy");
		//PresidentialPardonForm	test3("Obama");
		Bureaucrat	hans("Hans", 2);
		Bureaucrat	peter("Peter", 138);
		//AForm test("Test",0, 151); // modify to proceed
 		test1.beSigned(hans);
		test1.execute(peter);
		//test2.beSigned(hans);
		//test2.execute(hans);
		test1.beSigned(hans);
		hans.executeForm(test1);
		peter.executeForm(test1);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	/*std::cout << "\nWe test the cannoncical form." << std::endl;
	AForm		blue("blue",3, 3);
	AForm		green("green", 69, 69);
	AForm		bleen(green);
	Bureaucrat	daGerman("Clemens", 1);
	blue.beSigned(daGerman);
	green = blue;
	green.execute(daGerman);
	std::cout << green;// <- status is signed because of copy assignment constructor*/
	return (0);
	
	/*Bureaucrat	Bob("Bob", 130);
	Bureaucrat	Linda("Linda", 4);
	Form		B27("B27", 120, 90);
	Form		B28("B28", 3, 1);
	//Form		B27("B27", 1200, 90);
	//Form		B28("B28", 3, 1000);

	//Form		B27("B27", 0, 90);
	//Form		B28("B28", 3, 0);

	std::cout << "\n\033[35m     Summary of instances     \033[0m" << std::endl;
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;

	std::cout << "\n\033[35m     Bob tries to sign both Forms     \033[0m" << std::endl;
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n\033[35m     Bob increases his grade     \033[0m" << std::endl;
	
	for (int i = 0; i < 30; i++)
	Bob.increment();

	std::cout << Bob;
	
	std::cout << "\n\033[35m     Bob has a better grade now     \033[0m" << std::endl;
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n\033[35m     Lindas grade is higher     \033[0m" << std::endl;
	
	Linda.signForm(B28);
	Linda.increment();
	Linda.signForm(B28);

	std::cout << "\n\033[35m     Summary of instances     \033[0m" << std::endl;
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;
	Linda.signForm(B27);
	
	return (0);*/
}
