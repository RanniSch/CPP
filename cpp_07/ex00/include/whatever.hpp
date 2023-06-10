/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 08:26:02 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/10 22:42:48 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/*
* syntax / semantics for a “function template”:
* template<typename T>
* void swap(T& x, T& y)
* {
*   T tmp = x;
*   x = y;
*   y = tmp;
* }
* instead of: void swap(int& x, int& y)
*
* What's the benefit of function template?
* To avoid long codes for different data types (floats, longs, Strings, Sets, and FileSystems,...) with almost identical code except for the type.
* Every time using swap() with a given pair of types, the compiler will go to the above definition and will create yet another “template function” as an instantiation of the above.
* Unlike template classes, template functions usually do not need to be explicit about the parameters over which they are instantiating. The compiler can usually determine them automatically.
* Note: A “template function” is the instantiation of a “function template”.
* Sometimes, you do want to be explicit about the types used. So explicitly select which version of a function template should get called:
* https://isocpp.org/wiki/faq/templates
*/
template < typename T >
void swap(T &x, T &y)
{
	T   temp;

    temp = y;
	y = x;
	x = temp;
}


template < typename T >
T min(T const &x, T const &y)
{
	if (x == y)
		return (y);
	else
	{
		if (x < y)
			return (x);
		else
			return (y);
	}
}

template < typename T >
T max(T const &x, T const &y)
{
		if (x == y)
			return (y);
		else
		{
			if (x > y)
				return (x);
			else
				return (y);
		}
}

#endif