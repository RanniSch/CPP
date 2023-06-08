/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:50:07 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
    // TEST 1: clear test
	Bureaucrat def;
	std::cout << "Default name: " << def.getName() << std::endl;
	std::cout << "Default grade: " << def.getGrade() << std::endl;
	def.decrement();
	Bureaucrat test1("Ben", 7);
	Bureaucrat test2("Tom", 1);
	Bureaucrat test3("Ken", 150);
	test1.increment();
	test2.increment();
	test2.decrement();
	test3.decrement();
	test3.increment();
	return (0);

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
}
