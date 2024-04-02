/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:05:47 by apyykone          #+#    #+#             */
/*   Updated: 2024/04/01 18:20:13 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
          C
         / \
        /   \
       /     \
      /   P   \  <- Point P is being checked if it's inside the triangle
     /         \
    A-----------B

- The `bsp` function checks if P is inside triangle ABC.
- `isOnSameSide` is used to determine if P and each vertex (A, B, C) are on the same side of the opposite edge.
- For example, it checks if P and C are on the same side of the line AB, and so on for other edges.
*/

static bool isOnSameSide(const Point& edgeStart, const Point& edgeEnd, const Point& point1, const Point& point2)
{
    Fixed x1 = edgeEnd.getX() - edgeStart.getX();
    Fixed y1 = edgeEnd.getY() - edgeStart.getY();
    Fixed x2 = point1.getX() - edgeStart.getX();
    Fixed y2 = point1.getY() - edgeStart.getY();
    Fixed x3 = point2.getX() - edgeStart.getX();
    Fixed y3 = point2.getY() - edgeStart.getY();
    
    Fixed cross1 = x1 * y2 - x2 * y1;
    Fixed cross2 = x1 * y3 - x3 * y1;

    if (cross1 == 0 || cross2 == 0) return false;

    return (cross1 * cross2 > 0);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    return isOnSameSide(a, b, c, point) && 
           isOnSameSide(b, c, a, point) && 
           isOnSameSide(c, a, b, point);
}
