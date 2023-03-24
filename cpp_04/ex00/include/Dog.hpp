/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:54 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 18:10:06 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal {
        public:
                // Constructors
                Dog(void);
                Dog(const Dog &copy);

                // Destructor
                ~Dog (void);

                // Overloaded operator
                Dog &operator=(const Dog &src);

                // member functions
                void makeSound(void)const;

};

#endif