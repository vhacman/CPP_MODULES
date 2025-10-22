/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 13:42:51 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// constructor: initializes point at origin (0, 0)
Point::Point() : _x(0), _y(0) {
}

// Parameterized constructor: creates point at specified coordinates
// Takes float values which are automatically converted to Fixed-point format
Point::Point(float const x, float const y) : _x(x), _y(y) {
}

// Copy constructor: creates a new point with the same coordinates as other
Point::Point(Point const &other) : _x(other._x), _y(other._y) {
}

/*
** Copy assignment operator 
** Important: Since _x and _y are const, they cannot be reassigned after
** initialization. This makes the assignment operator essentially useless
** for this class, but it must be defined to satisfy OCF requirements.
**
*/
Point	&Point::operator=(Point const &other) {
	(void)other;
	return (*this);
}

// Destructor: no dynamic memory to clean up
Point::~Point() {
}

// Getter: returns the x coordinate as a Fixed-point number
Fixed	Point::getX(void) const {
	return (_x);
}

// Getter: returns the y coordinate as a Fixed-point number
Fixed	Point::getY(void) const {
	return (_y);
}
