/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apyykone <apyykone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:50:19 by apyykone          #+#    #+#             */
/*   Updated: 2024/03/28 14:15:49 by apyykone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &point) : x(point.x), y(point.y) {}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point() {}

Point &Point::operator=(const Point &point) {
	(void)point;
	return (*this);
}

Fixed Point::getX() const { return (this->x); }

Fixed Point::getY() const { return (this->y); }
