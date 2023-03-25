/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:24:54 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:43:47 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <stdlib.h>

/*
* DERIVED CLASS with its BASE CLASS Animal.
* Dog class can overwrite animal noise of Animal class.
* Dog Class needs Brain class to think, so include here.
*/
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

                // getter
                void getIdeas(size_t i)const;

                // setter
                void setIdeas(size_t i, std::string idea);

        private:
                Brain *_brain;
};

#endif