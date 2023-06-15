/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:36:01 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 08:23:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

/*
* Why use a ".tpp" file when implementing templated functions and classes defined in a header?
* It's used when you don't want the file that contains the interface of a module to contain all the gory implementation details. 
* But you cannot write the implementation in a .cpp file because it's a template.
* It does not matter what the extension is, but don't use .cpp because it goes against conventions.
*/

// Constructors
template <typename T>
Array<T>::Array() : _size(0), _array(NULL)
{
	std::cout << "\033[33mArray: default constructor called!\033[0m" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _array(new T[n])
{
	std::cout << "\033[33mArray: parameterized constructor called!\033[0m" << std::endl;
}

template <typename T>
Array<T>::Array(const Array &copy) : _size(copy._size), _array(new T[copy._size])
{
	std::cout << "\033[33mArray: copy constructor called!\033[0m" << std::endl;
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = copy._array[i];
}

// Destructor
template <typename T>
Array<T>::~Array(void)
{
	std::cout << "\033[33mArray destructor called!\033[0m" << std::endl;
	delete[] _array;
}

// Overloaded operators
template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	std::cout << "\033[33mArray: copy assignment operator called!\033[0m" << std::endl;
	this->_size = src._size;
	if (_array != NULL)
		delete [] _array;
	this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = src._array[i];
	return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index < 0 || index > (this->_size - 1))
		throw OutOfRangeException();
	return (this->_array[index]);
}

// Getter
template <typename T>
unsigned int    Array<T>::size(void)
{
	return (this->_size);
}

// Member function
template <typename T>
void	Array<T>::printArrayElements(void)
{
	unsigned int i = -1;

	if (_size == 0)
		std::cout << "Array is empty!" << std::endl;
	else
	{
		while (++i < this->size())
		{
			if (i != this->size() - 1)
				std::cout << _array[i] << " - ";
			else
				std::cout << _array[i] << std::endl;
		}		
	}
}

// Exception
template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
	return ("\033[31mIndex is out of range!\033[0m");
}

#endif