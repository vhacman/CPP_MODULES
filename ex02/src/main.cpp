/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:05:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:36:57 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** ============================================================================
**  DEMONSTRATING ALL FIXED-POINT OPERATORS
** ============================================================================
**
** This program tests all major operator overloads:
**   1. Comparison and arithmetic operators
**   2. Pre and post-increment behavior
**   3. Static min/max utility functions
**   4. Stream insertion operator for printing
** ============================================================================
*/
int	main( void ) {
	Fixed		a;
	Fixed const	b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
