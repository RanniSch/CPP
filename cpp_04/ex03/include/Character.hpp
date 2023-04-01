/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:48:21 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/01 19:53:17 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <iostream>

/*
* ABSTRACT CLASS
*
* Its interface is ICharacter
*
* The Character possesses an inventory of 4 slots = 4 Materias at most. Inventory is empty at construction. 
* They equip the Materias in the first empty slot they find, in this order: from slot 0 to slot 3. In case they try to add
* a Materia to a full inventory, or use/unequip an unexisting Materia -> nothing happens. 
* The unequip() member function must NOT delete the Materia.
*
* use(int, ICharacter&) has to use the Materia at the slot[idx], and pass the target parameter to the AMateria::use function.
*
* [ICharacter in use() function in AMateria, Cure and Ice]
*/
class Character : public ICharacter {
	    public:
		        Character(const std::string &name);
		        Character(const Character &copy);
		        ~Character();

		        Character& operator=(const Character &src);

		        const std::string &getName() const;
		        void equip(AMateria *m);
		        void unequip(int idx);
		        void use(int idx, ICharacter& target);
	    private:
		        Character();

		        static const int kInventorySize = 4;

		        std::string _name;
		        AMateria *_inventory[Character::kInventorySize];
		        int _nEquiped;
                
};

#endif