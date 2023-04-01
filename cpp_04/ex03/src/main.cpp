/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:30:50 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:37:58 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

#include <iostream>

int main()
{
	// SUBJECT TEST
    std::cout << "\nSUBJECT TEST:\n" << std::endl;

    IMateriaSource *src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter *me = new Character("me");

	AMateria *tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter *bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	// OWN TEST
	std::cout << "\nOWN TESTS:\n" << std::endl;

	me->unequip(1);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip(1);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl;

	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	// DELETING STAYS THE SAME LIKE IN SUBJECT TEST

	delete (bob);
	delete (me);
	delete (src);

	return (0);
}
