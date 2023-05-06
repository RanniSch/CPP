/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/06 09:18:20 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		//ShrubberyCreationForm	test0;
		ShrubberyCreationForm	test1("Shrubb");
		//std::cout << test0;
		//std::cout << test1;
		RobotomyRequestForm		test2("Robotomy");
		PresidentialPardonForm	test3("Obama");
		Bureaucrat	hans("Hans", 2);
		Bureaucrat	peter("Peter", 138);
		//AForm test("Test",0, 151); // modify to proceed
		test1.execute(hans);
		peter.signForm(test1);
		test1.beSigned(hans);
		test1.execute(peter);
		test2.execute(hans);
		test2.beSigned(peter);
		test2.beSigned(hans);
		test2.execute(hans);
		test3.execute(hans);
		test3.beSigned(peter);
		test3.beSigned(hans);
		test3.execute(hans);
		hans.executeForm(test1);
		peter.executeForm(test1);
		peter.executeForm(test2);
		hans.executeForm(test2);
		peter.executeForm(test3);
		hans.executeForm(test3);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return 1;
	}

	std::cout << "\n\033[32mTesting the cannoncical form:\033[0m" << std::endl;
	AForm		blue("blue",3, 3);
	Bureaucrat	linda("Linda", 1);
	
	AForm green("green", 69, 69);
	AForm bleen(green);
	blue.beSigned(linda);
	green.execute(linda);
	green = blue;
	green.execute(linda);
	std::cout << green;// <- status is signed because of copy assignment constructor
	std::cout << bleen;

	/*AForm green(blue); // deep copy gets created.
	std::cout << green;
	std::cout << blue;
	blue.beSigned(linda);
	std::cout << blue;
	std::cout << green;
	green = blue;
	std::cout << green;*/
	
	return (0);
}
