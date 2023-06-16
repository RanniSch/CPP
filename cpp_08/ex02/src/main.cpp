/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:43:29 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 09:32:07 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.tpp"

int main(void)
{
	std::cout << "\033[32m\n----- Tests from Subject -----\033[0m" << std::endl;
	{
		std::cout << "\033[35m----- MutantStack <int> -----\033[0m" << std::endl;
		MutantStack<int> mstack;
		mstack.push(6);         // push() function is used to insert an element at the top of the stack. 
		mstack.push(21);
		std::cout << "\n\033[33m" << mstack.top() << " is the top element of the stack. From ";
        std::cout << mstack.size() << " elements in total.\033[0m"<< std::endl;
		mstack.pop();           // The pop() function is used to remove or an element from the top of the stack.
		std::cout << mstack.size() << " element in the stack after pop."<< std::endl;
		mstack.push(2);
		mstack.push(5);
		mstack.push(979);
		mstack.push(-4);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		std::cout << "First element: " << *it << std::endl;
        ++it;
        std::cout << "After iterating: " << *it << std::endl;
        --it;
		while (it != ite)
		{
			std::cout << *it << " - ";
			++it;
		}
		std::cout << std::endl;
		std::stack<int> s(mstack);
	}
	{
		std::cout << "\033[35m\n----- List <int> -----\033[0m" << std::endl;
		std::list<int> mstack;
		mstack.push_back(6);            // Adds a new element at the end of the list container, after its current last element.
		mstack.push_back(21);
        std::cout << "\033[33m" << mstack.back() << " is the top element of the stack. From ";
        std::cout << mstack.size() << " elements in total.\033[0m"<< std::endl;
		mstack.pop_back();              // Removes the last element in the list container, effectively reducing the container size by one.
		std::cout << mstack.size() << " elements in the stack after pop_back." << std::endl;
		mstack.push_back(2);
		mstack.push_back(5);
		mstack.push_back(979);
		mstack.push_back(-4);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
        std::cout << "First element: " << *it << std::endl;
        ++it;
        std::cout << "After iterating: " << *it << std::endl;
        --it;
		while (it != ite)
		{
			std::cout << *it << " - ";
			++it;
		}
        std::cout << std::endl;
	}
	std::cout << "\n\033[32m----- Own Tests -----\033[0m" << std::endl;
	{
		std::cout << "\033[35m----- MutantStack <float> -----\033[0m" << std::endl;
		MutantStack<float> mstack;
		mstack.push(3.1f);      // push() function is used to insert an element at the top of the stack.
		mstack.push(-14.7f);
		std::cout << "\n\033[33m" << mstack.top() << "f" << " is the top element of the stack. From ";
		std::cout << mstack.size() << " elements in total.\033[0m" << std::endl;
        mstack.pop();           // The pop() function is used to remove or an element from the top of the stack.
		std::cout << mstack.size() << " elements in the stack after pop." << std::endl;
		mstack.push(5.3f);
		mstack.push(9.4f);
		mstack.push(747.7f);
		mstack.push(0.1f);
		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();
        std::cout << "First element: " << *it << std::endl;
        ++it;
        std::cout << "After iterating: " << *it << std::endl;
        --it;
		while (it != ite)
		{
			std::cout << *it << "f" << " - ";
			++it;
		}
		std::cout << std::endl;
		std::stack<float> s(mstack);
	}
	{
		std::cout << "\n\033[35m----- List <float> -----\033[0m" << std::endl;
		std::list<float> mstack;
		mstack.push_back(3.1f);         // Adds a new element at the end of the list container, after its current last element.
		mstack.push_back(-14.7f);
		std::cout << "\033[33m" << mstack.back() << "f" << " is the top element of the stack. From ";
		std::cout << mstack.size() << " elements in total.\033[0m" << std::endl;
        mstack.pop_back();              // Removes the last element in the list container, effectively reducing the container size by one.
		std::cout << mstack.size() << " elements in the stack after pop_back." << std::endl;
		mstack.push_back(5.3f);
		mstack.push_back(9.4f);
		mstack.push_back(747.7f);
		mstack.push_back(0.1f);
		std::list<float>::iterator it = mstack.begin();
		std::list<float>::iterator ite = mstack.end();
		std::cout << "First element: " << *it << std::endl;
        ++it;
        std::cout << "After iterating: " << *it << std::endl;
        --it;
		while (it != ite)
		{
			std::cout << *it << "f" << " - ";
			++it;
		}
        std::cout << std::endl;
	}
	return (0);
}
