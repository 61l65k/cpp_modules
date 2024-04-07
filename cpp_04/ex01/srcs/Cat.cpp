/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 14:49:57 by alex              #+#    #+#             */
/*   Updated: 2024/04/07 15:44:28 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called 🐈" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &src) : Animal(src)
{
	std::cout << "Cat copy constructor called 🐈" << std::endl;
	*this = src;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called 🐈" << std::endl;
	delete this->brain;
}

Cat &Cat::operator=(const Cat &src)
{
	std::cout << "Cat assignment operator called 🐈" << std::endl;
	if (this == &src)
		return (*this);
	Animal::operator=(src);
	this->brain = new Brain(*src.brain);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow 🐈" << std::endl;
}
