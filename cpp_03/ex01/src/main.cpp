/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/23 10:02:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    /*
	// TEST 1

	std::cout << "### TESTING CLAPTRAP ###\n" << std::endl;
	ClapTrap a;
    ClapTrap b("Peter");

	print_table();
	a.status();
	b.status();

    a.attack("Peter");
    b.takeDamage(4);
    b.beRepaired(2);
    
    b.attack("Lucky");
    a.takeDamage(4);
    a.beRepaired(1);
    b.beRepaired(2);

	print_table();
	a.status();
	b.status();

	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	ScavTrap c;
	ScavTrap d("Scav");

	print_table();
	c.status();
	d.status();

	c.attack("CloneTrap");
	c.takeDamage(17);
	c.beRepaired(10);
	c.guardGate();

	print_table();
	c.status();
	d.status();
	*/



	// TEST 2

	std::cout << "\n\n### TESTING SCAVTRAP ###\n" << std::endl;
	
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ClapTrap a ("Lilly");
	ScavTrap c;
	ScavTrap d("Savage");
	
	print_table();
	a.status();
	c.status();
	d.status();

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	c.attack("CloneTrap");
	c.takeDamage(21);
	c.beRepaired(22);
	a.takeDamage(9);
	a.beRepaired(30);
	c.beRepaired(22);
	c.guardGate();
	d.attack("Savage-clone");
	d.takeDamage(101);
	d.takeDamage(15);
	d.attack("ScavTrap-clone");

	print_table();
	a.status();
	c.status();
	d.status();

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;

	/*
	// TEST 3

	ClapTrap	Claudia("Claudia");
	ScavTrap	Selma("Selma");

	print_table();
	Claudia.status();
	Selma.status();

	std::cout << "\033[33mThe game begins! \033[0m" << std::endl;
	Claudia.attack("Steve");
	Claudia.beRepaired(14);
	Claudia.takeDamage(3);
	Selma.takeDamage(54);
	Selma.attack("Steve");
	Selma.takeDamage(42);
	Selma.guardGate();
	Selma.beRepaired(20);
	Claudia.attack("Steve");
	Selma.takeDamage(10000);
	Selma.beRepaired(23);

	print_table();
	Claudia.status();
	Selma.status();
	*/

    return (0); 
}
