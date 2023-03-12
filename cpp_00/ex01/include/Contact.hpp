/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:01:41 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/12 13:18:44 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {
        private:
                std::string    _firstname;       // initialization in constructor automatically done and set to NULL
                std::string    _lastname;
                std::string    _nickname;
                std::string    _phonenumber;
                std::string    _secret;


        public:
                int     c_index;        // countet from 0 till 7, so for SEARCH user input + 1
                Contact (void);
                ~Contact (void);    // destructor

                void    adddata(int index, std::string in_first, std::string in_last, std::string in_nick, std::string in_num, std::string in_sec);
                void    putextract(void);
                void    putdata(void);
                
};

#endif