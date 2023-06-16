/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:41:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/16 08:48:06 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>

template < typename T > 
class MutantStack : public std::stack < T > { //MutantStack will also inherit (implicitly) the template argument T
	    public:
		        // Constructors
		        MutantStack(void);
		        MutantStack(const MutantStack &copy);

                // Destructor
		        ~MutantStack (void);
		
		        // Overload operator
		        MutantStack &operator=(const MutantStack &src);

		        /*
                * Iterator typedefs
                * A typedef declaration may declare one or many identifiers on the same line.
                * typedef is used to create an alias for : iterator, const_iterator etc.
                */
                typedef typename std::stack<T>::container_type::iterator iterator;
		        typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		        typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		        typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		        iterator begin();
		        iterator end();
		        const_iterator begin() const;
		        const_iterator end() const;
		        reverse_iterator rbegin();
		        reverse_iterator rend();
		        const_reverse_iterator rbegin() const;
		        const_reverse_iterator rend() const;

};

#endif