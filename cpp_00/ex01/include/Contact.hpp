/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:01:41 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 11:51:38 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
        private:
                std::string    _firstname;       // initialization in constructor automatically done and set to NULL
                std::string    _lastname;
                std::string    _nickname;
                int     _phonenumber;
                std::string    _secret;


        public:
                int     c_index;        // countet from 1 till 8 for SEARCH
                Contact (void);
                ~Contact (void);    // destructor

                void    adddata(int index, std::string in_first, std::string in_last, std::string in_nick, int in_num, std::string in_sec);
                void    putextract(void);
                void    putdata(void);
                
};

#endif