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
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << YELLOW << this->name << " has entered in Gate keeper mode 🚪" << RESET << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << YELLOW << this->name << " is out of energy or dead! Cant Gate keep! 🚪" << RESET << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0 || this->energyPoints == 0)
    {
		std::cout << BLUE << this->name << " tried to attack " << target
				<< (this->hitPoints == 0 ? " but is dead!" : " but is out of energy!") << RESET << std::endl;
		return ;
	}
	this->energyPoints--;
	if (this->energyPoints <= 0)
		this->energyPoints = 0;
	std::cout << MAGENTA << "Scav Attack method " << this->name << " attacks "  << target
			<< ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
}
