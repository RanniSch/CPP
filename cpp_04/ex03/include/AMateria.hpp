/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:23:43 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:03 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include "ICharacter.hpp"
# include <iostream>

class ICharacter;

/*
* BASE CLASS
* 
* The C++ interfaces are implemented using abstract classes.
* A class is made abstract by declaring at least one of its functions as pure 
* virtual function. A pure virtual function is specified by placing "= 0" in its declaration.
* 
* An abstract class is meant to be used as a base class where some or all functions are declared
* purely virtual and hence can not be instantiated.
*
* Interface classes inherit its functions to other classes; in the class itself nothing happens.
*/
class AMateria {
	    public:
		        AMateria(const std::string& type);
		        virtual ~AMateria();

		        const std::string& getType() const; // return the materia type

		        virtual AMateria* clone() const = 0;
		        virtual void use(ICharacter &target);
	    
        protected:
		        std::string _type;
	    
        private:
		        AMateria();

};

#endif