/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 19:46:09 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 20:16:35 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>

/*
* Generates a random int from 0 to 2.
*/
int	IntNumGenerator(void)
{
	int random_int = std::rand() % 3;
	return (random_int);
}

/*
* *generate randomly instanciates A, B or C and returns the instance as a Base pointer.
*/
Base *generate(void)
{
	Base *ptrBase = NULL;
	int i = IntNumGenerator();
	switch (i)
	{
		case 0:
			ptrBase = new A;
			std::cout << "\033[32mA Class is created -";
			break;
		case 1:
			ptrBase = new B;
			std::cout << "\033[33mB Class is created -";
			break;
		case 2:
			ptrBase = new C;
			std::cout << "\033[35mC Class is created -";
			break;
		default:
			std::cout << "\033[31mError: fatal.\033[0m" << std::endl;
			break;
	}
	return (ptrBase);
}

/*
* identify prints the actual type of the object pointed to by p: "A", "B" or "C".
*
* Syntax: dynamic_cast< target-type >( expression )
* Safely converts pointers and references to classes up, down, and sideways along the inheritance hierarchy.
* If the cast is successful, dynamic_cast returns a value of type target-type. If the cast fails and target-type is a pointer type,
* it returns a null pointer of that type. If the cast fails and target-type is a reference type,
* it throws an exception that matches a handler of type std::bad_cast.
*/
void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << " A is identified with pointer -";
	else if (dynamic_cast<B*>(p))
		std::cout << " B is identified with pointer -";
	else if (dynamic_cast<C*>(p))
		std::cout << " C is identified with pointer -";
	else
		std::cout << " Unkown base -";
}

/*
* identify prints the actual type of the object pointed to by p: "A", "B" or "C".
*/
void	identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << " A is identified with reference\033[0m" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << " B is identified with reference\033[0m" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << " C is identified with reference\033[0m" << std::endl;
	}
	catch (const std::exception &e)
	{
	}
}

int main(void)
{
	Base *ptr;
	
	std::srand(std::time(NULL)); // Seeds the IntNumGenerator with the current time.

	for (int i = 0; i < 10; i++)
	{
		std::cout << "[" << i + 1 << "]\t"; 
		ptr = generate();
		Base &ref = *ptr;
		identify(ptr);
		identify(ref);
		delete ptr;
	}
	return (0);
}
