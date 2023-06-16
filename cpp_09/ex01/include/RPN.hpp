/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 23:23:39 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 00:24:56 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>   // for stack template

class RPN {
	    public:
		        // Constructor
                RPN(void);

                // Destructor
		        ~RPN (void);

                // Public member function
		        int		calculate(const std::string input);
        
        private:
		        std::stack<int>		_I;
		        std::stack<char>	_C;
		        std::string			_input;
		        
                // Copy constructor
                RPN(const RPN& copy);

                // Overload operator
		        RPN& 	operator=(const RPN& src);

                // Private member functions
		        int		inputCheck(const std::string input);
		        int		operate(void);
		        void	printResult(void);
             
};

#endif