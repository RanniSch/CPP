/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 09:29:52 by rschlott          #+#    #+#             */
/*   Updated: 2023/05/06 10:10:58 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern {
	    public:
		        Intern(void);
		        Intern(const Intern &copy);
                ~Intern (void);
		        
                Intern &operator=(const Intern &src);
		        
		        void	hm() const;
                AForm *makeForm(std::string const name, std::string const target); // name of the form and name of the target(f.e. test1)

                class InvalidFormException : public std::exception {
			            public:
                                virtual const char* what() const throw();
		        };

        private:
};

#endif