/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:43:51 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 04:11:41 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"

/*

For HumanA (Bob), we use a reference to Weapon because Bob must always have a weapon, and the weapon type remains constant throughout Bob's lifetime.

For HumanB (Jim), we use a pointer to Weapon because Jim may not always have a weapon initially, and he can equip different weapons during his lifetime.

So said the reference is always same as the pointer can dynamically change.

*/

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("crude spiked club");
        HumanB jim("Jim");
        jim.attack();
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }
    return 0;
}
