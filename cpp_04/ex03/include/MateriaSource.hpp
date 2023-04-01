/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:12:58 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:51:50 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

/*
* CONCRETE CLASS
*
* A concrete class is an ordinary class which has no purely virtual functions and hence can be instantiated.
*
* This concrete class implements the interface IMaterialSource.
*/
class MateriaSource : public IMateriaSource {
	    public:
		        MateriaSource();
		        MateriaSource(const MateriaSource &copy);
		        ~MateriaSource();

		        MateriaSource& operator=(const MateriaSource &src);

		        void learnMateria(AMateria *materia);
		        AMateria* createMateria(const std::string &type);
	    
        private:
		        static const int kMateriaSize = 4;

		        AMateria *_materias[MateriaSource::kMateriaSize];
		        int _nLearned;
                
};

#endif