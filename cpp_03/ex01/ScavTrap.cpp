/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 15:30:56 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:05:15 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

// Constructors ---------------------------------------------------------------

ScavTrap::ScavTrap() : ClapTrap("nameless", false)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    init_trap("ScavTrap");
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, false)
{
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    init_trap("ScavTrap");
}


ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src, false)
{
    const int boxWidth = 50;

    std::string border = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << border << std::endl;
    std::cout << GREEN << "{ ScavTrap } copy constructed from :" << RESET << BLUE << src.name << RESET << std::endl;
    std::cout << GREEN << this->name << " ScavTrap created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED << this->name << "{ ScavTrap } destructed 💀!" << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src)
{
    const int boxWidth = 50;

    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    std::string border = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << border << std::endl;
    std::cout << GREEN << "{ ScavTrap } created with copy assigment! from :" << RESET << BLUE << src.name << RESET << std::endl << std::endl;
    std::cout << GREEN << this->name << " ScavTrap created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
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
