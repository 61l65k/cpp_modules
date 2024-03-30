/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:51:47 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/30 17:17:38 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors ---------------------------------------------------------------

FragTrap::FragTrap() : ClapTrap("nameless", false)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	init_trap("FragTrap");
}
FragTrap::FragTrap(std::string name) : ClapTrap(name, false)
{
	this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
	init_trap("FragTrap");
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src, false)
{
	const int boxWidth = 50;

    std::string border = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << border << std::endl;
    std::cout << GREEN << "{ FlagTrap } copy constructed from :" << RESET << BLUE << src.name << RESET << std::endl;
    std::cout << GREEN << this->name << " FlagTrap created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << RED << this->name << "{ FragTrap } destructed 💀!" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src)
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
    std::cout << GREEN << "{ FragTrap } created with copy assigment! from :" << RESET << BLUE << src.name << RESET << std::endl << std::endl;
    std::cout << GREEN << this->name << " FragTrap  created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
    return *this;
}

void    FragTrap::highFivesGuys(void)
{
	if(this->hitPoints > 0)
    	std::cout << YELLOW << this->name << " high fives guys! 🙌" << RESET << std::endl;
	else
		std::cout << YELLOW << this->name << " is dead! 💀 Cant highfive!" << RESET << std::endl;
}
