/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:54:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 13:44:47 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

/*
** This file contains comprehensive tests to verify the correctness of the
** bsp() function.
*/

/*
** Test 1: Points strictly inside the triangle
**
** This test verifies that the algorithm correctly identifies points that
** are clearly inside the triangle boundaries. 
*/
static void	testPointsInside(Point const &a, Point const &b, Point const &c) {
	bool	result;

	std::cout << "\n";
	printTestGroup("Points inside the triangle");

	// Test point near the top of the triangle
	Point	p1(1.0f, 0.8f);
	result = bsp(a, b, c, p1);
	printResult("Point1 (1.0, 0.8)", result, true);

	// Test point near the bottom-left
	Point	p2(0.5f, 0.3f);
	result = bsp(a, b, c, p2);
	printResult("Point2 (0.5, 0.3)", result, true);

	// Test point near the bottom-right
	Point	p3(1.4f, 0.5f);
	result = bsp(a, b, c, p3);
	printResult("Point3 (1.4, 0.5)", result, true);

	// Test point in the upper-middle area
	Point	p4(1.0f, 1.2f);
	result = bsp(a, b, c, p4);
	printResult("Point4 (1.0, 1.2)", result, true);
}

/*
** Test 2: Points on triangle vertices
** According to the subject requirements, points that lie exactly on
** the vertices of the triangle are considered OUTSIDE the triangle.
*/
static void	testPointsOnVertices(Point const &a, Point const &b, Point const &c) {
	bool	result;

	std::cout << "\n";
	printTestGroup("Points on vertices (should be outside)");

	// Test point coinciding with vertex A
	result = bsp(a, b, c, a);
	printResult("Point A (0.0, 0.0)", result, false);

	// Test point coinciding with vertex B
	result = bsp(a, b, c, b);
	printResult("Point B (2.0, 0.0)", result, false);

	// Test point coinciding with vertex C
	result = bsp(a, b, c, c);
	printResult("Point C (1.0, 2.0)", result, false);
}

/*
** Test 3: Points on triangle edges
**
** According to the subject requirements, points that lie exactly on
** the edges of the triangle are considered OUTSIDE the triangle.
** This test verifies that the algorithm detects points on each of the
** three edges (AB, AC, BC) and correctly returns false.
*/
static void	testPointsOnEdges(Point const &a, Point const &b, Point const &c) {
	bool	result;

	std::cout << "\n";
	printTestGroup("Points on edges (should be outside)");

	// Point on edge AB (between vertices A and B)
	Point	p5(1.0f, 0.0f);
	result = bsp(a, b, c, p5);
	printResult("Point1 (1.0, 0.0) - middle of AB", result, false);

	// Point on edge AC (between vertices A and C)
	Point	p6(0.5f, 1.0f);
	result = bsp(a, b, c, p6);
	printResult("Point2 (0.5, 1.0) - on AC", result, false);

	// Point on edge BC (between vertices B and C)
	Point	p7(1.5f, 1.0f);
	result = bsp(a, b, c, p7);
	printResult("Point3 (1.5, 1.0) - on BC", result, false);
}

/*
** Test 4: Points clearly outside the triangle
**
** This test verifies that the algorithm correctly identifies points that
** are clearly outside the triangle boundaries.
*/
static void	testPointsOutside(Point const &a, Point const &b, Point const &c) {
	bool	result;

	std::cout << "\n";
	printTestGroup("Points outside the triangle");

	// Point to the left of the triangle
	Point	p8(-0.5f, 0.0f);
	result = bsp(a, b, c, p8);
	printResult("Point1 (-0.5, 0.0)", result, false);

	// Point to the right of the triangle
	Point	p9(2.5f, 0.0f);
	result = bsp(a, b, c, p9);
	printResult("Point2 (2.5, 0.0)", result, false);

	// Point above the triangle
	Point	p10(1.0f, 2.5f);
	result = bsp(a, b, c, p10);
	printResult("Point3 (1.0, 2.5)", result, false);

	// Point below the triangle
	Point	p11(1.0f, -0.5f);
	result = bsp(a, b, c, p11);
	printResult("Point4 (1.0, -0.5)", result, false);

	// Point to the upper-left of the triangle
	Point	p12(0.0f, 1.5f);
	result = bsp(a, b, c, p12);
	printResult("Point5 (0.0, 1.5)", result, false);

	// Point to the upper-right of the triangle
	Point	p13(2.0f, 1.5f);
	result = bsp(a, b, c, p13);
	printResult("Point6 (2.0, 1.5)", result, false);
}

/*
** Test Suite 1: Standard Triangle
**
** This function runs a comprehensive test suite on a standard triangle
** with positive coordinates:
**   A(0, 0) - bottom-left
**   B(2, 0) - bottom-right
**   C(1, 2) - top
**
*/
void	testStandardTriangle(void) {
	printHeader("BSP TRIANGLE");

	// Define triangle vertices
	Point	a(0.0f, 0.0f);
	Point	b(2.0f, 0.0f);
	Point	c(1.0f, 2.0f);

	printTriangleInfo(a, b, c);
	testPointsInside(a, b, c);
	testPointsOnVertices(a, b, c);
	testPointsOnEdges(a, b, c);
	testPointsOutside(a, b, c);
}

/*
** Test Suite 2: Alternative Triangle with Negative Coordinates
**
** This function tests the bsp() algorithm with a different triangle
** configuration that includes negative coordinates
**   A(-2, -2) - bottom-left (negative x and y)
**   B(2, -2)  - bottom-right (negative y only)
**   C(0, 2)   - top (positive y only)
*/
void	testAlternativeTriangle(void) {
	bool	result;

	printHeader("Different triangle");

	// Define alternative triangle vertices
	Point	a2(-2.0f, -2.0f);
	Point	b2(2.0f, -2.0f);
	Point	c2(0.0f, 2.0f);

	printTriangleInfo(a2, b2, c2);

	// Test point at the center of the triangle - should be INSIDE
	Point	p14(0.0f, 0.0f);
	result = bsp(a2, b2, c2, p14);
	printResult("Point in the middle (0.0, 0.0) - center", result, true);

	// Test point on the bottom edge - should be OUTSIDE
	Point	p15(0.0f, -2.0f);
	result = bsp(a2, b2, c2, p15);
	printResult("Point on edge (0.0, -2.0) - on edge", result, false);

	// Test point far to the right - should be OUTSIDE
	Point	p16(3.0f, 0.0f);
	result = bsp(a2, b2, c2, p16);
	printResult("Point outside (3.0, 0.0) - outside", result, false);
}
