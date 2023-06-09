/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:25:36 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 19:25:45 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
//# include <string>
//# include <cstdlib>
# include <stdint.h> // for uintptr_t; This expression requires compiler and library support for the ISO C++ 2011 standard.

struct  Data
{
	    std::string	    stringValue;
	    int			    intValue;
};

/*
* uintptr_t 
* is an unsigned integer type that is capable of storing a data pointer
* (whether it can hold a function pointer is unspecified).
* Which typically means that it's the same size as a pointer. It is optionally defined in C++11 and later standards.
* A common reason to want an integer type that can hold an architecture's pointer type is to perform
* integer-specific operations on a pointer, or to obscure the type of a pointer by providing it as an integer "handle".
*/
class	Serializer {
	    public:
		        // Constructors
		        Serializer(void);
		        Serializer(const Serializer &copy);

                // Destructor
		        ~Serializer (void);

		        // Overloaded Operator
		        Serializer &operator=(const Serializer &src);

				// Member Functions
		        static uintptr_t	serialize(Data *ptr);
		        static Data         *deserialize(uintptr_t raw);
};

#endif