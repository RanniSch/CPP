/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:16:14 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 07:54:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/*
* BASE CLASS 
*
* The word “polymorphism” means having many forms. In simple words, we can define 
* polymorphism as the ability of a message to be displayed in more than one form.
* 
* A virtual function is a member function which is declared within a base class 
* and is re-defined (overridden) by a derived class. When you refer to a derived
* class object using a pointer or a reference to the base class, you can call a 
* virtual function for that object and execute the derived class’s version of the function. 
*/
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