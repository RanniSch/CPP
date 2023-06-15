/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:13:16 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 09:21:29 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"


template < typename T >
void	printElements(T container)
{
	typename T::const_iterator it;
	typename T::const_iterator ite = container.end();

	for (it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it;
		if (std::distance(it, ite) > 1)
			std::cout << " - ";
	}
	std::cout << std::endl;
}

/*
* Public member function std::vector::push_back
* Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
* This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space
* if -and only if- the new vector size surpasses the current vector capacity.
*/
int main(void)
{
	std::list<int>		lst1;  // std::list is a container that supports constant time insertion and removal of elements from anywhere in the container.
	int					tofind;

	lst1.push_back(2);  
	lst1.push_back(1);
	lst1.push_back(3);
	lst1.push_back(6);
	lst1.push_back(5);
	lst1.push_back(1);
	lst1.push_back(4);
	lst1.push_back(4);
	lst1.push_back(2);
    std::cout << "\nNumbers: ";
	printElements(lst1); // prints all created elements.
	try
	{
		long firstOccurence;
		std::cout << "\n";
		tofind = 2;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 1;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 3;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 4;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 5;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 6;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
		tofind = 7;
		firstOccurence = easyfind(lst1, tofind);
		std::cout << "tofind is: " << tofind << ". 1st occurence found at index : " << firstOccurence << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "tofind is: " << tofind << ". ";
		std::cerr << e.what() << std::endl;
	}

	return (0);
}