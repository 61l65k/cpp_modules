/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:37:55 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 11:46:23 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float n);
        Fixed(const Fixed &src);
        ~Fixed(void);
        Fixed&  operator=(const Fixed &rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const Raw);
        float   toFloat(void)   const;
        int     toInt(void)     const;
};
std::ostream&   operator<<(std::ostream &o, Fixed const &rhs);
#endif
