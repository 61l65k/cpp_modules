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

* 1. Create a array of Animal pointers and fill it with Dogs and Cats that inherit from Animal.
* 2. Only thing that changed is the virtual key word before the destructor of the Animal class.-
* So if the Class has a virtual destructor, the derived class destructor will be called.


** Virtual destructor used in polymorphism when the class is dynamically allocated adn the class is not on stack-
*  So it knows to call the derived class destructorfirst if there is.
* Its good to make the base class destructor virtual if the class is meant to be inherited. Always !!
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
