/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:41:11 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/01 19:58:14 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name, false), FragTrap(name), ScavTrap(name) {};

void DiamondTrap::whoAmI(void){
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap &src) : ClapTrap(src.name, false), FragTrap(src.name), ScavTrap(src.name){
	*this = src;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &cop) {
	this->name = cop.name;
	FragTrap::setHitPoints( cop.getHitPoints() );
	ScavTrap::setEnergyPoints( cop.getEnergyPoints() );
	FragTrap::setAttackDamage( cop.getAttackDamage() );
	return (*this);
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called" << std::endl;
}
