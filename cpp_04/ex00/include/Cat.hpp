/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:22:35 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 09:58:59 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

/*
* DERIVED CLASS with its BASE CLASS Animal. Cat class can overwrite animal noise of Animal class.
*/
class Cat: public Animal {
        public:
                // Constructors
                Cat(void);
                Cat(const Cat &copy);

                // Destructor
                ~Cat (void);

                // Overloaded operator
                Cat &operator=(const Cat &src);

                // member functions
                void makeSound(void)const;

};

#endif