/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 17:53:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template < typename T > 
class MutantStack : public std::stack< T > //MutantStack will also inherit (implicitly) the template argument T
{
	public:
		// CONSTRUCTORS
		MutantStack();
		MutantStack(const MutantStack& src);
		
		// OVERLOAD OPERATOR
		MutantStack& operator=(const MutantStack& src);

		// DESTRUCTOR
		~MutantStack();

		//ITERATOR TYPEDEFS
		// * iterators are similar in concept to pointers.
		// * std::stack is a container adapter that is built on top of the underlying container, which 
		//   is std::deque. The underlying container can be accessed through the member c. Therefore,
		//   std::stack<T>::c is the underlying container of type std::deque<T> in which the elements are stored.
		//   std::stack is a class template that is defined in the C++ standard library. It has a container_type member that 
		//   refers to the type of the underlying container that is used to store the elements of the stack.
		// * std::stack does not expose the iterator type of the underlying container directly, so we have to use the
		//   container_type member to get the underlying container's type, and then access its iterator type. 
		// * typename is to signify that container_type is a template type that depends on parameter T which could be int, float etc.
		// * typedef is used to create an alias for : iterator, const_iterator etc. (cf MutantStack.tpp)
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		// ITERATOR FUNCTIONS
		// * The inherited begin(), end(), rbegin(), and rend() functions access the corresponding member functions 
		//   of the underlying container std::stack<T>::c to provide access to the iterators of the container std::deque<T>.
		// * std::deaue hqs for 4 types of iterators.
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		reverse_iterator rbegin();
		reverse_iterator rend();
		const_reverse_iterator rbegin() const;
		const_reverse_iterator rend() const;

	private:

};

#endif