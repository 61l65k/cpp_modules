/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:49:15 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:17:57 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Constructors ---------------------------------------------------------------

ClapTrap::ClapTrap( void ) : name("nameless"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    init_trap("ClapTrap", this->name);
}

ClapTrap::ClapTrap(const std::string& name, bool not_derived)
: name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    if (not_derived)
        init_trap("ClapTrap", this->name);
    else
          std::cout << GREEN << this->name << " ClapTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap, bool not_derived)
    : name(clapTrap.name),
      hitPoints(clapTrap.hitPoints),
      energyPoints(clapTrap.energyPoints),
      attackDamage(clapTrap.attackDamage)
{
    if (not_derived)
        copy_constructor_msg("ClapTrap", clapTrap.name);
    else 
          std::cout << GREEN << this->name << " ClapTrap created as a derived constructor 👶!" << RESET << std::endl << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src)
{
    if (this != &src)
    {
        this->name = src.name;
        this->hitPoints = src.hitPoints;
        this->energyPoints = src.energyPoints;
        this->attackDamage = src.attackDamage;
    }
    copy_assigment_msg("ClapTrap", src.name);
    return *this;
}

ClapTrap::~ClapTrap( void )
{
    destruct_trap(this->name, "ClapTrap");
}

// Methods ---------------------------------------------------------------------

void	ClapTrap::attack(const std::string& target)
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
	std::cout << MAGENTA << "Clap attack method" << this->name << " attacks "  << target
			<< ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	int           from = this->hitPoints;
    const int     damagetaken = this->hitPoints - amount;

	if (from == 0)
    {
		std::cout << RED << this->name << " is already dead!" << RESET << std::endl;
		return ;
	}
	this->hitPoints -= amount;
	if (damagetaken <= 0)
    {
		this->hitPoints = 0;
		std::cout << RED << this->name <<  " died due to " << \
			amount << " damage! (" << from << " >> " << damagetaken << ")" << RESET << std::endl;
		return ;
	}
	std::cout << RED << this->name << " took " << \
		amount << " damage! (" << from << " >> " << this->hitPoints << ")" << RESET << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	int	from = this->hitPoints;

	if (from == 0 || this->energyPoints == 0)
    {
		std::cout  << RED << this->name <<  " can't be repaired. "
				<< (from == 0 ? "Entity is dead." : "No energy points left!") << RESET << std::endl;
		return ;
	}
	this->hitPoints += amount;
	this->energyPoints--;
	if (this->energyPoints <= 0)
		this->energyPoints = 0;
	std::cout << MAGENTA << this->name << " is being repaired... ("
			<< from << " >> " << this->hitPoints << ")" << RESET << std::endl;
}

// shared trap methods --------------------------------------------------------

void ClapTrap::init_trap(const std::string& title, const std::string &real_name) 
{
    const int boxWidth = 50;
    int titleStartPos = (boxWidth - title.length()) / 2;

    std::string topborder = "+" + std::string(titleStartPos - 1, '-')\
    + title + std::string(boxWidth - titleStartPos - title.length() - 1, '-') + "+" ;
    std::string bottomborder = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << topborder << std::endl;
    std::cout << BLUE << "Name: " << RESET;
    std::cout << std::left << std::setw(boxWidth - 8) << real_name << std::endl;
    std::cout << GREEN << "Hit Points: " << RESET;
    std::cout << std::left << std::setw(boxWidth - 20) << std::to_string(hitPoints) + " 🛡️" << std::endl;
    std::cout << MAGENTA << "Energy Points: " << RESET;
    std::cout << std::left << std::setw(boxWidth - 22) << std::to_string(energyPoints) + " 🔋"  << std::endl;
    std::cout << RED << "Attack Damage: " << RESET;
    std::cout << std::left << std::setw(boxWidth - 22) << std::to_string(attackDamage) + " 🗡️" << std::endl;
    std::cout << GREEN << real_name << " ClapTrap created 👶!" << RESET << std::endl;
    std::cout << bottomborder << std::endl << std::endl;
}

void ClapTrap::destruct_trap(const std::string &real_name, const std::string& class_name)
{
    std::cout << RED << real_name << "{ " << class_name  << " } destructed 💀!" << RESET << std::endl;
} 

void ClapTrap::copy_assigment_msg(const std::string &class_name, const std::string &real_name)
{
    const int boxWidth = 50;

    std::string border = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << border << std::endl;
    std::cout << GREEN << "{ " << class_name << " } created with copy assigment! from :" << RESET << BLUE << real_name << RESET << std::endl << std::endl;
    std::cout << GREEN << real_name << " " << class_name << " created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
}

void ClapTrap::copy_constructor_msg(const std::string &class_name, const std::string &real_name)
{
    const int boxWidth = 50;

    std::string border = "+" + std::string(boxWidth - 2, '-') + "+" ;
    std::cout << border << std::endl;
    std::cout << GREEN << "{ " << class_name << " } copy constructed from :" << RESET << BLUE << real_name << RESET << std::endl;
    std::cout << GREEN << real_name << class_name << " created 👶!" << RESET << std::endl << std::endl;
    std::cout << border << std::endl << std::endl;
}
