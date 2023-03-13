/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:46:38 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 21:14:28 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
        private:
                std::string     _type;

        public:
                Weapon (std::string type);
                ~Weapon (void);

                const std::string &getType(void);
                void setType(std::string type);

};

#endif