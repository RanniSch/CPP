/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:08:58 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/13 09:07:05 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream> // needed for std
# include <string>

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