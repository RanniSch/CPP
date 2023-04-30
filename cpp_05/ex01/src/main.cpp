/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/30 12:13:52 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//#include "Form.hpp"

#include <iostream>

int main(void)
{
    // TEST 1: clear test
	/*Bureaucrat def;
	std::cout << def.getName() << std::endl;
	std::cout << def.getGrade() << std::endl;
	def.decrement();
	Bureaucrat test1("Ben", 7);
	Bureaucrat test2("Tom", 1);
	Bureaucrat test3("Ken", 150);
	test1.increment();
	test2.increment();
	test2.decrement();
	test3.decrement();
	test3.increment();
	return (0);*/

	// TEST 2: test to show exception with overload << operator
	/*Bureaucrat	Bob("Bob", 1000);
	Bob.decrement();
	Bob.increment();
	// constructor sets grade to 150 (comment in line 39 in Bureaucrat.cpp);
	//std::cout << Bob.getGrade() << std::endl;
	//std::cout << Bob;
	return (0);*/

    // TEST 3: to test also cannoncial form
	/*try
	{
		Bureaucrat	first("George", 0); //change to a valid number to proceed
		Bureaucrat	second("Clooney", 2);
		first.decrement();
		second.increment();
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}

	std::cout << "\033[35m\nTesting the cannonical form:\033[0m" << std::endl;
	
	Bureaucrat office1("Hugo", 69);
	Bureaucrat office2(office1); // deep copy gets created.
	std::cout << office2;
	office1.increment();
	std::cout << office2;
	office2 = office1; // increment also deep copy by 1.
	std::cout << office2;
	return (0);*/

	Bureaucrat	Bob("Bob", 1000);
	Bureaucrat	Linda("Linda", 4);
	Form		B27("B27", 120, 90);
	Form		B28("B28", 3, 1);

	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;

	std::cout << "\n################################## Bob tries to sign both ######################\n\n";
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n################################### Bob is working hard to get each and every promotion ##########################\n\n";
	
	for (int i = 0; i < 30; i++)
	Bob.increment();

	std::cout << Bob;
	
	std::cout << "\n################ Bob finally managed to grind his way up ##############################\n\n";
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n######################################## All this hard work an he's still not on the top ######################\n\n";
	
	Linda.signForm(B28);
	Linda.increment();
	Linda.signForm(B28);

	std::cout << "\n############################### Summary of instances ###########################\n\n";
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;
	
	return (0);
}
