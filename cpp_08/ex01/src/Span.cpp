/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:40:07 by mochan            #+#    #+#             */
/*   Updated: 2023/06/15 17:20:13 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/*
* Constructors
*/
Span::Span(void) : _N(0), _collection()
{
	std::cout << "Span default constructor called!" << std::endl;
}

Span::Span(unsigned int N) : _N(N), _collection()
{
	std::cout << "Span parameterized constructor called!" << std::endl;
}

Span::Span(const Span &copy) : _N(copy._N), _collection(copy._collection)
{
	std::cout << "Span copy constructor called!" << std::endl;
}

/*
* Destructor
*/
Span::~Span(void)
{
	std::cout << "Span destructor called!" << std::endl;
}


// Overloaded operator

/*
* public member funcion std::vector::clear
* Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
*
* insert (iterator position, InputIterator first, InputIterator last)
* The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
* This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
* Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
* position - Position in the vector where the new elements are inserted. Iterator is a member type, defined as a random access iterator type that points to elements.
*/
Span &Span::operator=(const Span &src)
{
	std::cout << "Span overloaded operator called!" << std::endl;
	if (this != & src) // check for self assignment
	{
		this->_N = src._N;
		this->_collection.clear();
		this->_collection.insert(this->_collection.begin(), src._collection.begin(), src._collection.end());
	}
	return (*this);
}


// Getter

/*
* Returns number of elements!
*/
//int	Span::getN(void)
//{
//	return (this->_N);
//}


// Member functions

/*
* Adding single numbers to a Span.
*
* set::size() --> set_name.size() returns the number of elements in the set container.
*
* std::vector::push_back --> adds a new element at the end of the vector, after its current last element.
* This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space.
*/
void	Span::addNumber(int setValue)
{
	if (this->_collection.size() >= this->_N)
		throw (Span::CollectionFullException());
	else
		this->_collection.push_back(setValue);
}

/*
* std::vector is a sequence container that encapsulates dynamic size arrays.
*
* class template iterator -> acts as a bridge that connects algorithms to STL containers and allows the modifications of the data present inside the container.
* It's a base class template that can be used to derive iterator classes from it.
*
* function template std::begin()
* returns an iterator pointing to the first element in the sequence. In Container it returns cont.begin().
*
* public member function end()
* Returns an iterator referring to the past-the-end element in the vector container, which is the theoretical element that would follow the last element in the vector.
* It does not point to any element, and thus shall not be dereferenced.
* Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with vector::begin to specify a range including all the elements in the container.
* If the container is empty, this function returns the same as vector::begin.
*/
void	Span::betterAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	while (begin < end)
	{
		try
		{
			this->addNumber(*begin);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		begin++;
	}
}

/*
* function template std::sort -> void sort (RandomAccessIterator first, RandomAccessIterator last)
* Sorts the elements in the range [first,last) into ascending order.
* The elements are compared using operator< for the first version, and comp for the second.
*
* std::adjacent_difference
* If [first, last) is not empty, computes the differences between the second and the first of each adjacent pair of its elements
* and writes the differences to the range beginning at diff.begin() + 1
* Calculates the adjacent differences.
*
* function template std::min_element -> returns an iterator pointing to the element with the smallest value in the range [first,last).
* Find the minimum difference.
*/
int	Span::shortestSpan(void)
{
	int shortest_span;

	std::sort(this->_collection.begin(), this->_collection.end());
	std::vector<int> diffs(this->_collection.size() - 1); // "diffs" dynamic size array; this->_collection.size() returns the number of elements in the set container.
	std::adjacent_difference(this->_collection.begin(), this->_collection.end(), diffs.begin()); 
	shortest_span = *std::min_element(diffs.begin(), diffs.end());
	return (shortest_span);
}

/*
* 
* function template std::max_element -> returns an iterator pointing to the element with the largest value in the range [first,last).
*
* function template std::min_element -> returns an iterator pointing to the element with the smallest value in the range [first,last).
* Find the minimum difference.
*/
int	Span::longestSpan(void)
{
	int largest = *std::max_element(this->_collection.begin(), this->_collection.end());
	int smallest = *std::min_element(this->_collection.begin(), this->_collection.end());
	return (largest - smallest);
}

/*
* For better output quality. Called in main. Function is not mandatory.
*/
void	Span::printArrayElements(void)
{
	if (_N == 0)
		std::cout << "\033[31mArray is empty!\033[0m" << std::endl;
	else
	{
		for (unsigned int i = 0; i < _collection.size(); i++)
		{
			if (i != this->_collection.size() - 1)
				std::cout << this->_collection[i] << " - ";
			else
				std::cout << this->_collection[i] << std::endl;
		}
		
	}
}

/*
* Exception
*/
const char *Span::CollectionFullException::what() const throw()
{
	return ("\033[0;31mCollection is full! Cannot add more numbers!");
}
