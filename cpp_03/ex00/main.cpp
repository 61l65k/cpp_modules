/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:12:48 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 18:12:49 by apyykone         ###   ########.fr       */
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

int main(void)
{
    ClapTrap clap1("ClapTrap1");
    ClapTrap clap2("ClapTrap2");
    ClapTrap clap3("ClapTrap3");


    clap1.attack("ClapTrap2");
    clap2.takeDamage(5);
    clap3.beRepaired(5);

    clap1.attack("ClapTrap2");
    clap2.takeDamage(5);

    clap1.attack("ClapTrap2");
    clap2.takeDamage(5);

    return 0;
}
