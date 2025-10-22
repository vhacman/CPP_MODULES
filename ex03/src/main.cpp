/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 13:30:09 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** Main function - BSP (Binary Space Partitioning) test program
**
** This program tests the bsp() function which determines if a point
** is inside a triangle. It runs two sets of comprehensive tests:
**
** 1. testStandardTriangle() - Tests with a standard triangle with
**    positive coordinates
**
** 2. testAlternativeTriangle() - Tests with a triangle that includes
**    negative coordinates to verify the algorithm works in all quadrants
**
** Each test suite verifies:
**   - Points clearly inside the triangle
**   - Points on the vertices (should be outside)
**   - Points on the edges (should be outside)
**   - Points clearly outside the triangle
**
** The output is color-coded with PASS/FAIL indicators for easy evaluation.
*/
int	main(void) {
	// Run comprehensive tests on a standard triangle
	testStandardTriangle();
	std::cout << "\n";

	// Run tests on an alternative triangle configuration
	testAlternativeTriangle();
	std::cout << "\n";

	return (0);
}
