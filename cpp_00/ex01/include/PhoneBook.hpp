/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:13:29 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/09 11:51:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>

class PhoneBook {
        private:
                Contact persons[8];     // instances for 8 Contact Classes
                int _num_entries;
                void    PhoneBook::replace_oldest_contact (void);
        
        public:
                PhoneBook (void);
                ~PhoneBook (void);

                void    PhoneBook::replace_oldest_contact (void);
                void    PhoneBook::new_contact_to_array (std::string in_first, std::string in_last, std::string in_nick, int in_num, std::string in_sec);
                void    PhoneBook::display_extract(void);
                void    PhoneBook::display_data(int user_index);
                        
};

#endif