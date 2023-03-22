/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/22 20:52:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("Lucky");
    ClapTrap b("Peter");

    a.attack("Peter");
    b.takeDamage(4);
    b.beRepaired(2);
    
    b.attack("Lucky");
    a.takeDamage(4);
    a.beRepaired(1);
    b.beRepaired(2);

    /*std::cout << "\033[34mConstructing\033[0m" << std::endl;
	ClapTrap a;
	ClapTrap b("Cody");

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	a.attack("some other robot");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("some other other robot");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Cody-clone");
	b.beRepaired(3);
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;*/

    return (0); 
}
