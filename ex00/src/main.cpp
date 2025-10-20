/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:54 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:23:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
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
**		- c.getRawBits()*/
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
