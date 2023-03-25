/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:22:35 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:42:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <stdlib.h>

/*
* DERIVED CLASS with its BASE CLASS Animal.
* Cat class can overwrite animal noise of Animal class.
* Cat Class needs Brain class to think, so include here.
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

                // getter
                void getIdeas(size_t i)const;

                // setter
                void setIdeas(size_t i, std::string idea);

        private:
                Brain *_brain;

};

#endif