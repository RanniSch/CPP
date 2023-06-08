/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 10:00:01 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/08 10:04:31 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

/*
* Base class AForm must be an abstract class!
*
* An abstract class is a class that is designed to be specifically used as a base class.
* An abstract class contains at least one pure virtual function.
* You declare a pure virtual function by using a pure specifier ( = 0 ) in the declaration
* of a virtual member function in the class declaration.
*/
class AForm {
        public:
                // Constructors
                AForm(void);
                AForm(std::string name, int signit, int executeit);
                AForm (const AForm &copy);

                // Destructor
                virtual~AForm (void);  // virtual???

                // Overloaded Operator
                AForm &operator=(const AForm &src);

                // Member functions
                void            setForm(std::string typeForm);
                void            beSigned(const Bureaucrat &obj);
                virtual void    execute(const Bureaucrat &executor)const;
                virtual AForm*	clone(std::string target)const = 0;
                
                // Getter
                std::string     getName(void) const;
                bool            getSigned(void) const;
                unsigned int    signIt(void) const;
                unsigned int    executeIt(void) const;
                std::string     getFormType(void) const;

                class GradeTooHighException: public std::exception {
                        public:
                                virtual const char *what() const throw();
                };
                class GradeTooLowException: public std::exception {
                        public:
                                virtual const char *what() const throw();
                };
                class NotSignedYet : public std::exception {
		        public:
				virtual const char *what() const throw();
		};

        private:
                const std::string   _name;
                bool                _signed;
                const unsigned int  _signit;
                const unsigned int  _executeit;
                std::string         _formName;
                
                
};

std::ostream &operator<< (std::ostream &os, const AForm &copy);

#endif