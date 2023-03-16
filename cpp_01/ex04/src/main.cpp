/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:08:30 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/16 07:50:16 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
//#include <string> //not nessecary when using std:: in front of string

std::string my_replace(std::string buffer, const std::string s1, const std::string s2)
{
    size_t	erase_length = s1.length();
	size_t	replace_length = s2.length();
	size_t	pos_search = 0;

    pos_search = buffer.find(s1);
    while (pos_search != std::string::npos)
	{
		buffer.erase(pos_search, erase_length);
		buffer.insert(pos_search, s2);
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
        const std::string   s1 = argv[2];  //maybe just write s1 and s2 and then save text from textfile into those strings?
        const std::string   s2 = argv[3];
        std::string         buffer;
        std::ifstream       infile;
        std::ofstream       outfile;

        infile.open(argv[1]); // infile.open(filename) doesn't work cause it is a string?  open has no return value!
        if (infile.is_open() == true)    // check if a file is open; true if a file is open and associated with this stream object. false otherwise.
        {
            outfile.open("filename.replace", std::ios::out | std::ios::trunc);
            if (outfile.is_open() == true)
            {
                while (std::getline(infile, buffer))
                {
                    buffer = my_replace(buffer, s1, s2);
                    outfile << buffer;
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
        /*std::ofstream outfile1;
        outfile1.open(filename);
        outfile1 << s2 << std::endl;
        outfile1.close();
        std::ofstream outfile2;
        outfile2.open("text.txt.replace");
        outfile2 << s1 << std::endl;
        outfile2.close();

        std::ifstream infile;
        infile.open(filename);
        infile >> s2
        infile.close();

        std::ofstream outfile3;
        outfile3.open("text.txt.replace");
        outfile3 << s2 << std::endl;
        outfile3.close();
        open(filename, ios::in);*/


        return (0);
    }
    return (0);
}