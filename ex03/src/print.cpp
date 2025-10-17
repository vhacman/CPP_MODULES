/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:50:46 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/17 17:29:05 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void	printResult(std::string testName, bool result, bool expected) {
	const char*	status;

	std::cout << testName << ": ";
	if (result == expected)
		std::cout << "\033[32m✓ PASS\033[0m";
	else
		std::cout << "\033[31m✗ FAIL\033[0m";
	if (result)
		status = "inside";
	else
		status = "outside";
	std::cout << " (Result: " << status << ")" << std::endl;
}

void	printSeparator(void) {
	std::cout << "========================================" << std::endl;
}

void	printHeader(std::string title) {
	printSeparator();
	std::cout << "    " << title << std::endl;
	printSeparator();
	std::cout << std::endl;
}

void	printTriangleInfo(Point const &a, Point const &b, Point const &c) {
	std::cout << "Triangle vertices:" << std::endl;
	std::cout << "  A: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "  B: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "  C: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	std::cout << std::endl;
}

void	printTestGroup(std::string title) {
	std::cout << title << std::endl;
	std::cout << std::string(title.length(), '-') << std::endl;
}
