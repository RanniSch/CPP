/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 10:00:59 by rschlott          #+#    #+#             */
/*   Updated: 2023/06/11 13:55:19 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.tpp>

#include <cstdlib> // for rand()
#include <ctime> // for time()

# define SIZE 10 // for own tests
# define MAX_VAL 750 // for subject test

int main(void)
{
    std::cout << "\n\033[32m----- Own tests -----\033[0m\n" << std::endl;
    {
		std::cout << "\033[35mConstruction of an Array without parameter:\033[0m" << std::endl;
		Array<int> arr1; // difference to function template! explicit about the parameters over which template classes are instantiating
        std::cout << "Print array elements: ";
		arr1.printArrayElements();
	}

	/*{
		std::cout << "\n\033[35mConstruction of an Array with 3 unsigned int n elements as parameter:\033[0m" << std::endl;
		Array<int> arr2(3);
        std::cout << "Print array elements: ";
		arr2.printArrayElements();
	}*/

	/*{
		std::cout << "\033[35mTesting exceptions:\033[0m" << std::endl;
		
        std::cout << "\n\033[35mConstruction of an Array with 3 unsigned int n elements as parameter:\033[0m" << std::endl;
		Array<int> arr3(3);
        std::cout << "Print array elements: ";
		arr3.printArrayElements();
		try
		{
			std::cout << "Trying to access arr3[-5]" << std::endl;
			std::cout << arr3[-5] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
            
        std::cout << "Print array elements again: ";
		arr3.printArrayElements();
		try
		{
			std::cout << "Trying to access arr3[4]" << std::endl;
			std::cout << arr3[4] << std::endl;
		}
		catch(const std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}*/

	/*{
		std::cout << "\033[35mConstruction of an Array by copy\033[0m\n" << std::endl;
		std::cout << "\033[35mConstruction of an array: arr4 with SIZE:\033[0m" << std::endl;
		Array<int>	arr4(SIZE);
        std::cout << "Print array elements: ";
		arr4.printArrayElements();

		std::srand(std::time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			const int	value = std::rand() % 100; // int rand (void) returns a pseudo-random integral number in the range between 0 and RAND_MAX. % 100 makes random numbers in the range 0 to 99.
			arr4[i] = value;
		}
		std::cout << "arr4 with different values (r/w through operator[]): " << std::endl;
        arr4.printArrayElements();
		std::cout << "\nConstruction of an array by copy of arr4: arr4CopyConstructor!" << std::endl;
		Array<int> arr4CopyConstructor = arr4;
        std::cout << "Copied elements: " << std::endl;
		arr4CopyConstructor.printArrayElements();
	}

	{
		std::cout << "\033[35mConstruction of an Array by assignement operator\033[0m\n" << std::endl;
		std::cout << "\033[35mConstruction of an array of 4 int n elements as parameter: arr5\033[0m" << std::endl;
		Array<int>	arr5(4);
        std::cout << "arr5 elements: ";
		arr5.printArrayElements();
		
		std::cout << "\n\033[35mConstruction of an array of 10 int n elements as parameter: arr6\033[0m" << std::endl;
		Array<int>	arr6(SIZE);
        std::cout << "arr6 elements: ";
		arr6.printArrayElements();
        
		std::srand(std::time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			const int	value = std::rand() % 100; // int rand (void) returns a pseudo-random integral number in the range between 0 and RAND_MAX. % 100 makes random numbers in the range 0 to 99.
			arr6[i] = value;
		}
        std::cout << "arr6 with different values (r/w through operator[]): " << std::endl;
		arr6.printArrayElements();
		arr5 = arr6;
        std::cout << "arr5 elements: ";
		arr5.printArrayElements();
	}*/

	/*{
		std::cout << "\033[35mConstruction of an Array of strings\033[0m\n" << std::endl;
		std::cout << "\033[35mConstruction of an array of 10 strings elements: arr7\033[0m\n" << std::endl;
		Array<std::string> arr7(SIZE);
        std::cout << "arr7 elements: ";
		arr7.printArrayElements();
        
		arr7[0] = "We";
		arr7[1] = " ";
		arr7[2] = "love";
		arr7[3] = " ";
		arr7[4] = "42 Wolfsburg";
		arr7[5] = ",";
		arr7[6] = "great";
		arr7[7] = " ";
		arr7[8] = "place";
		arr7[9] = "!";
        std::cout << "arr7 with different values (r/w through operator[]): " << std::endl;
		arr7.printArrayElements();
	}*/

	/*{
		std::cout << "\033[35mConstruction of an Array with parameter / compare with new []\033[0m\n" << std::endl;
		std::cout << "\033[35mConstruction of an array of 10 int n elements from template class: arr8\033[0m" << std::endl;
		Array<int> arr8(SIZE);
		std::srand(std::time(NULL));
		for (int i = 0; i < SIZE; i++)
		{
			const int	value = std::rand() % 100;
			arr8[i] = value;
		}
        std::cout << "arr8 elements: ";
		arr8.printArrayElements();

		std::cout << "\n\033[35mConstruction of an array of 10 int n elements from integer array: actualIntArray\033[0m" << std::endl;
		int *actualIntArray = new int[SIZE];
		for (int i = 0; i < SIZE; i++)
		{
			actualIntArray[i] = arr8[i];
		}
		for (int i = 0; i < SIZE; i++)
		{
			if (i < (SIZE - 1))
				std::cout << actualIntArray[i] << " - ";
			else
				std::cout << actualIntArray[i] << std::endl;
		}
		delete [] actualIntArray;
	}*/
    
    
    /*{
        std::cout << "\n\033[32m----- Subject test -----\033[0m\n" << std::endl;
        Array<int> numbers(MAX_VAL);
        int* mirror = new int[MAX_VAL];
        srand(time(NULL));
        for (int i = 0; i < MAX_VAL; i++)
        {
            const int value = rand(); // int rand (void) returns a pseudo-random integral number in the range between 0 and RAND_MAX.
            numbers[i] = value;
            mirror[i] = value;
        }
        //SCOPE
        {
            Array<int> tmp = numbers;
            Array<int> test(tmp);
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            if (mirror[i] != numbers[i])
            {
                std::cerr << "\033[31mdidn't save the same value!!\033[0m" << std::endl;
                return 1;
            }
        }
        try
        {
            numbers[-2] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            numbers[MAX_VAL] = 0;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }

        for (int i = 0; i < MAX_VAL; i++)
        {
            numbers[i] = rand();
        }
        delete [] mirror;//
    }*/

    return 0;
}