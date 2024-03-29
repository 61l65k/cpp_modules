/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:38:00 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 12:53:19 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {}

Fixed::Fixed(const int n) : _fixedPointValue(n << _fractionalBits){}

Fixed::Fixed(const float n) : _fixedPointValue(roundf(n * (1 << _fractionalBits))){}

Fixed::Fixed(const Fixed &src)
{
    *this = src;
}

Fixed::~Fixed() {}

Fixed&  Fixed::operator=(const Fixed &rhs)
{
    if (this != &rhs)
        _fixedPointValue = rhs.getRawBits();
    return *this;
}

int     Fixed::getRawBits(void) const
{
    return _fixedPointValue;
}

void    Fixed::setRawBits(int const raw)
{
    _fixedPointValue = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(_fixedPointValue) / (1 << _fractionalBits));
}

int     Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}

std::ostream&   operator<<(std::ostream &o, Fixed const &rhs)
{
    o << rhs.toFloat();
    return o;
}

bool    Fixed::operator>(const Fixed &rhs) const { return (_fixedPointValue > rhs.getRawBits()); }

bool    Fixed::operator<(const Fixed &rhs) const { return (_fixedPointValue < rhs.getRawBits()); }

bool    Fixed::operator>=(const Fixed &rhs) const { return (_fixedPointValue >= rhs.getRawBits()); }

bool    Fixed::operator<=(const Fixed &rhs) const { return (_fixedPointValue <= rhs.getRawBits()); }

bool    Fixed::operator==(const Fixed &rhs) const { return (_fixedPointValue == rhs.getRawBits()); }

bool    Fixed::operator!=(const Fixed &rhs) const { return (_fixedPointValue != rhs.getRawBits()); }

Fixed   Fixed::operator+(const Fixed &rhs) const { return (Fixed(toFloat() + rhs.toFloat())); }

Fixed   Fixed::operator-(const Fixed &rhs) const { return (Fixed(toFloat() - rhs.toFloat())); }

Fixed   Fixed::operator*(const Fixed &rhs) const { return (Fixed(toFloat() * rhs.toFloat())); }

Fixed   Fixed::operator/(const Fixed &rhs) const { return (Fixed(toFloat() / rhs.toFloat())); }

Fixed&  Fixed::operator++(void)
{
    _fixedPointValue++;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed&  Fixed::operator--(void)
{
    _fixedPointValue--;
    return *this;
}

Fixed   Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}


Fixed&  Fixed::min(Fixed &a, Fixed &b) { return (a < b ? a : b); }

Fixed& Fixed::max(Fixed &a, Fixed &b) { return (a > b ? a : b); }

const Fixed&  Fixed::min(const Fixed &a, const Fixed &b) { return (a < b ? a : b); }

const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return (a > b ? a : b); }
