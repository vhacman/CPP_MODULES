/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:41:10 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
**   Execute a comprehensive test suite for the Binary Space Partitioning
**   (BSP) algorithm. Tests multiple scenarios to validate the point-in-
**   triangle detection algorithm works correctly.
*/
int	main(void) {
	testStandardTriangle();
	testAlternativeTriangle();
	std::cout << "\n";
	printSeparator();
	std::cout << "    TEST COMPLETED" << std::endl;
	printSeparator();
	std::cout << std::endl;
	return (0);
}
