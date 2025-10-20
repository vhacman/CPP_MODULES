/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:40:17 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
**   Calculate the cross product (signed area) to determine which side of a
**   line a point lies on. This is the mathematical foundation of the BSP
**   algorithm.
**
** Parameters:
**   - p1: The point to test (which side of the line is it on?)
**   - p2: First vertex of the line
**   - p3: Second vertex of the line
**
** Returns: Fixed (cross product value)
**   - Positive (> 0): p1 is on the LEFT side of line p2→p3
**   - Negative (< 0): p1 is on the RIGHT side of line p2→p3
**   - Zero (= 0): p1 is exactly ON the line
**
** Mathematical Background (2D Cross Product):
**   The cross product of vectors v1 and v2 is calculated as: cross = (v1.x * v2.y) - (v1.x * v2.y)
**   The sign of the result tells us the orientation:
**   - If positive: p1 is counterclockwise from p2 (when viewed from p3)
**   - If negative: p1 is clockwise from p2
**   - If zero: p1 is collinear with the line p2-p3
*/
static Fixed	sign(Point const &p1, Point const &p2, Point const &p3) {
	Fixed diffx1;
	Fixed diffy2;
	Fixed diffx2;
	Fixed diffy1;

	diffx1 = p1.getX() - p3.getX();
	diffy2 = p2.getY() - p3.getY();
	diffx2 = p2.getX() - p3.getX();
	diffy1 = p1.getY() - p3.getY();
	return (diffx1 * diffy2 - diffx2 * diffy1);
}

/*
** Binary Space Partitioning (BSP)
**
** Purpose:
**   Determine if a point lies strictly INSIDE a triangle. Points on edges
**   or vertices are considered OUTSIDE.
**
** Parameters:
**   - a, b, c: The three vertices of the triangle (const references).
**   - point: The point to test (const reference).
**
** Returns: bool
**   - true: The point is strictly INSIDE the triangle.
**   - false: The point is OUTSIDE the triangle OR on its boundary.
**
** ALGORITHM EXPLANATION:
**
** Core Principle:
**   A point is inside a triangle if and only if it is on the SAME SIDE
**   of all three edges of the triangle.
** Steps:
**   1. Calculate cross product for each edge (using sign() function)
**   2. Check if any cross product is zero (point on boundary)
**   3. Check if all cross products have the same sign
**
** Important Edge Cases:
**   - Point on vertex → returns false (on boundary)
**   - Point on edge → returns false (on boundary)
**   - Point exactly at same location as vertex → returns false*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	d1;
	Fixed	d2;
	Fixed	d3;
	bool	has_neg;
	bool	has_pos;

	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);
	if (d1 == Fixed(0) || d2 == Fixed(0) || d3 == Fixed(0))
		return (false);
	has_neg = (d1 < Fixed(0)) || (d2 < Fixed(0)) || (d3 < Fixed(0));
	has_pos = (d1 > Fixed(0)) || (d2 > Fixed(0)) || (d3 > Fixed(0));
	return !(has_neg && has_pos);
}
