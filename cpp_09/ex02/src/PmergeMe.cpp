/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:30:01 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 17:25:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe(void) : _inputVector(), _inputDeque()
{
    //std::cout << "PmergeMe: Default constructor called!" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& copy) : _inputVector(copy._inputVector), _inputDeque(copy._inputDeque)
{
    //std::cout << "PmergeMe: Copy constructor called!" << std::endl;
}

// Destructor
PmergeMe::~PmergeMe(void)
{
    //std::cout << "PmergeMe: Destructor called!" << std::endl;
}

// Overload operator
PmergeMe& PmergeMe::operator=(const PmergeMe& src)
{
	if (this != & src) // check for self assignment
	{
		this->_inputVector.clear();
		this->_inputVector.insert(this->_inputVector.begin(), src._inputVector.begin(), src._inputVector.end());
		this->_inputDeque.clear();
		this->_inputDeque.insert(this->_inputDeque.begin(), src._inputDeque.begin(), src._inputDeque.end());
	}
	return (*this);
}

// Getters
std::vector<int>&	PmergeMe::getVector()
{
	return this->_inputVector;
}

std::deque<int>&	PmergeMe::getDeque()
{
	return this->_inputDeque;
}


// ---------- Member functions (private and public) ----------

/*
* std::vector is a sequence container that encapsulates dynamic size arrays.
*
* push_back() is a pre-defined function that is used to insert data or elements at the end of a vector or it
* pushes the element in the vector from the back. Whenever an element is inserted into a vector, the size of
* the vector increases by one.
*/
void	PmergeMe::addNumToVector(int numValue)
{
	this->_inputVector.push_back(numValue);
}

/*
* std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end.
* In addition, insertion and deletion at either end of a deque never invalidates (ungültig machen) pointers or references to the rest of the elements.
*
* push_back() adds a new element at the end of the deque container, after its current last element. 
* The content of val is copied (or moved) to the new element.
*/
void	PmergeMe::addNumToDeque(int numValue)
{
	this->_inputDeque.push_back(numValue);
}

/*
* This function stores the given numbers with the help of two different containers "Vector" and "deque" by calling the functions
* addNumToVector() and addNumToDeque()
*
* atoi() -> changing string to int
*/
void	PmergeMe::storeCollection(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		addNumToVector(atoi(argv[i]));
		addNumToDeque(atoi(argv[i]));
	}
}

/*
* This function checks for duplicate numbers. This check is only in one of the containers needed!
*
* public member function std::set::set -> Constructs a set container object.
* Elements of sets are always sorted.                                   vs. Vector       Elements of the vector are unsorted.
* It contains only unique elements.                                     vs. Vector       It can contain duplicate elements.
* Set is ordered.                                                       vs. Vector       The vector is unordered.
* Time complexity for the insertion of a new element is O(log N).       vs. Vector       Time complexity for insertion of a new element is O(1).
* Faster for insertion & deletion of elements at middle of container.   vs. Vector       Is faster for insertion & deletion of elements at end of container.
*
*
* public member function std::vector::begin -> returns an iterator pointing to the first element in the vector.
* Vector is accessed with the help of my getVector getter function.
*
* public member function std::vector::end -> returns an iterator referring to the past-the-end element in the vector container.
* Vector is accessed with the help of my getVector getter function.
*
* std::set::size -> returns the number of elements in the set container.
* std::vector::size -> Returns the number of elements in the vector. This is the number of actual objects held in the vector, which is not necessarily equal to its storage capacity.
*/
bool	PmergeMe::checkNoDuplicate(void)
{
    std::set<int> set(getVector().begin(), getVector().end()); // this copies elements of vec into a set. Set does not take double entries by default.
    if (set.size() == getVector().size())   // size is equal when no duplicates exist, else getVector size is bigger.
		return (true);
	return (false);
}

/*
* Prints elements after sorted and stored in the vector container.
*/
void	PmergeMe::printVector(void)
{
	for (std::vector<int>::iterator it = getVector().begin(); it != getVector().end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
}

/*
* Prints elements after sorted and stored in the deque container.
*/
void	PmergeMe::printDeque(void)
{
	for (long unsigned int i = 0; i < this->getDeque().size(); i++)
		std::cout << this->getDeque()[i] << " ";
	std::cout << "\n";
}


// ---------- Functions outside the class ----------

/*
* This function checks if a received string only contains digits.
*
* int isdigit ( int c ) -> Checks whether c is a decimal digit character.
* Decimal digits are any of: 0 1 2 3 4 5 6 7 8 9
*/
bool	isDigit(char *s)
{
	int i;

    i = 0;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
		i++;
	while (s[i])
	{
        if (isdigit(s[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

/*
* This function converts string to long integer and checks if the integer is in range.
*
* strtol() -> long int strtol (const char* str, char** endptr, int base); converts string to long integer
* str - C-string beginning with the representation of an integral number.
* endptr - This parameter can also be a null pointer, in which case it is not used.
* base - Numerical base (radix) that determines the valid characters and their interpretation. 
*
*/
bool	inRange(char *s)
{
	long	c;

	c = strtol(s, NULL, 10);
	if (c < INT_MIN || c > INT_MAX || strlen(s) > 11)
		return (false);
	return (true);
}

/*
* This function calls the isDigit and the inRange function.
*/
bool	isDigitAndInRange(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
        if (!isDigit(argv[i]))
            return (false);
        if (!inRange(argv[i]))
            return (false);
	}
	return (true);
}

/*
* This function checks for the correct amount of input and calls the isDigitAndInRange function.
*/
bool	validInput(int argc, char **argv)
{
	if (argc == 1)
		return (false);
	if (argc > 1)
		if(!isDigitAndInRange(argc, argv))
            return (false);
	return (true);
}
