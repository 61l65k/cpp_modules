/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:09:01 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:38:15 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string const Harl::_complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};


Harl::Harl( void ) { }

Harl::~Harl( void ) { }

void Harl::debug( void ) {
    std::cout << "{DEBUG}" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "{INFO}" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "{WARNING}" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "{ERROR}" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain( std::string level ) {
    void    (Harl::*memberFuncs[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for(int i=0; i < 4; i++) {
        if (_complains[i] == level)
            (this->*memberFuncs[i])();
    }
}
