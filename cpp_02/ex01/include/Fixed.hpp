/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:39 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/21 07:31:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // for roundf function

class Fixed {
        public:
                // Constructors
                Fixed(void); // Constructor (Default constructor)
                Fixed(const int input);
                Fixed(const float input);
                Fixed(const Fixed &copy); // Copy constructor is defined by using as argument a reference to an object of the same class.
		
                // Destructor
                ~Fixed (void);
                
                // Overloaded operator
                Fixed& operator=(const Fixed &src); // copy assignment operator 'overload' (i.e. each of those member functions here constructor, destructor and so on are overloads...). variable src refers to right-hand-side -> what is being passed in as an argument is the right-hand-side of the '=' statement. (fpn2 in this case ll. 23 in main.cpp).

                // member functions
                float toFloat(void) const; // public method
                int toInt(void) const; // public method
                int getRawBits(void) const; // getter
                void setRawBits(int const raw); // setter

        private:
                int                 _fpValue;
                static const int    _fracBits = 8;

};

// add to fixed class files: An overload of the insertion («) operator that inserts a floating-point representation
// of the fixed-point number into the output stream object passed as parameter
std::ostream    &operator<<(std::ostream &ostream, Fixed const &myClass);

#endif