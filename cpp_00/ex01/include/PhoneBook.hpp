/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:13:29 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/11 17:50:27 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <stdlib.h>
#include "Contact.hpp"

class PhoneBook {
        private:
                Contact         persons[8];     // instances for 8 Contact Classes
                std::string     _user_input;
                int             _num_entries;
                void            _replace_oldest_contact (void);
                void            _new_contact_to_array (std::string in_first, std::string in_last, std::string in_nick, std::string in_num, std::string in_sec);
                bool            _display_extract(void);
                bool            _display_data(std::string user_input);

        public:
                PhoneBook (void);
                ~PhoneBook (void);

                int         input_data(void);
                void        search_data(void);
                void	    show_instruction(void);
                        
};

#endif