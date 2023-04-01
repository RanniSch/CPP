/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:35:29 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:17:06 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include <iostream>

/*
* Derived class from its base class AMateria.
*/
class Ice : public AMateria {
	    public:
		        Ice();
		        Ice(const Ice &copy);
		        ~Ice();

		        Ice& operator=(const Ice &src);

		        AMateria *clone() const;
		        void use(ICharacter &target);
                
};

#endif