/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:47 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/02 02:29:37 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors ---------------------------------------------------------------

FragTrap::FragTrap() : ClapTrap("nameless", false)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	init_trap("FragTrap", this->name);
}
FragTrap::FragTrap(std::string name) : ClapTrap(name, false)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	init_trap("FragTrap", this->name);
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src, false)
{
    copy_constructor_msg("FragTrap", src.name);
}

FragTrap::~FragTrap()
{
	destruct_trap(this->name, "FragTrap");
}

FragTrap &FragTrap::operator=(const FragTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    copy_assigment_msg("FragTrap", src.name);
    return *this;
}

// Methods -----------------------------------------------------------

void    FragTrap::highFivesGuys(void)
{
	if(this->hitPoints > 0)
    	std::cout << YELLOW << this->name << " high fives guys! 🙌" << RESET << std::endl;
	else
		std::cout << YELLOW << this->name << " is dead! 💀 Cant highfive!" << RESET << std::endl;
}
