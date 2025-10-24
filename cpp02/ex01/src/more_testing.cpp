/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_testing.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:49:43 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 10:59:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

/* Create objects using different constructors:
  	- For each object, print the floating-point value using
  		operator<<
  	- Print the integer representation using toInt(),
    which truncates toward zero.
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
        - Fixed x(10.5f);
        - Fixed y(20.25f);
        - Fixed z;
   Perform chained assignment:
         z = y = x;
   Returns a reference to y to allow chaining.
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
   Evaluates how accurately the Fixed class represents
   fractional values given 8 fractional bits.
   Create Fixed objects with progressively smaller fractional components:
         - precise1(1.0f)
         - precise2(1.5f)
         - precise3(1.25f)
         - precise4(1.125f)
         - precise5(1.0625f)
      Each constructor converts the float into the fixed-point
      format with 8 fractional bits.
*/
void	testPrecision(void) {
	std::cout << "\n=== Precision Test ===\n" << std::endl;

	Fixed	precise1(1.0f);
	Fixed	precise2(1.5f);
	Fixed	precise3(1.25f);
	Fixed	precise4(1.125f);
	Fixed	precise5(1.0625f);

	std::cout << "Precise1 is: " << precise1 << std::endl;
	std::cout << "Precise2 is: " << precise2 << std::endl;
	std::cout << "Precise3 is: " << precise3 << std::endl;
	std::cout << "Precise4 is: " << precise4 << std::endl;
	std::cout << "Precise5 is: " << precise5 << std::endl;
}

/*
   Tests how accurately various floating-point values are converted
   into the Fixed class representation and then back to float/int.

   Define an array of sample floats including:
  			Small positives (0.0, 0.1, 0.5, 0.9, 1.1)
  			Negatives (-0.5, -1.5)
  			Famous constants (3.14159, -2.71828)
   Loop through each value:
  	- Construct a Fixed object using the float constructor,
  	which scales and rounds the value to 8 fractional bits.
  	- Print the original float, the Fixed value as a float
  	(operator<< calls toFloat()), and the integer conversion (toInt()).
*/
void	testFloatConversions(void) {
	std::cout << "\n=== Float to Fixed Conversion Test ===\n" << std::endl;

	float	testFloats[] = {0.0f, 0.1f, 0.5f, 0.9f, 1.1f, -0.5f, -1.5f, 3.14159f, -2.71828f};
	int		numTests;
	int		i;

	numTests = sizeof(testFloats) / sizeof(testFloats[0]);
	// for (i = 0; i < numTests; i++) {
	// 	Fixed converted(testFloats[i]);
	// 	std::cout << "Float " << testFloats[i] << " -> Fixed " << converted
	// 			  << " -> Int " << converted.toInt() << std::endl;
	// }
	i = 0;
	while (i < numTests)
	{
		Fixed	converted(testFloats[i]);
		std::cout << "FLoat " << testFloats[i] << "--> Fixed" << converted 
					<< "--> Int " << converted.toInt() << std::endl;
		i++;
	}
}
