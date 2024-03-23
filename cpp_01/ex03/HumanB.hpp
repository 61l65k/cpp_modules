/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:46:43 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 04:10:56 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
private:
    std::string name;
    Weapon* weaponPtr;

public:
    HumanB(const std::string& name);
    ~HumanB();

    void setWeapon(const Weapon& weapon);
    void attack() const;
};

#endif // HUMANB_HPP
