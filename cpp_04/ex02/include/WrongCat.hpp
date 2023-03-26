/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:39:19 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 16:26:34 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

/*
* DERIVED CLASS with its BASE CLASS WrongAnimal.
* WrongCat class can overwrite animal noise of WromgAnimal class.
*/
class WrongCat: public WrongAnimal {
        public:
                // Constructors
                WrongCat(void);
                WrongCat(const WrongCat &copy);

                // Destructor
                ~WrongCat (void);

                // Overloaded operator
                WrongCat &operator=(const WrongCat &src);

                // member functions
                void makeSound(void)const;

};

#endif