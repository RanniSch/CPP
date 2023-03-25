/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:37:43 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 07:58:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

/*
* BASE CLASS
*/
class WrongAnimal {
        public:
                // Constructors
                WrongAnimal(void);
                WrongAnimal(const WrongAnimal &copy);

                // Destructor
                virtual ~WrongAnimal (void);

                // Overloaded operator
                WrongAnimal &operator=(const WrongAnimal &src);

                // Member function
                virtual void makeSound(void)const;

                // Getter
                std::string getType(void)const;
        
        protected:
                std::string _type;

};

#endif