/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:43:05 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 17:53:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"


//======== CONSTRUCTORS =========================================================================
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor called!" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& src) : std::stack<T>(src)
{
	std::cout << "MutantStack copy constructor called!" << std::endl;
}


//======== OVERLOAD OPERATORS ===================================================================
// This is a shallow copy
template<typename T>
MutantStack<T>&  MutantStack<T>::operator=(const MutantStack& src)
{
	std::cout << "MutantStack copy assignment operator called!" << std::endl;
	std::stack<T>::operator=(src);
	return (*this);
}


//======== DESTRUCTOR ==========================================================================
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called!" << std::endl;
}

//======== ITERATOR FUNCTIONS ==================================================================
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return std::stack<T>::c.end();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return std::stack<T>::c.begin();
}

template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return std::stack<T>::c.end();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return std::stack<T>::c.rend();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return std::stack<T>::c.rbegin();
}

template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return std::stack<T>::c.rend();
}

#endif