/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/29 19:00:16 by apyykone         ###   ########.fr       */
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



#include "ClapTrap.hpp"

int	main(void)
{
    ClapTrap sepi("Sepi");
    ClapTrap sepi2(sepi);
    ClapTrap sepi3 = sepi;

    ClapTrap tepi("Tepi");
    ClapTrap kepi("Kepi");
    ClapTrap nameless;

    sepi.attack("Tepi");
    sepi2.attack("Tepi");
    sepi3.attack("Tepi");
    tepi.takeDamage(0);
    tepi.takeDamage(0);
    tepi.takeDamage(0);

    kepi.beRepaired(100);
    kepi.beRepaired(100);
    kepi.beRepaired(100);
    nameless.attack("Tepi");
    tepi.takeDamage(0);

	return (0);
}