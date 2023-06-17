/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 00:29:27 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/17 17:24:20 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cctype>      // for isdigit()
# include <climits>     // for INT_MIN and INT_MAX
# include <algorithm>   // for strtol() and atoi()
# include <cstring>     // for strlen()
# include <vector>      // for vector container
//# include <list>
# include <deque>       // for deque container
# include <set>         // for set() to check for duplicates
# include <iomanip>     // for std::setprecision in main
# include <sys/time.h>  // for timeval struct

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
        
		        void				printVector(void);
		        void				printDeque(void);
		
		
		        template <typename T>
		        void	sort(T& A, int first, int middle, int last)
		        {
			        int len1 = middle - first + 1; // length of left array len1 = 3
			        int len2 = last - middle; // length of right array  len2 = 2
			        int leftAr[len1]; // declare Left Array
			        int rightAr[len2]; // declare Right Array
			        for (int i = 0; i < len1; i++) // copy values from A into leftAr
				        leftAr[i] = A[first + i];
			        for (int i = 0; i < len2; i++) // copy values from A into rightAr
				        rightAr[i] = A[middle + 1 + i];
			        int index_r = 0; // right index
			        int index_l = 0; // left index
			        for (int i = first; i <= last; i++)
			        {
				        if (index_r == len2) // reached end of right-hand-side Array
				        {
					        A[i] = leftAr[index_l]; // left-hand-side index into A[i]
					        index_l++;
				        }
				        else if (index_l == len1)
				        {
					        A[i] = rightAr[index_r];
					        index_r++;
				        }
				        else if (rightAr[index_r] > leftAr[index_l]) // not true for rightAr{2} leftAr{5}
				        {
					        A[i] = leftAr[index_l];
					        index_l++;
				        }
				        else // We are copying the SMALLEST value into A[i]
				        {
					        A[i] = rightAr[index_r]; // A[0] = rightAr[0] => A = {2, 4, 3, 2, 1}
					        index_r++;
				        }
			        }
		        }

                /*
                * This template handles the sorting process if input only contains 2 elements.
                */
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

		        /*
                * This template starts the sorting process and is called in main.
                */
                template <typename T>
		        void sortProcess(T& A, int first, int last)   // A - vector container, first - index 0, last - index of last element
		        {
			        int n = last - first + 1;
			        if (n > 2) // value 2 since we want to pair the values into sub-arrays of size 2
			        {
				        int middle = (first + last) / 2; // 1st. iteration q = 0 + n - 1 / 2
				        sortProcess(A, first, middle); // 2nd. sort it 0 -> middle | left hand side
				        sortProcess(A, middle + 1, last); // 3rd. it middle -> n - 1 | right hand side
				        sort(A, first, middle, last);
			        }
			        else
				        insertionSort(A, first, last);      // if input contains only 2 elements
		        }
                
};

// Functions outside the class
bool		isDigit(char *s);
bool		inRange(char *s);
bool		isDigitAndInRange(int argc, char **argv);
bool		validInput(int argc, char **argv);

#endif