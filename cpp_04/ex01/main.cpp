/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:54:21 by alex              #+#    #+#             */
/*   Updated: 2024/04/16 14:47:24 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_ANIMALS 2

/**
* Create an array of MAX_ANIMALS animals, alternating between Dog and Cat.
* Create deep copy of the first animal in the array. which is a Dog.
*/

int	main()
{
	Animal* animals[MAX_ANIMALS];
	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < MAX_ANIMALS; i++)
		animals[i]->makeSound();

	if (MAX_ANIMALS > 0)
	{
		Animal* copy = new Dog(*static_cast<Dog *>(animals[0]));
		std::cout << copy->getType() << std::endl;
		copy->makeSound();
		delete copy;
	}

	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		delete animals[i];
	}
}
