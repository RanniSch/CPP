/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 08:20:26 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/22 20:56:42 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {
        public:
                // Constructors
                ClapTrap(void);
                ClapTrap(std::string name);
                ClapTrap(const ClapTrap &copy);

                // Destructor
                ~ClapTrap (void);

                // Overloaded operator
                ClapTrap& operator=(const ClapTrap &src);

                // member functions
                void attack(const std::string &target);
                void takeDamage(unsigned int amount);
                void beRepaired(unsigned int amount);
        
        private:
                std::string     _name;
                unsigned int    _hitPoints;
                unsigned int    _energyPoints;
                unsigned int    _attackDamage;

};

#endif