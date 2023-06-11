/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:58:31 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/11 09:40:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

/*
* syntax / semantics for a “function template”:
* template<typename T>
* void function(T& x, T& y, ...)
*
* function template that takes 3 parameters and returns nothing.
• 1. address of an array, 2. length of the array, 3. function that's called on every element of the array.
*/

template < typename T >
void    iter(T *arrayAdress, unsigned int len, void (*f)(T const &ptr))
{
    unsigned int	i = 0;

	while (i < len)
	{
		f(arrayAdress[i]);
		i++;
	}
}

template < typename T >
void    myPrint(T const &x)
{
    std::cout << x << std::endl;
}

#endif