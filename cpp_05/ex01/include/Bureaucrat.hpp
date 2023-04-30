/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:22:38 by rschlott          #+#    #+#             */
/*   Updated: 2023/04/30 13:48:21 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {
        public:
                // Constructors
                Bureaucrat();
                Bureaucrat(std::string name, unsigned int grade); // const: Wert wird zugewiesen und kann nicht geändert werden; bleibt const.
                Bureaucrat(const Bureaucrat &copy);

                // Destructor
                ~Bureaucrat (void);

                // Overloaded Operator
                Bureaucrat &operator=(const Bureaucrat &src);
                
                // Member functions
                void increment();
                void decrement();
                void signForm(Form &form);
                
                // Getter
                std::string     getName() const;
                unsigned int    getGrade() const;

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
                unsigned int        _grade;
};

std::ostream &operator<< (std::ostream &os, const Bureaucrat &copy);

#endif