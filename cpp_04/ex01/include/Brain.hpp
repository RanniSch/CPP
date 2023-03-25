/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:10:26 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 15:42:19 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

/*
* BASE CLASS 
*
* Overloaded operator
*
* In Deep copy, an object is created by copying data of all variables, and it also allocates
* similar memory resources with the same value to the object. In order to perform Deep copy,
* we need to explicitly define the copy constructor and assign dynamic memory as well, if required.
* Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
*/
class Brain {
        public:
            // Constructors
            Brain(void);
            Brain(const Brain &copy);

            // Destructor
            ~Brain (void);

            // Overloaded operator
            Brain &operator=(const Brain &src);

            // getter
            const std::string getIdea(size_t i)const;
            const std::string *getIdeaAddress(size_t i)const;

            // setter
            void setIdea(size_t i, std::string idea);

        private:
            std::string _ideas[100];

};

#endif