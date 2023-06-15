/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 08:27:57 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 09:33:15 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

# include "easyfind.hpp"
# include <vector> // end()
# include <list> // for std::list in main
# include <algorithm> // find()


/*
* A container is a holder object that stores a collection of other objects (its elements). They are implemented as class templates, which allows a great flexibility in the types supported as elements.
* The container manages the storage space for its elements and provides member functions to access them, either directly or through iterators (reference objects with similar properties to pointers).
* Containers replicate structures very commonly used in programming: dynamic arrays (vector), queues (queue), stacks (stack), heaps (priority_queue), linked lists (list), trees (set), associative arrays (map)...
*
* class template iterator
* Iterators act as a bridge that connects algorithms to STL containers and allows the modifications of the data present inside the container.
* It's a base class template that can be used to derive iterator classes from it. It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
*
* find(first_element, last_element, value we want to search)
* Used to search an element inside a specified range and returns the first occurrence of the element.
* It returns the first occurrence of the element searched inside a specified range.
* If the element is not found after all possible comparisons, it returns the last element of the specified range.
* If any unessential action is performed by the find() function then it throws an exception that is not required by the programmer.
*
* function template std::begin()
* returns an iterator pointing to the first element in the sequence. In Container it returns cont.begin().
*
* public member function end()
* Returns an iterator referring to the past-the-end element in the vector container, which is the theoretical element that would follow the last element in the vector.
* It does not point to any element, and thus shall not be dereferenced.
* Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with vector::begin to specify a range including all the elements in the container.
* If the container is empty, this function returns the same as vector::begin.
*
* function template std::distance
* Calculates the number of elements between first and last.
*/

template    < typename T >
long    easyfind(T &container, int tofind)
{
    typename T::iterator it = std::find(container.begin(), container.end(), tofind);
    if (*it == tofind)  // it != container.end() would be also correct, as it would be the past-the-end element.
    {
        std::cout << "Found it!" << std::endl;
        return (std::distance(container.begin(), it)); // to get the index
    }
    else
        throw NotFoundException();
}

#endif