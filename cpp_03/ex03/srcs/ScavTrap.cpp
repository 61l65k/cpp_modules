/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:30:56 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:30:20 by apyykone         ###   ########.fr       */
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

ScavTrap::ScavTrap(std::string name, bool not_derived) : ClapTrap(name, true)
{
    if (not_derived)
    {
        hitPoints = 100;
        energyPoints = 50;
        attackDamage = 20;
        init_trap("ScavTrap", this->name);
    }
    else
        std::cout << GREEN << this->name << " ScavTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
}


ScavTrap::ScavTrap(const ScavTrap &src, bool not_derived) : ClapTrap(src, false)
{
    if (not_derived)
        copy_constructor_msg("ScavTrap", src.name);
    else
        std::cout << GREEN << this->name << " ScavTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
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
