/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:41:05 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:16:14 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap fragger("Fragger");
    ScavTrap scaver("Scaver");

    scaver.guardGate();

    fragger.highFivesGuys();
    fragger.attack("Scaver");
    scaver.takeDamage(30);

    return 0;
}
