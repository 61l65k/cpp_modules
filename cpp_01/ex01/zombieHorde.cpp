/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 03:16:12 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 03:26:20 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        horde[i].give_name(name + " " + std::to_string(i + 1));
        horde[i].announce();
    }
    return horde;
}
