/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MoreTesting.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:49:43 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 14:52:29 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/*
               Create objects using different constructors:
**      - Fixed zero                 -->   Default constructor, value 0.0.
**      - Fixed negative(-15.75f)    -->   Float constructor with a negative number.
**      - Fixed verySmall(0.001f)    -->   Float constructor with a very small positive number.
**      - Fixed veryLarge(9999.999f) --> Float constructor with a very large positive number.
**	- For each object, print the floating-point value using
**		operator<< (calls toFloat()).
**	- Print the integer representation using toInt(), which truncates toward zero.
**   - Validates correct handling of:
**        Zero values, Negative numbers, Tiny fractional numbers close to zero,
**        Very large values that still fit in the internal fixed-point range.
*/
void	testEdgeCases(void) {
	std::cout << "\n=== Edge Cases and Boundary Tests ===\n" << std::endl;

	Fixed	zero;
	Fixed	negative(-15.75f);
	Fixed	verySmall(0.001f);
	Fixed	veryLarge(9999.999f);

	std::cout << "zero: " << zero << " (as int: " << zero.toInt() << ")" << std::endl;
	std::cout << "negative: " << negative << " (as int: " << negative.toInt() << ")" << std::endl;
	std::cout << "verySmall: " << verySmall << " (as int: " << verySmall.toInt() << ")" << std::endl;
	std::cout << "veryLarge: " << veryLarge << " (as int: " << veryLarge.toInt() << ")" << std::endl;
}

/*
**      - Fixed x(10.5f);  // Float constructor with value 10.5
**      - Fixed y(20.25f); // Float constructor with value 20.25
**      - Fixed z;         // Default constructor (0.0)
** Display initial values:
**      - Print x, y, and z using operator<< (toFloat()).
** Perform chained assignment:
**       z = y = x;
**  First assigns x to y (calls copy assignment operator).
**  Then assigns y (which now equals x) to z.
**  Returns a reference to y to allow chaining.
*/
void	testAssignmentOperator(void) {
	std::cout << "\n=== Assignment Operator Test ===\n" << std::endl;

	Fixed	x(10.5f);
	Fixed	y(20.25f);
	Fixed	z;

	std::cout << "Before assignment --> x: " << x << ", y: " << y << ", z: " << z << std::endl;
	/* assignment */
	z = y = x;
	std::cout << "After assignment --> x: " << x << ", y: " << y << ", z: " << z << std::endl;
}

/*
** Evaluates how accurately the Fixed class represents
** fractional values given 8 fractional bits.
** Create Fixed objects with progressively smaller
**    fractional components:
**       - precise1(1.0f)
**       - precise2(1.5f)
**       - precise3(1.25f)
**       - precise4(1.125f)
**       - precise5(1.0625f)
**    Each constructor converts the float into the fixed-point
**    format with 8 fractional bits.
** Print each object using operator<<, which outputs the
**    floating-point representation via toFloat().
** Demonstrates the resolution of 8 fractional bits,
** where the smallest distinguishable step is 1/256 ≈ 0.0039.
** Example:
**   Values like 1.125 or 1.0625 should be represented exactly,
**   while numbers requiring more than 8 bits of fractional
**   precision may be rounded.
*/
void	testPrecision(void) {
	std::cout << "\n=== Precision Test ===\n" << std::endl;

	Fixed	precise1(1.0f);
	Fixed	precise2(1.5f);
	Fixed	precise3(1.25f);
	Fixed	precise4(1.125f);
	Fixed	precise5(1.0625f);

	std::cout << "1.0: " << precise1 << std::endl;
	std::cout << "1.5: " << precise2 << std::endl;
	std::cout << "1.25: " << precise3 << std::endl;
	std::cout << "1.125: " << precise4 << std::endl;
	std::cout << "1.0625: " << precise5 << std::endl;
}

/*
** Tests how accurately various floating-point values are converted
** into the Fixed class representation and then back to float/int.
** 2) Define an array of sample floats including:
**			Small positives (0.0, 0.1, 0.5, 0.9, 1.1)
**			Negatives (-0.5, -1.5)
**			Famous constants (3.14159, -2.71828)
** Loop through each value:
**	- Construct a Fixed object using the float constructor,
**	which scales and rounds the value to 8 fractional bits.
**	- Print the original float, the Fixed value as a float
**	(operator<< calls toFloat()), and the integer conversion (toInt()).
*/
void	testFloatConversions(void) {
	std::cout << "\n=== Float to Fixed Conversion Test ===\n" << std::endl;

	float	testFloats[] = {0.0f, 0.1f, 0.5f, 0.9f, 1.1f, -0.5f, -1.5f, 3.14159f, -2.71828f};
	int		numTests;
	int		i;

	numTests = sizeof(testFloats) / sizeof(testFloats[0]);
	for (i = 0; i < numTests; i++) {
		Fixed converted(testFloats[i]);
		std::cout << "Float " << testFloats[i] << " -> Fixed " << converted
				  << " -> Int " << converted.toInt() << std::endl;
	}
}
