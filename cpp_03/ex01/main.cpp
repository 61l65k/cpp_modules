/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/03 17:17:38 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:34:58 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 17:49:35 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScavTrap.hpp"

int main()
{
    ScavTrap tepi("Tepi");
    ScavTrap jepa("Jepa");
    ScavTrap sepi = tepi;
    ScavTrap lepi;

    ClapTrap clapper("Clapper", true);
    ClapTrap clapper2(clapper, true);

    tepi.attack("Jepa");
    jepa.takeDamage(20);
    jepa.beRepaired(10);
    tepi.guardGate();
    sepi.guardGate();
    return 0;
}

