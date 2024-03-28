/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:38:00 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 10:41:23 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"


Fixed::Fixed() : _fixed_point_nb(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=  (const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixed_point_nb = other.getRawBits();
    }
    return (*this);
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixed_point_nb);
}

void Fixed::setRawBits( int const raw )
{
    this->_fixed_point_nb = raw;
}