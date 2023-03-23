/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 07:49:35 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/23 10:08:36 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
            public:
            // Constrcutors
                    ScavTrap(void);
                    ScavTrap(const ScavTrap &copy);
                    ScavTrap(std::string name);

            // Destructor
                    ~ScavTrap (void);
            
            // Overload Operator
                    ScavTrap &operator=(const ScavTrap &src);

            // Member functions
                    void attack(const std::string &target);
                    void guardGate(void);
            
            private:
                    bool _guardingGate;

};

#endif