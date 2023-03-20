/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:39 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/20 20:09:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
        public:
                Fixed(void); // Constructor (Default constructor)
                ~Fixed (void); // Destructor

                Fixed(const Fixed &copy); // Copy constructor is defined by using as argument a reference to an object of the same class.
		        Fixed& operator=(const Fixed &src); // copy assignment operator 'overload' (i.e. each of those member functions here constructor, destructor and so on are overloads...). variable src refers to right-hand-side -> what is being passed in as an argument is the right-hand-side of the '=' statement. (fpn2 in this case ll. 23 in main.cpp).

                
                int getRawBits(void) const;
                void setRawBits(int const raw);

        private:
                int                 _fpValue;
                static const int    _fracBits = 8;

};

#endif