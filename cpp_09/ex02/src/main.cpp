/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:29:57 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 17:22:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/*
* The Ford-Johnson algorithm, also known as merge-insertion sort is an in-place sorting algorithm designed
* to perform as few comparisons as possible to sort a collection. Unfortunately, the algorithm needs some specific
* data structures to keep track of the order of the elements and is generally too slow to be practical. Anyway, it is
* an interesting algorithm from a computer science point of view; while not performing an optimal number of comparisons,
* it's still a reference and one of the best known comparison sorts when it comes to reducing the number of comparisons.
*/

// ./PmergeMe "-1" "2" --> Error how to?
// ./PmergeMe "-1 2" --> Error

/*
* int gettimeofday(struct timeval *tp, struct timezone *tzp)
* tp is a pointer to a timeval structure that contains the time in seconds and microseconds since 1 January 1970, 00:00:00 UTC (epoch-1970).
* tzp is a pointer to a time zone structure that contains the local time zone (measured in minutes west of Greenwich) and a flag that, if nonzero, indicates Daylight Saving Time applies locally during the appropriate part of the year.
*
* function std::fixed
* When floatfield is set to fixed, floating-point values are written using fixed-point notation: the value is represented
* with exactly as many digits in the decimal part as specified by the precision field (precision) and with no exponent part.
*
* function std::setprecision
* Sets the decimal precision to be used to format floating-point values on output operations. Behaves as if member precision
* were called with n as argument on the stream on which it is inserted/extracted as a manipulator.
*/
int main(int argc, char **argv)
{
	PmergeMe	collection;

	if (!validInput(argc, argv))
	{
		std::cout << "\033[31mError: Input is NOT correct!\033[0m" << std::endl;
		return (0);
	}
	collection.storeCollection(argc, argv);
	if (!collection.checkNoDuplicate())
	{
		std::cout << "\033[31mError: Input has duplicates!\033[0m" << std::endl;
		return (0);
	}
	
    std::cout << "Before:\t";
	for (int i = 1; argv[i]; i++)
		std::cout << argv[i] << " ";
	std::cout << std::endl;
    
	struct timeval	start_1;
    struct timeval	end_1;
	struct timeval	start_2;
    struct timeval	end_2;

    gettimeofday(&start_1, NULL); // NULL as no time zone needed. We only compare time length from start with each other.
	collection.sortProcess(collection.getVector(), 0, collection.getVector().size() - 1); // Vector for container, Index 0 and last element as Index
	gettimeofday(&end_1, NULL);

	gettimeofday(&start_2, NULL);
	collection.sortProcess(collection.getDeque(), 0, collection.getDeque().size() - 1);
	gettimeofday(&end_2, NULL);
    
	double time_taken_1 = (end_1.tv_sec - start_1.tv_sec) + (end_1.tv_usec - start_1.tv_usec) / 1000000.0; // tv_sec -> sec; tv_usec -> microsec
	double time_taken_2 = (end_2.tv_sec - start_2.tv_sec) + (end_2.tv_usec - start_2.tv_usec) / 1000000.0; // tv_sec -> sec; tv_usec -> microsec

	std::cout << "After:\t";
	collection.printVector();   // only one sorted process should be printed.
    //collection.printDeque();

	std::cout << "Time to process a range of " << collection.getVector().size() << " elements with std::vector<int> : " << std::fixed << time_taken_1 * 1000000 << std::setprecision(10) << " usec" << std::endl;
	std::cout << "Time to process a range of " << collection.getDeque().size() << " elements with std::deque<int>  : " << std::fixed << time_taken_2 * 1000000 << std::setprecision(10) << " usec" << std::endl;	
	return (0);
}
