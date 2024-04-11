/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/12 01:50:14 by alex             ###   ########.fr       */
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

    return 0;
}
