/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:54:21 by alex              #+#    #+#             */
/*   Updated: 2024/04/14 13:41:54 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#define MAX_ANIMALS 2

/**
* - Only thing that changed we made the AAnimal class abstract
* by adding a pure virtual function makeSound.
* - So it needs a derived class to implement it.

* So the AAnimal class is now an abstract class so called interface.
*/

int	main()
{
	AAnimal* animals[MAX_ANIMALS];
	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	if (MAX_ANIMALS > 0)
	{
		AAnimal* copy = new Dog(*(Dog *)animals[0]);
		std::cout << copy->getType() << std::endl;
		copy->makeSound();
		delete copy;
	}

	for (int i = 0; i < MAX_ANIMALS; i++)
	{
		delete animals[i];
	}

	// Pointer tests (Polymorphic)
	std::cout << "\033[1;34mPointer tests (Polymorphic)\033[0m" << std::endl;
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	// Reference tests (Polymorphic)
	std::cout << "\033[1;34mReference tests (Polymorphic)\033[0m" << std::endl;
	const AAnimal& l = *j;
	const AAnimal& m = *i;

	std::cout << l.getType() << " " << std::endl;
	std::cout << m.getType() << " " << std::endl;
	m.makeSound();
	l.makeSound();

	delete j;
	delete i;

	return 0;
}