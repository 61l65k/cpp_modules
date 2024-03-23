/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:46:31 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 03:55:37 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon {
private:
    std::string type;

public:
    Weapon(const std::string& type);

    const std::string& getType() const;

    void setType(const std::string& newType);
};

#endif // WEAPON_HPP
