/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/02 02:29:34 by apyykone         ###   ########.fr       */
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

! Make the Frag & Scav classes inherit from virtual ClapTrap class. 
! This way, the DiamondTrap class will have only one instance of the ClapTrap class.

*/


int main()
{
    DiamondTrap diamondTrap("DiamondTrap");
    DiamondTrap diamondTrap2("DiamondTrap2");   
    DiamondTrap diamondTrap3(diamondTrap2);

    diamondTrap.guardGate();
    diamondTrap.attack("target");
    diamondTrap.takeDamage(10);
    diamondTrap.whoAmI();

    diamondTrap2.whoAmI();
    diamondTrap2.guardGate();
    return 0;
}
