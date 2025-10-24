/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 13:46:05 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** This function computes the cross product of two vectors:
**   - Vector 1: from edgeEnd to testPoint
**   - Vector 2: from edgeEnd to edgeStart
**
** The cross product tells us on which side of the edge the point lies:
**   - Positive value: point is on the left side of the edge
**   - Negative value: point is on the right side of the edge
**   - Zero: point lies exactly on the edge
**
**   testPoint  - The point we want to test
**   edgeStart  - Start vertex of the triangle edge
**   edgeEnd    - End vertex of the triangle edge
**
** Returns: Fixed point number representing the cross product
*/
static Fixed	getOrientation(Point const &testPoint,
								Point const &edgeStart, Point const &edgeEnd)
{
	// Create vector from edgeEnd to testPoint
	Fixed	vec1_x = testPoint.getX() - edgeEnd.getX();
	Fixed	vec1_y = testPoint.getY() - edgeEnd.getY();

	// Create vector from edgeEnd to edgeStart
	Fixed	vec2_x = edgeStart.getX() - edgeEnd.getX();
	Fixed	vec2_y = edgeStart.getY() - edgeEnd.getY();

	// Calculate cross product: (vec1_x * vec2_y) - (vec2_x * vec1_y)
	Fixed	crossProduct = ((vec1_x * vec2_y) - (vec2_x * vec1_y));
	return (crossProduct);
}

/*
** BSP (Binary Space Partitioning) 
** Determines if a point is inside a triangle using the cross product method.
**   1. Calculate the orientation (cross product) of the point relative to
**      each of the three edges of the triangle (AB, BC, CA)
**   2. If the point lies exactly on any edge (orientation == 0), it's
**      considered OUTSIDE.
**   3. If all three orientations have the same sign (all positive or all
**      negative), the point is INSIDE the triangle
**   4. If the signs are mixed, the point is OUTSIDE
**
** Why this works:
**   When a point is inside a triangle, it will be on the same side
**   (either left or right) of all three edges. The cross product gives
**   us a consistent sign for all edges when the point is inside.
** Returns: true if point is strictly inside the triangle, false otherwise
*/
bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	orientation_ab;
	Fixed	orientation_bc;
	Fixed	orientation_ca;
	bool	has_neg;
	bool	has_pos;

	// Calculate the orientation of the point relative to each edge
	orientation_ab = getOrientation(point, a, b);
	orientation_bc = getOrientation(point, b, c);
	orientation_ca = getOrientation(point, c, a);

	// If the point lies exactly on any edge, it's considered outside
	if (orientation_ab == Fixed(0) || orientation_bc == Fixed(0) || orientation_ca == Fixed(0))
		return (false);

	has_neg = ((orientation_ab < Fixed(0)) || (orientation_bc < Fixed(0)) || (orientation_ca < Fixed(0)));
	has_pos = ((orientation_ab > Fixed(0)) || (orientation_bc > Fixed(0)) || (orientation_ca > Fixed(0)));

	// The point is inside only if all orientations have the same sign
	return !(has_neg && has_pos);
}
