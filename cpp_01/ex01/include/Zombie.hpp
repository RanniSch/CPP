/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:08:58 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/17 07:15:00 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> // needed for std
# include <string> // only needed when not writing std::

class Zombie {
        private:
                std::string     _name;
        
        public:
                Zombie(void);
                ~Zombie (void);

                void    announce(void);
                void    setName(std::string name); 

};

#endif