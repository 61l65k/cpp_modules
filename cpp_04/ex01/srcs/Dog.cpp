/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:48:50 by alex              #+#    #+#             */
/*   Updated: 2024/04/07 15:45:13 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called 🐕" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &src) : Animal(src)
{
	std::cout << "Dog copy constructor called 🐕" << std::endl;
	*this = src;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called 🐕" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(const Dog &src)
{
	std::cout << "Dog assignment operator called 🐕" << std::endl;
	if (this == &src)
		return (*this);
	Animal::operator=(src);
	this->brain = new Brain(*src.brain);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Wuf Wuf 🐕" << std::endl;
}
