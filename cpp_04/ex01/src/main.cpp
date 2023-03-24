/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 17:53:47 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/24 19:12:17 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>

int main(void)
{
    // FIRST TEST
    /*const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();
    
    delete meta;
    delete j;
    delete i;*/

    // SECOND TEST
    std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*meta = new Animal();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;

	std::cout << "Animal _type: " << meta->getType() << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*catto = new Cat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Cat _type: " << catto->getType() << std::endl;
	catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete catto;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const Animal	*doggo = new Dog();
	std::cout << std::endl;
	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Dog _type: " << doggo->getType() <<std::endl;
	doggo->makeSound();
	std::cout << std::endl;
	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete doggo;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << std::endl;
	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal	*wrong_meta = new WrongAnimal();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "Animal _type: " << wrong_meta->getType() << std::endl;
	wrong_meta->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete wrong_meta;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

	std::cout << "\033[34mConstructing\033[0m" << std::endl;
	const WrongAnimal	*wrong_catto = new WrongCat();
	std::cout << std::endl;

	std::cout << "\033[34mTesting\033[0m" << std::endl;
	std::cout << "WrongCat _type: " << wrong_catto->getType() <<std::endl;
	wrong_catto->makeSound();
	std::cout << std::endl;

	std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
	delete wrong_catto;
	std::cout << std::endl;

	std::cout << "-------------------------------------------------------" << std::endl;

    return (0);
}
