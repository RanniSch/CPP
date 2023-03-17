/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:16 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/17 21:57:32 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <fstream>

class Harl {
        private:
                void _debug(void);
                void _info(void);
                void _warning(void);
                void _error(void);
                void	(Harl::*_function)(void);
        
        public:
                Harl(void);
                ~Harl (void);

                void complain(std::string level);

};

#endif