/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 09:37:50 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/01 17:24:03 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*** Main triangle 
// Arithmetic operators, use floats cos not so prone to overflow
// if we pass fixedpoint to the fixed as argument it will most likely overflow
// cos it will double shift the value

            Vertexc
               (5,5)   C
                 x
               /  \
              /    \
             /      \
            x________x
    Vertexa(0,0)  Vertexb(10,0)  B       

*/
/**
            /\
           /  \ Inside point
          /  x \    (3,2)
         /      \
        /________\

*/
/**
              outsidepoint
            (0,10)
             x   


            /\
           /  \
          /    \
         /      \
        /________\

*/
/**
            /\
           /  \
          /    \
         /      \   Edge point
        /________x      (5,0)

*/

int main(void)
{
    const Point vertexa(0, 0);
    const Point vertexb(10, 0);
    const Point vertexc(5, 5);

    // Test: Point inside the triangle
    const Point insidePoint(3, 2);
    if (bsp(vertexa, vertexb, vertexc, insidePoint))
        std::cout << "Inside point: Inside the triangle" << std::endl;
    else
        std::cout << "Inside point: Outside the triangle" << std::endl;

    // Test: Point outside the triangle
    const Point outsidePoint(0, 10);
    if (bsp(vertexa, vertexb, vertexc, outsidePoint))
        std::cout << "Outside point: Inside the triangle" << std::endl;
    else
        std::cout << "Outside point: Outside the triangle" << std::endl;

    // Test: Point on the edge of the triangle
    const Point edgePoint(3, 5);
    if (bsp(vertexa, vertexb, vertexc, edgePoint))
        std::cout << "Edge point: Inside the triangle" << std::endl;
    else
        std::cout << "Edge point: Outside the triangle" << std::endl;

    return EXIT_SUCCESS;
}
