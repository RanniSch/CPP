/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschlott <rschlott@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:47:11 by rschlott          #+#    #+#             */
/*   Updated: 2023/03/17 21:57:54 by rschlott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
    //std::cout << "Harl called" << std::endl;
    return;
}

Harl::~Harl(void)
{
    //std::cout << "Harl destroyed" << std::endl;
    return;
}

void    Harl::_debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::_info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::_warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::_error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    std::string input[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    int i;

    for (i = 0; i < 4; i++)
    {
        if (level == input[i])
            break;
    }
    i++;
    switch(i)
    {
        case 1 :
            _function = &Harl::_debug;
            (this->*_function)();
            break;
        case 2 :
            _function = &Harl::_info;
            (this->*_function)();
            break;
        case 3 :
            _function = &Harl::_warning;
            (this->*_function)();
            break;
        case 4 :
            _function = &Harl::_error;
            (this->*_function)();
            break;
        case 5 :
            std::cout << "This input does not exist! DEBUG, INFO, WARNING, ERROR allowed!" << std::endl;
            break;
    }
}
