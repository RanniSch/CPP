/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:32:07 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:17:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include <iostream>

/*
* Derived class from its base class AMateria.
*/
class Cure : public AMateria {
	    public:
		        Cure();
		        Cure(const Cure &copy);
		        ~Cure();

		        Cure& operator=(const Cure &src);

		        AMateria *clone() const;
		        void use(ICharacter &target);

};

#endif