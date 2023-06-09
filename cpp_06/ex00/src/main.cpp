/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 12:43:59 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 12:46:27 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31mWrong input. Number of argument are 2!\033[0m" << std::endl;
		return (1);
	}
	if (argv[1] == NULL)
	{
		std::cout << "\033[31mInput string is empty.\033[0m" << std::endl;
		return (0);
	}
	else
	{
		std::string	input;
		ScalarConverter *Convert1 = ScalarConverter::createInstance();

		input = argv[1];
		Convert1->setInput(input);
		Convert1->convert(input);
		delete Convert1;
	}
	return (0);
}
