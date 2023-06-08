/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 08:50:15 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 11:21:41 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"                                                                                                                                                                  
# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
        public:
                PresidentialPardonForm(void);
                PresidentialPardonForm(std::string target);
                PresidentialPardonForm(const PresidentialPardonForm &copy);
                ~PresidentialPardonForm (void);
                
                PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

                void    execute(const Bureaucrat &obj) const;
                AForm	*clone(std::string target)const;

        private:
                std::string _target;

};

#endif