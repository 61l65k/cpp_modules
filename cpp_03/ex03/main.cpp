/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/13 16:43:34 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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
       ClapTrap    virtual  abstract class
      /        \
 ScavTrap   FragTrap
      \        /
       DiamondTrap

    ClapTrap  ClapTrap    non virtual   non abstract class
      /           \
 ScavTrap        FragTrap
      \          /
       DiamondTrap

! Make the Frag & Scav classes inherit from virtual ClapTrap class. 
! This way, the DiamondTrap class will have only one instance of the ClapTrap class.

*/


int main()
{
    DiamondTrap diamondTrap("DiamondTrap");
    DiamondTrap diamondTrap2("DiamondTrap2");


    diamondTrap.attack("DiamondTrap2");
    diamondTrap2.takeDamage(10);
    diamondTrap.highFivesGuys();

    diamondTrap.whoAmI();
    diamondTrap2.whoAmI();

    return 0;
}
