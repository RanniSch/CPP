/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:54:55 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
//#include "Form.hpp"

#include <iostream>

int main(void)
{
	Bureaucrat	Bob("Bob", 130);
	Bureaucrat	Linda("Linda", 4);
	Form		B27("B27", 120, 90);
	Form		B28("B28", 3, 1);
	//Form		B27("B27", 1200, 90);
	//Form		B28("B28", 3, 1000);

	//Form		B27("B27", 0, 90);
	//Form		B28("B28", 3, 0);

	std::cout << "\n\033[35m##### Summary of instances #####\033[0m" << std::endl;
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;

	std::cout << "\n\033[35m##### Bob tries to sign both Forms #####\033[0m" << std::endl;
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n\033[35m##### Bob increases his grade #####\033[0m" << std::endl;
	
	for (int i = 0; i < 30; i++)
	Bob.increment();

	std::cout << Bob;
	
	std::cout << "\n\033[35m##### Bob has a better grade now #####\033[0m" << std::endl;
	
	Bob.signForm(B27);
	Bob.signForm(B28);
	
	std::cout << "\n\033[35m##### Lindas grade is higher #####\033[0m" << std::endl;
	
	Linda.signForm(B28);
	Linda.increment();
	Linda.signForm(B28);

	std::cout << "\n\033[35m##### Summary of instances #####\033[0m" << std::endl;
	std::cout << Bob;
	std::cout << Linda;
	std::cout << B27;
	std::cout << B28;
	Linda.signForm(B27);
	
	return (0);
}
