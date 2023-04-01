/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:18:43 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:26:51 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

// Constructors
MateriaSource::MateriaSource(): _nLearned(0)
{
	for (int i = 0; i < MateriaSource::kMateriaSize; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &copy) 
{
	*this = copy;
}

// Destructor
MateriaSource::~MateriaSource() 
{
	for (int i = 0; i < MateriaSource::kMateriaSize; i++) 
    {
		if (this->_materias[i] != NULL)
			delete (this->_materias[i]);
	}
}

// Overloaded operator
MateriaSource& MateriaSource::operator=(const MateriaSource &src)
{
	this->_nLearned = src._nLearned;

	for (int i = 0; i < MateriaSource::kMateriaSize; i++)
    {
		if (this->_materias[i] != NULL)
			delete (this->_materias[i]);
		if (src._materias[i] != NULL)
			this->_materias[i] = src._materias[i]->clone();
        else
			this->_materias[i] = NULL;
	}
	return (*this);
}

// Public member functions
void MateriaSource::learnMateria(AMateria *materia)
{
	if (this->_nLearned < MateriaSource::kMateriaSize)
    {
		this->_materias[this->_nLearned] = materia;
		this->_nLearned++;
	}
}

AMateria *MateriaSource::createMateria(const std::string &type)
{
	for (int i = 0; i < MateriaSource::kMateriaSize; i++)
    {
		if (this->_materias[i]->getType() == type)
        {
			return (this->_materias[i]->clone()); // deep copy
			//return (this->_materias[i]); // shallow copy
		}
	}
	return (NULL);
}
