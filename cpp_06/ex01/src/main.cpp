/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:34:45 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 19:29:48 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		dataTest;
	Data		*ptr1;
	Data		*ptr2;
	Serializer	Serializer1;
	dataTest.stringValue = "42 Wolfsburg"; 
	dataTest.intValue = 42;
	ptr1 = &dataTest;

	std::cout << "\n\033[32m----- ptr1 stores dataTest at address: " << ptr1 << " -----\033[0m" << std::endl;
	
	std::cout << "intValue: " << (*ptr1).intValue << std::endl;
	std::cout << "stringValue: " << (*ptr1).stringValue << "\n" << std::endl;
	
	uintptr_t dataTestMemoryAddress = Serializer1.serialize(ptr1);
    std::cout << "\033[32m----- dataTest MemoryAddress as Integer: " << dataTestMemoryAddress << " -----\n\033[0m" << std::endl;
	
	ptr2 = Serializer1.deserialize(dataTestMemoryAddress);
	std::cout << "\033[32m----- ptr2 stores dataTest at address: " << ptr2 << " -----\033[0m" << std::endl;
	std::cout << "intValue: " << (*ptr2).intValue << std::endl;
	std::cout << "stringValue: " << (*ptr2).stringValue << "\n" << std::endl;

	if (ptr1 == ptr2)
		std::cout << "\033[32mOriginal pointer and pointer from deserialization are equal!\033[0m\n" << std::endl;
	else
		std::cout << "\033[31mOriginal pointer and pointer from deserialization are different!\033[0m\n" << std::endl;

	return (0);
}
