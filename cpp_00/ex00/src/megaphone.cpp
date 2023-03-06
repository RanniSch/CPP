/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 07:59:43 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/06 09:17:44 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* <cctype> to use toupper in c++
* <iostream> to use cout and sin
* print the sting by operating on the std::cout stream: 
*   std::cout << your_string << std::endl;
* line above reads in the standard output
* std = standard namespace
* << redirect the flow to the standard output
* endl having a new line (works on windows OS and linux; better than \n)
* (char)toupper converts the return value from ASCII back to char
*/

#include <cctype>
#include <iostream>

int main (int argc, char **argv)
{
    int i;
    int j;

    if (argc > 1)
    {
        for (i = 1; i < argc; i++)
        {
            for (j = 0; argv[i][j] != '\0'; j++)
                argv[i][j] = (char)toupper(argv[i][j]);
            std::cout << argv[i];
            if (argv[i] != NULL)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
}