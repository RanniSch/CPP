/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:20:26 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/23 10:08:34 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <iomanip>

/*
* public class members are available to everyone. The data members and member 
* functions declared public can be accessed by other classes too. 
* The public members of a class can be accessed from anywhere in the program
* using the direct member access operator (.) with the object of that class.
*
* Protected access modifier is similar to that of private access modifiers,
* the difference is that the class member declared as Protected are inaccessible 
* outside the class but they can be accessed by any subclass(derived class) of that class.
*
* Deleting a ScavTrap class object using a pointer of ClapTrap class type that
* has a non-virtual destructor results in undefined behavior. To correct this 
* situation, the clapTrap class should be defined with a virtual destructor.
*/
class ClapTrap {
        public:
                // Constructors
                ClapTrap(void);
                ClapTrap(std::string name);
                ClapTrap(const ClapTrap &copy);

                // Destructor
                virtual ~ClapTrap (void);

                // Overloaded operator
                ClapTrap& operator=(const ClapTrap &src);

                // member functions
                void attack(const std::string &target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);

                void	status(void) const;
        
        protected:
                std::string     _name;
                unsigned int    _hitPoints;
                unsigned int    _energyPoints;
                unsigned int    _attackDamage;

};

void	print_table(void);

#endif