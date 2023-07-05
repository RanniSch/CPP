/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:25:18 by rschlott          #+#    #+#             */
/*   Updated: 2023/07/05 20:09:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructor (public)
RPN::RPN(void)
{
    std::cout << "RPN default constructor called!" << std::endl;
}

// Copy constructor (private)
RPN::RPN(const RPN&	copy)
{
	std::cout << "RPN copy constructor called!" << std::endl;
    this->_input = copy._input;
	this->_I = copy._I;
	this->_C = copy._C;
}

// Destructor (public)
RPN::~RPN(void)
{
    std::cout << "RPN destructor called!" << std::endl;
}

// Overload operator (private)
RPN& RPN::operator=(const RPN& src)
{
	std::cout << "RPN copy assignment operator called!" << std::endl;
    this->_input = src._input;
	this->_I = src._I;
	this->_C = src._C;
	return (*this);
}

// Public member function
/*
* Inverted Polish mathematical expression:
* Bei der umgekehrten polnischen Notation werden zunächst die Operanden niedergeschrieben bzw. eingegeben und danach der darauf anzuwendende Operator.
* „(3+4)×5“ -> „3 4 + 5 ×“ first "3 4 +" and then "7 5 x"
*
* push() function is used to insert an element at the top of the stack.
*
* empty() -> returns a true value (1) if the stack is empty. 
* Otherwise, it returns false (0). In short, this function is used to check if the stack is empty.
*
* top() -> used to access the element at the top of the stack container.
* In a stack, the top element is the element that is inserted at the last or most recently inserted element.
*/
int	RPN::calculate(const std::string input)
{
	if (this->inputCheck(input) == -1) // call of inputCheck()
		return (0);
	this->_input = input;
	int i = 0;
	while (this->_input[i])
	{
		if (this->_input[i] >= '0' && this->_input[i] <= '9')
			this->_I.push(((int)this->_input[i] - 48)); // Convert from string to int
		else if (this->_input[i] != ' ')
			this->_C.push(this->_input[i]); // insert "+ - / *" into char _C
		if (!this->_I.empty() && !this->_C.empty()) // only enters when operator is saved; so there need to be already two numbers saved
			if (this->operate() == -1)      // call of operate()
				return (0);
		i++;
	}
	if (!this->_C.empty()) // if stack for operators is not empty after the call of operate() 
	{
		std::cout << "Error: Stack _C needs to be empty!" << std::endl;
		return (0);
	}
	this->printResult();        // call of printResult()
	return (this->_I.top());
}

// Private member functions

/*
* This function checks for the correct input.
*/
int	RPN::inputCheck(const std::string input)
{
	int	size = input.size();
	for (int i = 0; i < size; i++)
	{
		if ((input[i] >= '0' && input[i] <= '9') || (input[i] == '+') || (input[i] == '-') || (input[i] == '*') || (input[i] == '/'))
		{
			if (i < (size -1) && input[i + 1] != ' ') // space between values and operators obligated
			{
				std::cout << "Error: Invalid input!" << std::endl;
				return (-1);
			}
		}
		else if (input[i] != ' ') // if no num or no operator; has to be a space
		{
			std::cout << "Error: Invalid input." << std::endl;
			return (-1);
		}
	}
	if (input.empty())
	{
		std::cout << "Error: Empty input!" << std::endl;
		return (-1);
	}
	int count_i = 0;
	int count_c = 0;
	for (int i = 0; i < size; i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
			count_i++;      // num of ints
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/')
			count_c++;      // num of chars
		if (count_c > count_i && count_i < 2)       // more operators than numbers
		{
			std::cout << "Error: No operator needed!" << std::endl;
			return (-1);
		}
	}
	if (count_c >= count_i)     // more operators than numbers
	{
		std::cout << "Error: Unused operators!" << std::endl;
		return (-1);
	}
	return (0);
}

/*
* This function handles the operations
* It always takes the first and the second number and calculates them with the operator.
*
* pop() function is used to remove an element from the top of the stack.
*
* push() function is used to insert an element at the top of the stack.
*/
int	RPN::operate(void)
{
	if (_I.size() < 2)  // if only one int
	{
		std::cout << "Error: Only one number!" << std::endl;
		return (-1);
	}
	int	second_op = (int)this->_I.top();
	this->_I.pop();     // remove element from top of stack.
	int	first_op = (int)this->_I.top();
	this->_I.pop();     // remove element from top of stack.
	if (this->_C.top() == '+')
	{
		this->_I.push(first_op + second_op);
		this->_C.pop();
	}
	else if (this->_C.top() == '-')
	{
		this->_I.push(first_op - second_op);
		this->_C.pop();
	}
	else if (this->_C.top() == '*')
	{
		this->_I.push(first_op * second_op);
		this->_C.pop();
	}
	else if (this->_C.top() == '/')
	{
		this->_I.push(first_op / second_op);
		this->_C.pop();
	}
	return (0);
}

void	RPN::printResult(void)
{
	std::cout << (this->_I.top()) << std::endl; // only result is left in stack.
}
