/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:34:49 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 19:23:57 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void)
{
	std::cout << "Serializer default constructor called!" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	std::cout << "Serializer copy constructor called!" << std::endl;
	*this = copy;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer destructor called!" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	std::cout << "Serializer overloaded operator called!" << std::endl;
	(void)src;

	return (*this);
}

/*
* serialize takes a pointer and converts it to the unsigned integer type uintptr_t.
*
* Syntax: reinterpret_cast< new-type >( expression )
* Returns a value of type new-type.
*
* static_casting a pointer to and from void* preserves the address. That is, in the following, a, b and c all point to the same address:
* int* a = new int();
* void* b = static_cast<void*>(a);
* int* c = static_cast<int*>(b);
* 
* reinterpret_cast only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type,
* you get the original value. So in the following:
* int* a = new int();
* void* b = reinterpret_cast<void*>(a);
* int* c = reinterpret_cast<int*>(b);
* a and c contain the same value, but the value of b is unspecified.
* (in practice it will typically contain the same address as a and c, but that's not specified in the standard, and it may not be true on machines with more complex memory systems.)
*
* For casting to and from void*, static_cast should be preferred.
*/
uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/*
* deserialize takes an unsigned integer parameter and converts it to a pointer to Data.
*/
Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
