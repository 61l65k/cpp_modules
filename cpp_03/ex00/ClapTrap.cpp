/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:49:15 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 17:49:16 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap spawned !" << std::endl;
}

ClapTrap::~ClapTrap( void )
{
    std::cout << "ClapTrap destroyed !" << std::endl;
}


void ClapTrap::attack(const std::string& target)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << "Cant do anything no energy or hitpoints!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints <= 0 || this->energyPoints <= 0)
    {
        std::cout << "ClapTrap " << name << "Cant do anything no energy or hitpoints!" << std::endl;
        return;
    }
    this->hitPoints += amount;
    std::cout << "ClapTrap " << name << " is repaired for " << amount << " points!" << std::endl;
}
