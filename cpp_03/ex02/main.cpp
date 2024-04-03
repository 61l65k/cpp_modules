/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 02:41:05 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/02 02:41:23 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    FragTrap fragger("Fragger");
    ScavTrap scaver("Scaver");
    ClapTrap clapper("Clapper", true);

    scaver.guardGate();
    clapper.attack("Clapper");
    clapper.takeDamage(0);

    fragger.highFivesGuys();
    fragger.attack("Scaver");
    scaver.takeDamage(30);

    return 0;
}
