/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:35:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/29 17:01:50 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

int main(void)
{
    // create a Bureaucrat
    // insert grade
    // insert to low grade
    // insert to high grade

    try{
		Bureaucrat	first("George", 0); //change to a valid number to proceed
		Bureaucrat	second("Clooney", 2);
		first.decrement();
		second.increment();
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
		return 1;
	}

	std::cout << "\nTesting the cannonical form\n" << std::endl; // memory adress print to check!!!
	Bureaucrat office1("Hugo Boss", 69);
	Bureaucrat office2(office1);
	std::cout << office2;
	office1.increment();
	office2 = office1;
	std::cout << office2;
	return (0);
}
