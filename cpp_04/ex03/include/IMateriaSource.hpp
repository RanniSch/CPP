/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:02:14 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:37 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"

/*
* INTERFACE
*
* Interface classes inherit its functions to other classes; in the class itself nothing happens.
* 
* Its concrete class is MateriaSource.
*/
class IMateriaSource {
	    public:
		        virtual ~IMateriaSource() {};
		        virtual void learnMateria(AMateria *) = 0;
		        virtual AMateria *createMateria(const std::string &type) = 0;
};

#endif