/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:00:01 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/30 13:48:24 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
        public:
                // Constructors
                Form(void);
                Form(std::string name, int signit, int executeit);
                Form (const Form &copy);

                // Destructor
                ~Form (void);

                // Overloaded Operator
                Form &operator=(const Form &src);

                // Member functions
                void beSigned(const Bureaucrat &copy);
                
                // Getter
                std::string     getName(void) const;
                bool            getSigned(void) const;
                unsigned int    signIt(void) const;
                unsigned int    executeIt(void) const;

                class GradeTooHighException: public std::exception {
                    public:
                        virtual const char *what() const throw();
                };
                class GradeTooLowException: public std::exception {
                    public:
                        virtual const char *what() const throw();
                };

        private:
                const std::string   _name;
                bool                _signed;
                const unsigned int  _signit;
                const unsigned int  _executeit;
                
                
};

std::ostream &operator<< (std::ostream &os, const Form &copy);

#endif