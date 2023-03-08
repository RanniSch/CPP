/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:01:41 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 15:08:50 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
        private:
                std::string    _firstname;       // initialization in constructor
                std::string    _lastname;
                std::string    _nickname;
                int     _phonenumber;
                std::string    _secret;


        public:
                //Contact (std::string input_firstname, std::string input_lastname);     // constructor
                Contact (void);
                ~Contact (void);    // destructor

                void    getdata();
                void    putdata();

                bool    c_exists;
};

#endif