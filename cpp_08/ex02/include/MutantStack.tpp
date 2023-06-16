/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:43:05 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 08:46:52 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "MutantStack.hpp"


// Constructors
template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack default constructor called!" << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T>(copy)
{
	std::cout << "MutantStack copy constructor called!" << std::endl;
}

// Destructor
template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called!" << std::endl;
}

// Overload Operator

/*
* Is used as a shallow copy.
*/
template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	std::cout << "MutantStack copy assignment operator called!" << std::endl;
	std::stack<T>::operator=(src);
	return (*this);
}


// Iterator Functions

/*
* typename is to signify that container_type is a template type that depends on parameter T which could be int, float etc.
*
* Stacks are a type of container adaptor, specifically designed to operate in a last-in first-out context, where elements are inserted and extracted only from one end of the container.
* std::stack is a container adapter that is built on top of the underlying container, which is std::deque.
* The underlying container can be accessed through the member c. Therefore, std::stack<T>::c is the underlying
* container of type std::deque<T> in which the elements are stored.
* Stack class initiated without an adapter specified, defaults to deque. Deque contains a protected member c, which is the sequence of data. 
* This uses the standard iterators and we are able to access them through c.
* class template std::deque
* is an irregular acronym of double-ended queue. They are sequence containers with dynamic sizes that can be expanded or contracted on both ends.		        
*
* container_type is a member of std::stack and refers to the type of the underlying container that is used to store the elements of the stack.
* std::stack does not expose the iterator type of the underlying container directly, so we have to use the
* container_type member to get the underlying container's type, and then access its iterator type.
*
* ------------------------------------------------------------------------------------------------------------------
* Iterator functions
* The inherited begin(), end(), rbegin(), and rend() functions access the corresponding member functions 
* of the underlying container std::stack<T>::c to provide access to the iterators of the container std::deque<T>.
*
* iterators are similar in concept to pointers:
* iterator -> iterates through a range.
*
* begin()
* returns an iterator pointing to the first element in the sequence. In Container it returns cont.begin().
*/
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::begin()
{
	return (std::stack<T>::c.begin());
}

/*
* iterators are similar in concept to pointers:
* iterator -> iterates through a range.
*
* end()
* Returns an iterator referring to the past-the-end element in the vector container, which is the theoretical element that would follow the last element in the vector.
* It does not point to any element, and thus shall not be dereferenced.
*/
template <typename T>
typename std::stack<T>::container_type::iterator MutantStack<T>::end()
{
	return (std::stack<T>::c.end());
}

/*
* Iterator functions
* The inherited begin(), end(), rbegin(), and rend() functions access the corresponding member functions 
* of the underlying container std::stack<T>::c to provide access to the iterators of the container std::deque<T>.
*
* iterators are similar in concept to pointers:
* const_iterator -> is an iterator that points to const value (like a const T* pointer) (cannot change the value, read only).
*
* begin()
* returns an iterator pointing to the first element in the sequence. In Container it returns cont.begin().
*/
template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::begin() const
{
	return (std::stack<T>::c.begin());
}

/*
* iterators are similar in concept to pointers:
* const_iterator -> is an iterator that points to const value (like a const T* pointer) (cannot change the value, read only).
*
* end()
* Returns an iterator referring to the past-the-end element in the vector container, which is the theoretical element that would follow the last element in the vector.
* It does not point to any element, and thus shall not be dereferenced.
*/
template <typename T>
typename std::stack<T>::container_type::const_iterator MutantStack<T>::end() const
{
	return (std::stack<T>::c.end());
}

/*
* Iterator functions
* The inherited begin(), end(), rbegin(), and rend() functions access the corresponding member functions 
* of the underlying container std::stack<T>::c to provide access to the iterators of the container std::deque<T>.
*
* iterators are similar in concept to pointers:
* reverse_iterator -> reverses the direction in which a bidirectional or random-access iterator iterates through a range.
* A copy of the original iterator (the base iterator) is kept internally and used to reflect the operations performed on the reverse_iterator:
* whenever the reverse_iterator is incremented, its base iterator is decreased, and vice versa.
* An iterator pointing to a past-the-end element in a range, when reversed, is pointing to the last element (not past it) of the range (this would be the first element of the reversed range).
* And if an iterator to the first element in a range is reversed, the reversed iterator points to the element before the first element (this would be the past-the-end element of the reversed range).             
*
* rbegin()
* Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
* rbegin points to the element right before the one that would be pointed to by member end().
*/
template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rbegin()
{
	return (std::stack<T>::c.rbegin());
}

/*
* iterators are similar in concept to pointers:
* reverse_iterator -> reverses the direction in which a bidirectional or random-access iterator iterates through a range.
* A copy of the original iterator (the base iterator) is kept internally and used to reflect the operations performed on the reverse_iterator:
* whenever the reverse_iterator is incremented, its base iterator is decreased, and vice versa.
* An iterator pointing to a past-the-end element in a range, when reversed, is pointing to the last element (not past it) of the range (this would be the first element of the reversed range).
* And if an iterator to the first element in a range is reversed, the reversed iterator points to the element before the first element (this would be the past-the-end element of the reversed range).
*
* rend()
* Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
* The range between vector::rbegin and vector::rend contains all the elements of the vector (in reverse order).
*/
template <typename T>
typename std::stack<T>::container_type::reverse_iterator MutantStack<T>::rend()
{
	return (std::stack<T>::c.rend());
}

/*
* rbegin()
* Returns a reverse iterator pointing to the last element in the vector (i.e., its reverse beginning).
* rbegin points to the element right before the one that would be pointed to by member end().
*/
template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (std::stack<T>::c.rbegin());
}

/*
* rend()
* Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (which is considered its reverse end).
* The range between vector::rbegin and vector::rend contains all the elements of the vector (in reverse order).
*/
template <typename T>
typename std::stack<T>::container_type::const_reverse_iterator MutantStack<T>::rend() const
{
	return (std::stack<T>::c.rend());
}

#endif