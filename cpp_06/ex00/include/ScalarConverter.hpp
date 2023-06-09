/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 10:16:44 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/09 13:09:43 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

/*
* C++ standard header <limits> contains <climits> in which is <limits.h>. Doesn't work here!
*/
# include <limits> // for numeric_limits<char>::min() and numeric_limits<char>::max()
# include <climits> // for two macros INT_MAX and INT_MIN that represents the integer limits.
# include <iostream>
# include <string> // needed?
# include <cstring> // needed?
# include <cstdlib>
# include <cfloat> // for DBL_MIN, DBL_MAX
# include <iomanip> // for setprecision

enum Types
{
	NOT_VALID	=	-1,
	CHAR		=	0,
	INT			=	1,
	FLOAT		=	2,
	DOUBLE		=	3,
	NANx		=	4,
	INFx		=	5,
};

/*
* By default, constructors are defined in public section of class.
* A constructor can be defined in private section of class, if we want that
* should not be instantiated by anyone else but only by a friend class.
*
* Due to subject requirement "write a static class", which is misleading as
* a static class itself does not exist.
*
* Static private member variables are initialized in ScalarConverter.cpp at the top.
*/

class	ScalarConverter {
	    public:
		        // Destructor
		        ~ScalarConverter (void); // Destructor cannot be private, or it won't be called.

		        // Creators
		        static ScalarConverter *createInstance(void);
		        static ScalarConverter *createParameterizedInstance(std::string const &setInput);
		        static ScalarConverter *createDefaultCopyInstance(const ScalarConverter &copy);

                // Setter and Getter
		        static void				setInput(std::string setInput);
                static std::string		getInput(void);
		        static void				setType(Types setType);  
		        static Types			getType(void);        

		        // Member functions
		        static void	convert(std::string const &input);
                
                static void	checkType(std::string const &input);
                static void	createConv(std::string const &input);

                static bool	isChar(std::string const &input);
		        static bool	isInt(std::string const &input);
		        static bool	isFloat(std::string const &input);
		        static bool	isDouble(std::string const &input);

                static void	createConvFromNotValid(void);
		        static void	createConvFromChar(std::string const &input);
		        static void	createConvFromInt(std::string const &input);
		        static void	createConvFromFloat(std::string const &input);
		        static void	createConvFromDouble(std::string const &input);
		        static void	createConvFromNANx(std::string const &input);
		        static void	createConvFromINFx(std::string const &input);

	    private:
		        // Constructors
		        ScalarConverter(); // Constructors cannot be declared as static because they are responsible for initialization.
		        ScalarConverter(std::string const &setInput);
		        ScalarConverter(const ScalarConverter &copy);

		        // Overloaded Operator
		        ScalarConverter &operator=(const ScalarConverter &src);

		        // Private Attributes
		        static std::string	_input;
		        static Types		_type;
};

#endif