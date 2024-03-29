/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:00:13 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:58:45 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>

class AMateria;

/*
* INTERFACE
*
* Interface classes inherit its functions to other classes; in the class itself nothing happens.
* 
* Its abstract class is Character.
*/
class ICharacter {
	    public:
		        virtual ~ICharacter() {}
		        virtual const std::string &getName() const = 0;
		        virtual void equip(AMateria *m) = 0;
		        virtual void unequip(int idx) = 0;
		        virtual void use(int idx, ICharacter &target) = 0;
                
};

#endif