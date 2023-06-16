/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:49:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 17:55:33 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mError: could not open file.\033[0m" << std::endl;
		return (0);
	}
	BitcoinExchange	b;

	b.storeDatabase(argv[1]);
    //b.storeDatabase((char *)"data.csv");
	b.printBtcValue(argv[1]);
	return (0);
}