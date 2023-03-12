/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:08:58 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 20:46:37 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream> // needed for std

class Zombie {
        private:
                std::string     _name;
        
        public:
                Zombie(std::string name);
                ~Zombie (void);

                void    announce(void);   

};

#endif