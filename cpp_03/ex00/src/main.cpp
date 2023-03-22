/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/22 20:32:45 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("Peter");

    a.attack("Target");
    b.takeDamage(3);
    a.beRepaired(1);
    b.beRepaired(2);

    return (0); 
}
