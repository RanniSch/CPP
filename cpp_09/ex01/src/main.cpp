/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:25:46 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 07:29:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		RPN	rpn;
		rpn.calculate(argv[1]);
	}
	else
		std::cout << "\033[31mError: Input not correct!\033[0m" << std::endl;
	return (0);
}