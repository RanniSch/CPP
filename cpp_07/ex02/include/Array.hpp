/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:16:25 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/11 10:47:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

/*
* syntax / semantics for a “class template”:
* template<typename T>
* class Array {
* }
* 
* Having a container class Array that acts like an array of integers. Similar code for Array of float, of char, of std::string, of Array-of-std::string, etc.
* Adding the template<typename T> before the class definition (the T can be any identifier you want).
* Then, instead of using int or float or char where referring to the data type, you use T instead. 
* Also, instead of just referring to the class as Array, it’s Array<T> when referring to the template, or Array<int>, Array<float>, etc. when referring to a specific instantiation.
* Just as with a normal class, you can optionally define your methods outside the class.
*
* Unlike template functions, template classes (instantiations of class templates)
* need to be explicit about the parameters over which they are instantiating when f.e. calling in main: Array<int>  ai;
* https://isocpp.org/wiki/faq/templates#class-templates
*/

template < class T >
class Array {
        public:
		        // Constructors
		        Array();
		        Array(unsigned int n);
		        Array(const Array &copy);
		        
                // Destructor
                ~Array (void);

		        // Overloaded operators
		        Array &operator=(const Array &src);
		        T &operator[](unsigned int index);

		        // Getter
		        unsigned int	size(void);

		        // Member function
		        void    printArrayElements(void);

		        // Exception
                class OutOfRangeException : public std::exception {
			        public:
				        virtual const char* what() const throw();
		        };

	    private:
		        unsigned int    _size;
		        T				*_array;
                
};

#endif