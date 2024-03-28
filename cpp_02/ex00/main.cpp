/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:37:50 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 10:41:54 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/** Consturctrs ( default, copy, assign ) ~destructor
* 1. First instance with normal constructor
* 2. Second instance with copy constructor-
* we copy the state of the first instance to the second instance
* 3. Third instance with the copy assignment operator
*/
/** Fixed point example with 8 fractional bits
* example: 1.5 represented in fixed point format
* 1.5 × 2^8 = 1.5 × 256 = 384
*/

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}