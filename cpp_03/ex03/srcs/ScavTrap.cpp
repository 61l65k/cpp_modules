/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:30:56 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/12 01:46:43 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors ---------------------------------------------------------------

ScavTrap::ScavTrap() : ClapTrap("nameless", true)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    init_trap("ScavTrap", this->name);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, true)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    init_trap("ScavTrap", this->name);
}


ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src, false)
{
    copy_constructor_msg("ScavTrap", src.name);
}

ScavTrap::~ScavTrap()
{
	destruct_trap(this->name, "ScavTrap");
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    copy_assigment_msg("ScavTrap", name);
    return *this;
}

// Methods ---------------------------------------------------------------------

void    ScavTrap::guardGate( void )
{
    if (hitPoints > 0)
        std::cout << YELLOW << this->name << " has entered in Gate keeper mode 🚪" << RESET << std::endl;
    else
        std::cout << RED << this->name << " is dead 💀 Cant Gate keep!" << RESET << std::endl;
}
