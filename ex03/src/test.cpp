/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:54:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 11:21:29 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// Test 1: Verifica punti all'interno del triangolo
static void	testPointsInside(Point const &a, Point const &b, Point const &c) {
	bool	result;

	printTestGroup("Test 1: Points inside the triangle");

	Point p1(1.0f, 0.8f);
	result = bsp(a, b, c, p1);
	printResult("Point (1.0, 0.8)", result, true);

	Point p2(0.5f, 0.3f);
	result = bsp(a, b, c, p2);
	printResult("Point (0.5, 0.3)", result, true);

	Point p3(1.4f, 0.5f);
	result = bsp(a, b, c, p3);
	printResult("Point (1.4, 0.5)", result, true);

	Point p4(1.0f, 1.2f);
	result = bsp(a, b, c, p4);
	printResult("Point (1.0, 1.2)", result, true);
}

// Test 2: Verifica che i punti sui vertici siano considerati fuori
static void	testPointsOnVertices(Point const &a, Point const &b, Point const &c) {
	bool	result;

	printTestGroup("Test 2: Points on vertices (should be outside)");

	result = bsp(a, b, c, a);
	printResult("Point A (0.0, 0.0)", result, false);

	result = bsp(a, b, c, b);
	printResult("Point B (2.0, 0.0)", result, false);

	result = bsp(a, b, c, c);
	printResult("Point C (1.0, 2.0)", result, false);
}

// Test 3: Verifica che i punti sui lati siano considerati fuori
static void	testPointsOnEdges(Point const &a, Point const &b, Point const &c) {
	bool	result;

	printTestGroup("Test 3: Points on edges (should be outside)");

	Point p5(1.0f, 0.0f);
	result = bsp(a, b, c, p5);
	printResult("Point (1.0, 0.0) - middle of AB", result, false);

	Point p6(0.5f, 1.0f);
	result = bsp(a, b, c, p6);
	printResult("Point (0.5, 1.0) - on AC", result, false);

	Point p7(1.5f, 1.0f);
	result = bsp(a, b, c, p7);
	printResult("Point (1.5, 1.0) - on BC", result, false);
}

// Test 4: Verifica punti chiaramente fuori dal triangolo
static void	testPointsOutside(Point const &a, Point const &b, Point const &c) {
	bool	result;

	printTestGroup("Test 4: Points outside the triangle");

	Point p8(-0.5f, 0.0f);
	result = bsp(a, b, c, p8);
	printResult("Point (-0.5, 0.0)", result, false);

	Point p9(2.5f, 0.0f);
	result = bsp(a, b, c, p9);
	printResult("Point (2.5, 0.0)", result, false);

	Point p10(1.0f, 2.5f);
	result = bsp(a, b, c, p10);
	printResult("Point (1.0, 2.5)", result, false);

	Point p11(1.0f, -0.5f);
	result = bsp(a, b, c, p11);
	printResult("Point (1.0, -0.5)", result, false);

	Point p12(0.0f, 1.5f);
	result = bsp(a, b, c, p12);
	printResult("Point (0.0, 1.5)", result, false);

	Point p13(2.0f, 1.5f);
	result = bsp(a, b, c, p13);
	printResult("Point (2.0, 1.5)", result, false);
}

// Esegue tutti i test su un triangolo standard
void	testStandardTriangle(void) {
	printHeader("BSP TRIANGLE");

	Point	a(0.0f, 0.0f);
	Point	b(2.0f, 0.0f);
	Point	c(1.0f, 2.0f);

	printTriangleInfo(a, b, c);
	testPointsInside(a, b, c);
	testPointsOnVertices(a, b, c);
	testPointsOnEdges(a, b, c);
	testPointsOutside(a, b, c);
}

// Test 5: Verifica con un triangolo diverso (coordinate negative)
void	testAlternativeTriangle(void) {
	bool	result;

	printHeader("Test 5: Different triangle");

	Point a2(-2.0f, -2.0f);
	Point b2(2.0f, -2.0f);
	Point c2(0.0f, 2.0f);

	printTriangleInfo(a2, b2, c2);

	// Test punto al centro
	Point p14(0.0f, 0.0f);
	result = bsp(a2, b2, c2, p14);
	printResult("Point (0.0, 0.0) - center", result, true);

	// Test punto sul lato
	Point p15(0.0f, -2.0f);
	result = bsp(a2, b2, c2, p15);
	printResult("Point (0.0, -2.0) - on edge", result, false);

	// Test punto esterno
	Point p16(3.0f, 0.0f);
	result = bsp(a2, b2, c2, p16);
	printResult("Point (3.0, 0.0) - outside", result, false);
}
