/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:10:03 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 08:46:24 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class FragTrap: public ClapTrap {
        public:
        // Constructors
                FragTrap(void);
                FragTrap(const FragTrap &copy);
                FragTrap(std::string name);
        
        // Destructor
                ~FragTrap (void);
        
        // Overload Operator
                FragTrap &operator=(const FragTrap &src);
        
        // Member functions
                void    highFivesGuys(void);
        
        private:

};

#endif