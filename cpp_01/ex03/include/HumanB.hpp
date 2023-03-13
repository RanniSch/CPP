/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:56:40 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 21:14:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {
        private:
                Weapon          *_weapon;
                std::string     _nameB;
                bool            _is_armed;
        
        public:
                HumanB (std::string name);
                ~HumanB (void);
                
                void setWeapon(Weapon &weapon);
                void attack(void);

};

#endif