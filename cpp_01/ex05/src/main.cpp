/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/17 21:57:44 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

int main(int argc, char **argv) 
{
	Harl *harl;
    int i = 0;
    std::string level;

	harl = new Harl;
    if (argc == 1)
    {
        std::cout << "Wrong input!" << std::endl <<
        "Write: ./harl with minimum one level comment!" << std::endl;
    }
    while (argv[++i] != '\0')
    {
        level = argv[i];
        harl->complain(level);
    }
	
    delete harl;

	return (0);
}
