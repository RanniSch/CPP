/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:48:33 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/15 17:31:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <cstdlib> // for srand() and rand()
#include <algorithm> // for sort
#include <vector> // for vector
#include <numeric> // for adjacent_difference

class Span {
		public:
				// Constructors
				Span(void);
				Span(unsigned int N);
				Span(const Span &copy);
		
				// Destructor
				~Span (void);

				// Overload operator
				Span &operator=(const Span &src);
		
				// Getter
				//int	getN(void);

				// Member functions
				void	addNumber(int setValue);
				void	betterAddNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
				int		shortestSpan(void);
				int		longestSpan(void);

				void	printArrayElements(void);

				// Exception
				class CollectionFullException : public std::exception {
					public:
						virtual const char* what() const throw();
				};

		private:
				unsigned int		_N; // max number of elements in the Span
				std::vector<int>	_collection; // std::vector is a sequence container that encapsulates dynamic size arrays
		
};

#endif