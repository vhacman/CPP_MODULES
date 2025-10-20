/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 14:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 11:18:25 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {

	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &other);
		Point	&operator=(Point const &other);
		~Point();

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

// BSP function declaration
bool	bsp(Point const a, Point const b, Point const c, Point const point);

// Utility functions
void	printTriangleInfo(Point const &a, Point const &b, Point const &c);
void	printTestGroup(std::string title);
void	printResult(std::string testName, bool result, bool expected);
void	printSeparator(void);
void	printHeader(std::string title);

// Test functions
void	testStandardTriangle(void);
void	testAlternativeTriangle(void);

#endif
