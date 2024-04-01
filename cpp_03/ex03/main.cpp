/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/01 20:01:20 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 -Wshadow flag is used to detect shadowed variables. example,
 and yes we can create new block with the braces.
 void foo (int x) 
 {
    int x = 0; --shadow
    {
        int x = 0; --shadow
    }
}

! Make the Frag & Scav classes inherit from virtual ClapTrap class. 
! This way, the DiamondTrap class will have only one instance of the ClapTrap class.

*/


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