/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:19:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/22 08:48:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap *clapTrap[2];

    clapTrap[0] = "Peter";
    clapTrap[1] = "Target";

    clapTrap[0]->attack("Target");
    clapTrap[1]->takeDamage(3);
    clapTrap[0]->beRepaired(1);
    clapTrap[1]->beRepaired(2);

    return (0); 
}
