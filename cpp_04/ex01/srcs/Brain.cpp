/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alex <alex@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 15:28:12 by alex              #+#    #+#             */
/*   Updated: 2024/04/07 15:39:10 by alex             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called 🧠" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "";
}

Brain::Brain(const Brain &src)
{
	std::cout << "Brain copy constructor called 🧠" << std::endl;
	*this = src;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called 🧠" << std::endl;
}

Brain	&Brain::operator=(const Brain &src)
{
	std::cout << "Brain assignment operator called 🧠" << std::endl;
	if (this == &src)
		return (*this);
	for (int i = 0; i < 100; i++)
			this->ideas[i] = src.ideas[i];
	return (*this);
}
