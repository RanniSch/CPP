/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:14 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 18:06:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
        public:
                // Constructors
                Animal(void);
                Animal(const Animal &copy);

                // Destructor
                virtual ~Animal (void);

                // Overloaded operator
                Animal &operator=(const Animal &src);

                // Member function
                virtual void makeSound(void)const;

                // Getter
                std::string getType(void)const;
        
        protected:
                std::string _type;

};

#endif