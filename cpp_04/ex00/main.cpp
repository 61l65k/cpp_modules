/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:54:21 by alex              #+#    #+#             */
/*   Updated: 2024/04/07 15:22:18 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/**
* Animal base class the makesound() is virtual so it can change in the derived classes
* in run time.
**
* WrongAnimal base class the makesound() is not virtual so it can't change in the derived classes
* in run time.
*/

int main()
{
    const Animal* meta = new Animal();
    Animal* catty = new Cat();
    Animal* doggy = new Dog();

    // Creating new block of memory
    const Animal *dog_deep = new Dog(*static_cast<Dog*>(doggy)); // deep copy
    const Animal *cat_deep = new Cat(*static_cast<Cat*>(catty)); // deep copy

    // pointing to existing memory
    const Animal *dog_shallow = doggy; // shallow copy
    const Animal *cat_shallow = catty; // shallow copy

    dog_deep->makeSound();
    cat_deep->makeSound();
    dog_shallow->makeSound();
    cat_shallow->makeSound();


    // Wrong Animals The base class doesnt have virtual makesound()
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound(); 
    wrongMeta->makeSound(); 

    delete dog_deep;
    delete cat_deep;
    delete catty;
    delete doggy;
    delete meta;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
