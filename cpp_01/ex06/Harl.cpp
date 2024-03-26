/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:09:01 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/25 13:45:11 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

std::string const Harl::_complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};


Harl::Harl( void ): _minLevel(0), _printed(0) { }

Harl::~Harl( void ) { }

void Harl::debug( void ) {
    std::cout << "[DEBUG]" << std::endl << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void ) {
    std::cout << "[INFO]" << std::endl << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning( void ) {
    std::cout << "[WARNING]" << std::endl << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void ) {
    std::cout << "[ERROR]" << std::endl << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

int Harl::getIndex( std::string level ) const {
    for(int i=0; i < 4; i++) {
        if (_complains[i] == level)
            return i;
    }
    return -1;
}

void Harl::complain( std::string level ) {
    void    (Harl::*memberFuncs[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    int index = this->getIndex(level);
    if (this->_minLevel == -1) {
        if (!this->_printed) {
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            this->_printed = 1;
        }
        return;
    }
        
    if (index >= this->_minLevel)
        (this->*memberFuncs[index])();
}

void Harl::setMinLevel( std::string level ) {

    switch (getIndex(level)) {
        case (0):
            this->_minLevel = 0;
            break;
        case (1):
            this->_minLevel = 1;
            break;
        case (2):
            this->_minLevel = 2;
            break;
        case (3):
            this->_minLevel = 3;
            break;
        default:
            this->_minLevel = -1;
    }
}

void Harl::complain_all( void )
{
    for (int i = this->_minLevel ; i < 4; i++) {
        complain(_complains[i]);
    }
}
