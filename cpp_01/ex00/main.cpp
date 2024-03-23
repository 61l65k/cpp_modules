/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 02:32:55 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/23 03:06:42 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

static void stack_example(void)
{
    Zombie	stack_zombie("Stack Zombie");
    stack_zombie.announce();
}

static Zombie *heap_example(void)
{
    Zombie	*heap_zombie = newZombie("Heap Zombie");
    heap_zombie->announce();
    return heap_zombie;
}

static Zombie *random_chumper(Zombie *heap_zombie)
{
    randomChump("Randomchumper Zombie");
    randomChump("Randomchumper Zombie");
    delete heap_zombie;
    randomChump("Randomchumper Zombie");
    stack_example();
    return heap_example();
}


int	main(void)
{
    stack_example();
    Zombie *heap_zombie = heap_example();
    Zombie *new_heap_zombie = random_chumper(heap_zombie);
	delete new_heap_zombie;
	return (0);
}
