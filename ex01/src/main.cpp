/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:38:15 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:26:16 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** - a = Fixed(1234.4321f);
**	Creates a temporary Fixed from a float and assigns
**	it to a using the copy assignment operator.
**	- Print each object using operator<<, which outputs
**		the floating-point value (via toFloat()).
**	- Print each object's integer representation using
**		toInt(), which truncates the fractional part.
*/
static void testBasicConstructors(void) {
	std::cout << "\n=== Subject Tests ===\n" << std::endl;

	Fixed		a;
	Fixed const	b(10);
	Fixed const	c(42.42f);
	Fixed const	d(b);

	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	runAllTests(void) {
	testBasicConstructors();
	testEdgeCases();
	testAssignmentOperator();
	testPrecision();
	testFloatConversions();
}

int	main(void) {
	runAllTests();
	return (0);
}
