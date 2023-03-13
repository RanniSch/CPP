/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:53:10 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 21:14:39 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {
        private:
                Weapon          &_weapon;
                std::string     _nameA;
        
        public:
                HumanA (std::string name, Weapon &weapon);
                ~HumanA (void);
                
                void attack(void);

};

#endif