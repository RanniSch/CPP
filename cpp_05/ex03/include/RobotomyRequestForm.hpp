/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 07:48:49 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/06 10:24:07 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"                                                                                                                                                                  
# include "AForm.hpp"
# include <ctime> // for time function

class Bureaucrat;

class RobotomyRequestForm : public AForm {
        public:
                RobotomyRequestForm(void);
                RobotomyRequestForm(std::string target);
                RobotomyRequestForm(const RobotomyRequestForm &copy);
                ~RobotomyRequestForm (void);
                
                RobotomyRequestForm &operator=(const RobotomyRequestForm &src);

                void    execute(const Bureaucrat &obj) const;
                AForm	*clone(std::string target)const;

        private:
                std::string _target;

};

#endif