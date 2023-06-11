/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 22:58:56 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/11 09:55:01 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

class Awesome
{
	public:
	Awesome( void ) : _n( 42 ) { return; }
	int get( void ) const { return this->_n; }
	private:
	int _n;
};

std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }


int main(void)
{
	{
		std::cout << "\n\033[32m----- My Test -----\033[0m\n" << std::endl;
		int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
        //double array[8] = {-3.789, 1.05, 0.8, 200.1, 42, 42, 42, 42};

		std::cout << "Elements of array:" << std::endl;
		for (int i = 0; i < 8; i++)
			std::cout << array[i] << "  ";
		std::cout << std::endl;
		std::cout << "\033[32mOutput of function template iter:\033[0m" << std::endl;
		iter(array, 8, myPrint);
	}
    
    {
		std::cout << "\n\033[32m----- Eval Sheet test -----\033[0m\n" << std::endl;
		int tab[] = { 0, 1, 2, 3, 4 };
		Awesome tab2[5];

		iter(tab, 5, print<int>);
		iter(tab2, 5, print<Awesome>);
	}
    
    return (0);
}
