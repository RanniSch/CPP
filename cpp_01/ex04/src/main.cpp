/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 07:08:30 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/14 07:54:46 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

/*
* takes 3 arguments: filename, string 1 and string 2
*/
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Wrong input!" << std::endl;
        //exit (0);
    }
    const char *filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];
    std::ofstream outfile1;
    outfile1.open(filename);
    outfile1 << s2 << std::endl;
    outfile1.close();
    std::ofstream outfile2;
    outfile2.open("text.txt.replace");
    outfile2 << s1 << std::endl;
    outfile2.close();
    
    //std::ifstream infile;
    //infile.open(filename);
    //infile >> s2
    //infile.close();

    std::ofstream outfile3;
    outfile3.open("text.txt.replace");
    outfile3 << s2 << std::endl;
    outfile3.close();
    //open(filename, ios::in);
    return (0);
}