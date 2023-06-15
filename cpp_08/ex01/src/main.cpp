/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:40:00 by mochan            #+#    #+#             */
/*   Updated: 2023/06/15 17:34:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	{
		try
		{
			std::cout << "\033[32m\n----- Collection creation -----\033[0m" << std::endl;
			std::cout << "\033[33mCreating a collection of 3 elements and adding 3 values.\033[0m" << std::endl;
			Span	span1(3);
			span1.addNumber(42);
			span1.addNumber(21);
			span1.addNumber(97);
			std::cout << "Elements: ";
			span1.printArrayElements();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	{
		try
		{
			std::cout << "\n\033[32m----- Catching Exceptions -----\033[0m" << std::endl;
			std::cout << "\033[33mCreating a collection of 3 elements and adding 4 values.\033[0m" << std::endl;
			Span	span1(3);
			span1.addNumber(42);
			span1.addNumber(21);
			span1.addNumber(97);
			span1.addNumber(67);
			std::cout << "Elements: ";
			span1.printArrayElements();
			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	
	{
		std::cout << "\n\033[32m----- Shortest and Longest Spans -----\033[0m" << std::endl;
		std::cout << "\033[33mCreating a collection of 5 elements and adding 5 values.\033[0m" << std::endl;
		Span span1 = Span(5);
		span1.addNumber(6);
		span1.addNumber(3);
		span1.addNumber(17);
		span1.addNumber(9);
		span1.addNumber(11);
		std::cout << "Elements: ";
		span1.printArrayElements();
		std::cout << "Shortest Span is: " << span1.shortestSpan() << std::endl;
		std::cout << "Longest Span is: " << span1.longestSpan() << std::endl;
		
	}

	{
		std::cout << "\n\033[32m----- Very big Span -----\033[0m" << std::endl;
		std::cout << "\033[33mCreating a collection of 20 000 elements.\033[0m" << std::endl;
		std::vector<int> bigVector;		// std::vector is a sequence container that encapsulates dynamic size arrays.
		Span bigSpan = Span(20000);

		srand(1);		// void srand (unsigned int seed) -> The pseudo-random number generator is initialized using the argument passed as seed. If seed is set to 1, the generator is reinitialized to its initial value and produces the same values as before any call to rand or srand.
		for (int i = 0; i < 20000; i++)
		{
			try
			{
				bigVector.push_back(rand());		// int rand (void) -> Returns a pseudo-random integral number in the range between 0 and RAND_MAX (at least 32767). This algorithm uses a seed to generate the series, which should be initialized to some distinctive value using function srand.
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}

		try
		{
			bigSpan.betterAddNumber(bigVector.begin(),bigVector.end());
			//bigSpan.printArrayElements();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	return 0;
}
