/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:37:55 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 10:42:01 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixed_point_nb;
    static const int _fractional_bits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed&  operator=  (const Fixed& other);
    ~Fixed();

    int getRawBits( void ) const;
    void setRawBits( int const raw );
};


#endif