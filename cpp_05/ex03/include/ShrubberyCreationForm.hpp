/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 11:05:33 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:18:30 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"                                                                                                                                                                  
# include "AForm.hpp"
# include <fstream> // for std::ofstream -> file execution

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
        public:
                ShrubberyCreationForm(void);
                ShrubberyCreationForm(std::string target);
                ShrubberyCreationForm(const ShrubberyCreationForm &copy);
                ~ShrubberyCreationForm (void);
                
                ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

                void    execute(const Bureaucrat &obj) const;
                AForm	*clone(std::string target)const;

        private:
                std::string _target;

};

#endif