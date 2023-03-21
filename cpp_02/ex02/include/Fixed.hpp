/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 22:06:39 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/21 08:10:20 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> // for roundf function

class Fixed {
        public:
                // Constructors
                Fixed(void);
                Fixed(const int input);
                Fixed(const float input);
                Fixed(const Fixed &copy);
		
                // Destructor
                ~Fixed (void);
                
                // Overloaded operator
                Fixed& operator=(const Fixed &src);

                // Comparison operators
                bool operator>(Fixed fixed)const;
                bool operator<(Fixed fixed)const;
                bool operator>=(Fixed fixed)const;
                bool operator<=(Fixed fixed)const;
                bool operator==(Fixed fixed)const;
                bool operator!=(Fixed fixed)const;

                // Arithmetic operators
                float operator+(Fixed fixed)const;
                float operator-(Fixed fixed)const;
                float operator*(Fixed fixed)const;
                float operator/(Fixed fixed)const;

                // pre-increment/pre-decrement operators
                Fixed operator++(void);
                Fixed operator--(void);

                // post-increment/post-decrement operators
                Fixed operator++(int);
                Fixed operator--(int);

                // member functions (public methods)
                float toFloat(void) const;
                int toInt(void) const;
                static Fixed &min(Fixed &first, Fixed &second);
		static const Fixed &min(Fixed const &first, Fixed const &second);
		static Fixed &max(Fixed &first, Fixed &second);
		static const Fixed &max(Fixed const &first, const Fixed &second);

                int getRawBits(void) const; // getter
                void setRawBits(int const raw); // setter

        private:
                int                 _fpValue;
                static const int    _fracBits = 8;

};

// add to fixed class files: overload for ostream
std::ostream    &operator<<(std::ostream &ostream, Fixed const &myClass);

#endif