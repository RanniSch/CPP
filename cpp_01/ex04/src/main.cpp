/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:08:30 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/16 19:43:11 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
//#include <string> //not nessecary when using std:: in front of string

std::string my_replace(std::string buffer, const std::string s1, const std::string s2)
{
    size_t	erase_length = s1.length();     // length() to get the length of a string
	size_t	replace_length = s2.length();
	size_t	pos_search = 0;

    pos_search = buffer.find(s1);       // Search an element inside a specified range and returns the first occurrence of the element.
    while (pos_search != std::string::npos)     // npos is a static member constant value with the greatest possible value for an element of type size_t. This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
	{
        buffer.erase(pos_search, erase_length);     // will delete the specified number (length) of characters after the specified position: erase(index, length)
		buffer.insert(pos_search, s2);              // insert part of the string
		pos_search = buffer.find(s1, pos_search + replace_length);
	}
	return (buffer);
}

/*
* takes 3 arguments: filename, s1 and s2
* It will open the file <filename> and copies its content into a new file
* <filename>.replace, replacing every occurrence of s1 with s2.
*/
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong input!" << std::endl <<
        "Write: ./files <filename> <s1> <s2>" << std::endl;
        return (-1);
    }
    else
    {
        const std::string   filename = argv[1];
        const std::string   s1 = argv[2];
        const std::string   s2 = argv[3];
        std::string         buffer;
        std::ifstream       infile;
        std::ofstream       outfile;

        infile.open(argv[1]); // infile.open(filename) doesn't work cause it is a string and not const char *; open has no return value!
        if (infile.is_open() == true)    // check if a file is open; true if a file is open and associated with this stream object. false otherwise.
        {
            outfile.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);     // c_str() convert a given string to an array of characters. Returns a pointer to an array that contains a null-terminated sequence of characters.
            if (outfile.is_open() == true)
            {
                while (std::getline(infile, buffer))        // takes text from infile and saves it in buffer; a loop per line in infile (one string = one line)
                {
                    buffer = my_replace(buffer, s1, s2);    // overwrites buffer with text to replace the outfile with
                    outfile << buffer;                      // writes buffer to outfile
                    if (infile.peek() != EOF) // Returns the next character in the input sequence, without extracting it: The character is left as the next character to be extracted from the stream.
                        outfile << std::endl;
                }
                outfile.close();
            }
            else
            {
                std::perror("Outfile error");
                infile.close();
                return (-1);
            }
            infile.close();
        }
        else
        {
            std::perror("Infile error");
            std::cout << "Outfile not created or truncated." << std::endl;
            return (-1);
        }
        return (0);
    }
    return (0);
}
