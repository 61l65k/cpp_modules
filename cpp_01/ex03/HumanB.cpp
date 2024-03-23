/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:46:46 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 03:58:43 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weaponPtr(NULL) {}

HumanB::~HumanB() {delete weaponPtr;}

void HumanB::setWeapon(const Weapon& weapon)
{
    delete weaponPtr;
    weaponPtr = new Weapon(weapon.getType());
}

void HumanB::attack() const
{
    if (weaponPtr)
        std::cout << name << " attacks with their " << weaponPtr->getType() << std::endl;
    else
        std::cout << name << " is unarmed" << std::endl;
}
