/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:54 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 12:40:29 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** main():
** Demonstrates the canonical form of the Fixed class by creating
** objects and observing constructor, copy, and assignment behavior.
** 1) Fixed a;
**		- Calls the default constructor.
**		- Initializes 'a' with _fixedPointValue = 0.
** 2) Fixed b(a);
**		- Calls the copy constructor.
**		- Initializes 'b' by copying the value from 'a'.
** 3) Fixed c;
**		- Calls the default constructor.
**		- Initializes 'c' with _fixedPointValue = 0.
** 4) c = b;
**		- Calls the copy assignment operator.
**		- Assigns the raw bits of 'b' to 'c'.
** 5) Print raw values:
**		- a.getRawBits()
**		- b.getRawBits()
**		- c.getRawBits()
**	Each call also prints a message from getRawBits().
*/
int	main(void) {
	Fixed	a;
	Fixed	b(a);
	Fixed	c;

	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
