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
    const Animal* doggy = new Dog();
    const Animal* catty = new Cat();
    
    std::cout << doggy->getType() << " " << std::endl;
    std::cout << catty->getType() << " " << std::endl;
    
    catty->makeSound(); 
    doggy->makeSound(); 
    meta->makeSound(); 
    
    const WrongAnimal* wrongMeta = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrongCat->makeSound(); 
    wrongMeta->makeSound(); 

    delete catty;
    delete doggy;
    delete meta;
    delete wrongMeta;
    delete wrongCat;

    return 0;
}
