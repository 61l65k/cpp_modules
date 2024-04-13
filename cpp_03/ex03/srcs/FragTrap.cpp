/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:47 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:35:27 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors ---------------------------------------------------------------

FragTrap::FragTrap() : ClapTrap("nameless", true)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	init_trap("FragTrap", this->name);
}
FragTrap::FragTrap(std::string name, bool not_derived) : ClapTrap(name, true)
{
    if (not_derived)
    { 
        this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        init_trap("FragTrap", this->name);
    }
    else
    {
        this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        std::cout << GREEN << this->name << " FragTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
    }
}

FragTrap::FragTrap(const FragTrap &src, bool not_derived) : ClapTrap(src, false)
{
    if (not_derived)
      copy_constructor_msg("FragTrap", src.name);
    else
    {
        this->hitPoints = 100;
        this->energyPoints = 100;
        this->attackDamage = 30;
        std::cout << GREEN << this->name << " FragTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
    }
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
	if(this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << YELLOW << this->name << " high fives guys! 🙌" << RESET << std::endl;
        this->energyPoints--;
    }
    else
		std::cout << YELLOW << this->name << " is dead or no energy ! Cant highfive! 🙌" << RESET << std::endl;
}
