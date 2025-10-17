/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/17 17:26:53 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
}

Point::Point(Point const &other) : _x(other._x), _y(other._y) {
}

// Copy assignment operator: since _x and _y are const, we can't reassign them
// This operator doesn't actually do anything meaningful for this class
Point	&Point::operator=(Point const &other) {
	(void)other;
	// Cannot assign to const members, but I need this for Orthodox Canonical Form
	return (*this);
}

Point::~Point() {
}

Fixed	Point::getX(void) const {
	return (_x);
}

Fixed	Point::getY(void) const {
	return (_y);
}
