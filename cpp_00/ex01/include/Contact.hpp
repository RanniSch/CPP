/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 09:01:41 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/08 10:15:25 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact {
        private:
                char    _firstname;       // initialization in constructor
                char    _lastname;
                //char    _nickname[10];
                //int     _phonenumber;
                //char    _secret[20];


        public:
                Contact (char input_firstname, char input_lastname);     // constructor
                ~Contact (void);    // destructor

                //void    getdata();
                //void    putdata();
};

#endif