/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 09:21:20 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 18:57:40 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
* References and pointers are used to have one variable provide access to another.
* 
* A pointer is a variable that holds the memory address of another variable. 
* A pointer needs to be dereferenced with the * operator to access the memory location it points to.
* 
* A reference variable is an alias, that is, another name for an already existing variable. 
* A reference, like a pointer, is also implemented by storing the address of an object. A reference can be 
* thought of as a constant pointer with automatic indirection, i.e., the compiler will apply the * operator for you.
*
* A pointer has its own memory address and size on the stack, whereas a reference shares the same memory address 
* with the original variable but also takes up some space on the stack!
*/
int main(void)
{
    std::string brain;
    std::string *stringPTR;
    std::string &stringREF = brain;

    stringPTR = &brain; 

    brain = "HI THIS IS BRAIN";

    std::cout << "adress string: " << &brain << std::endl;
    std::cout << "  adress *ptr: " << &stringPTR << std::endl;
    std::cout << "  adress &ref: " << &stringREF << std::endl;
    std::cout << "" << std::endl;
    std::cout << " value string: " << brain << std::endl;
    std::cout << "   value *ptr: " << *stringPTR << std::endl;
    std::cout << "   value &ref: " << stringREF << std::endl;

    return (0);
}