/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:47 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/25 16:08:49 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream> // cout
#include <stdlib.h> // exit
#include <stdio.h> // perror

int main(void)
{
    // FIRST TEST
    /*Dog *bello = new Dog();
    Dog *j = new Dog();
    Cat *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    bello->makeSound();

	bello->setIdeas(0, "I have to sniff it");
	i->setIdeas(1, "I have to pee on it");
	j->setIdeas(2, "I have to sniff it again");
	bello->setIdeas(101, "some shit");
    
	bello->getIdeas(0);
	i->getIdeas(1);
	j->getIdeas(2);
	bello->getIdeas(101);

    delete bello;
    delete j;
    delete i;*/

	
	// SECOND TEST
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			meta[i] = new Cat();
			if (meta[i] == NULL)
			{
				perror("Cat allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
		else
		{
			meta[i] = new Dog();
			if (meta[i] == NULL)
			{
				perror("Dog allocation failed");
				std::cerr << "Exiting process now";
				exit(1);
			}
		}
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	for (int i = 0; i < 10; i++)
		delete(meta[i]);

//THIS PART IS FOR TESTING DEEP COPY ↓

	std::cout << std::endl << std::endl;
	std::cout << "#### showing that the copy constructor creates a deep copy ####" << std::endl;
	std::cout << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	//Dog *a = new Dog();
	Cat *a = new Cat();
	if (a == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}

	a->setIdeas(5, "I wanna jump on it");
	a->setIdeas(9, "I would love to eat the steak from the fridge");
	a->setIdeas(53, "I hate this dude");
	a->setIdeas(105, "pied onto my leg");

	//Dog *b = new Dog(*a);
	Cat *b = new Cat(*a);
	if (b == NULL)
	{
		perror("Allocation failed");
		std::cerr << "Exiting the process now." << std::endl;
		exit(1);
	}
	std::cout << std::endl;

	std::cout << "\033[34mTesting a\033[0m" << std::endl;
	std::cout << "The " << a->getType() << " a has the following ideas: " << std::endl;
	//for (int i = 0; i < 100; i++)  // for many ideas
	//	a->getIdeas(i);
	a->getIdeas(5);
	a->getIdeas(9);
	a->getIdeas(53);
	a->getIdeas(105);
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing a\033[0m" << std::endl;
	delete(a);
	std::cout << std::endl;

	std::cout << "\033[34mTesting b\033[0m" << std::endl;
	std::cout << "The " << b->getType() << " b has the following ideas: " << std::endl;
	//for (int i = 0; i < 100; i++)  // for many ideas
	//	b->getIdeas(i);
	b->getIdeas(5);
	b->getIdeas(9);
	b->getIdeas(53);
	b->getIdeas(105);
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing b\033[0m" << std::endl;
	delete(b);

    return (0);
}
