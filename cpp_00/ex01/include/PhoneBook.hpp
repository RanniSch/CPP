/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:13:29 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/10 11:29:36 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"

class PhoneBook {
        private:
                Contact     persons[8];     // instances for 8 Contact Classes
                int         _num_entries;
                void        _replace_oldest_contact (void);
                void        _new_contact_to_array (std::string in_first, std::string in_last, std::string in_nick, int in_num, std::string in_sec);
        
        public:
                PhoneBook (void);
                ~PhoneBook (void);

                void        input_data(void);
                bool        display_extract(void);
                bool        display_data(std::string user_input);
                void	    show_instruction(void);
                        
};

#endif