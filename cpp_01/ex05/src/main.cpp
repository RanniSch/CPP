/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/16 19:58:41 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

int main(int argc, char **argv) 
{
	Harl *harl;

	harl = new Harl;
    if (argc == 1)
    {
        std::cout << "Wrong input!" << std::endl <<
        "Write: ./harl with minimum one level comment!" << std::endl;
    }

	delete harl;

	return (0);
}
