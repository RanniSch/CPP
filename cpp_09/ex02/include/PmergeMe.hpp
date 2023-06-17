/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:29:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 09:25:04 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
//# include <string>
# include <cctype>      // for isdigit()
# include <climits>     // for INT_MIN and INT_MAX
# include <algorithm>
# include <cstring>
# include <vector>      // for vector container
# include <list>
# include <deque>       // for deque container
# include <set>         // for set() to check for duplicates
# include <iomanip>     // for setprecision
# include <sys/time.h>

// using vector container in this exercise
// using deque container in this exercise
// DIFFERENCES
// As opposed to std::vector, the elements of a deque are not stored contiguously: typical implementations use a sequence of 
// individually allocated fixed-size arrays, with additional bookkeeping, which means indexed access to deque must perform
// two pointer dereferences, compared to vector's indexed access which performs only one.
// The storage of a deque is automatically expanded and contracted as needed. Expansion of a deque is cheaper than the expansion
// of a std::vector because it does not involve copying of the existing elements to a new memory location. On the other hand,
// deques typically have large minimal memory cost; a deque holding just one element has to allocate its full internal array.

class	PmergeMe {
	    private:
		        std::vector<int>	_inputVector;       // std::vector is a sequence container that encapsulates dynamic size arrays.
		        std::deque<int>		_inputDeque;        // std::deque (double-ended queue) is an indexed sequence container that allows fast insertion and deletion at both its beginning and its end.
		        void				addNumToVector(int numValue);
		        void				addNumToDeque(int numValue);
	
        public:
		        // Constructors
                PmergeMe(void);
		        PmergeMe(const PmergeMe& copy);

                // Destructor
                ~PmergeMe (void);

                // Overload operator
		        PmergeMe& operator=(const PmergeMe& src);
		        
                // Getters
                std::vector<int>&	getVector(void);
		        std::deque<int>&	getDeque(void);

		        // Member functions
                void				storeCollection(int argc, char **argv);
                bool				checkNoDuplicate(void);
        
		void				printVector();
		void				printDeque();
		
		template <typename T>
		void	insertionSort(T& A, int first, int middle)
		{
			for (int i = first; i < middle; i++)
			{
				int tempVal = A[i + 1];
				int j = i + 1;
				while (j > first && A[j - 1] > tempVal)
				{
					A[j] = A[j - 1];
					j--;
				}
				A[j] = tempVal;
			}
		}

		template <typename T>
		void	merge(T& A, int first, int middle, int last)
		{
			int n1 = middle - first + 1; // length of left array n1 = 3
			int n2 = last - middle; // length of right array  n2 = 2
			int LA[n1]; // declare Left Array
			int RA[n2]; // declare Right Array
			for (int i = 0; i < n1; i++) // copy values from A into LA
				LA[i] = A[first + i];
			for (int i = 0; i < n2; i++) // copy values from A into RA
				RA[i] = A[middle + 1 + i];
			int RIDX = 0; // right index
			int LIDX = 0; // left index
			for (int i = first; i <= last; i++)
			{
				if (RIDX == n2) // reached end of right hand side Array
				{
					A[i] = LA[LIDX]; // left hand side index into A[i]
					LIDX++;
				}
				else if (LIDX == n1)
				{
					A[i] = RA[RIDX];
					RIDX++;
				}
				else if (RA[RIDX] > LA[LIDX]) // not true for RA{2} LA{5}
				{
					A[i] = LA[LIDX];
					LIDX++;
				}
				else // We are copying the SMALLEST value into A[i]
				{
					A[i] = RA[RIDX]; // A[0] = RA[0] => A = {2, 4, 3, 2, 1}
					RIDX++;
				}
			}
		}

		template <typename T>
		void mergeSort(T& A, int first, int last)
		{
			int n = last - first + 1;
			if (n > 2) // K == 2 since we want to pair the values into sub-arrays of size 2
			{
				int middle = (first + last) / 2; // 1st. iteration q = 0 + n - 1 / 2
				mergeSort(A, first, middle); // 2nd. sort it 0 -> middle | left hand side
				mergeSort(A, middle + 1, last); // 3rd. it middle -> n - 1 | right hand side
				merge(A, first, middle, last);
			}
			else
				insertionSort(A, first, last);
		}
};

// Functions outside the class
bool		isDigit(char *s);
bool		inRange(char *s);
bool		isDigitAndInRange(int argc, char **argv);
bool		validInput(int argc, char **argv);

#endif