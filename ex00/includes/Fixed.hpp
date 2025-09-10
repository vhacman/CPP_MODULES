/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:51:58 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/10 14:20:03 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

/*
** Class Fixed
**
** Purpose:
**   Represents a fixed-point number with 8 fractional bits.
**   Demonstrates encapsulation and the "canonical form"
**   (default constructor, copy constructor, destructor,
**   and copy assignment operator).
**
** Private attributes:
**   - _fixedPointValue:
**       Stores the raw fixed-point value as an integer.
**       This member is private, so it cannot be accessed
**       directly outside the class. Access must be done
**       via getter/setter methods.
**
**   - static const int _fractionalBits = 8:
**       Constant number of fractional bits used for the
**       fixed-point representation. Declared static so
**       that all instances of Fixed share the same value.
**
** Public methods:
**   - Fixed():
**       Default constructor. Initializes _fixedPointValue to 0.
**
**   - Fixed(const Fixed &other):
**       Copy constructor. Creates a new Fixed object by copying
**       the internal value from 'other'.
**
**   - Fixed& operator=(const Fixed &other):
**       Copy assignment operator. Assigns the value of one Fixed
**       object to another, with a check for self-assignment.
**       Returns a reference to the current object.
**
**   - ~Fixed():
**       Destructor. Cleans up when a Fixed object goes out of scope.
**
**   - int getRawBits() const:
**       Getter. Returns the current raw fixed-point value.
**
**   - void setRawBits(int const raw):
**       Setter. Updates the internal raw fixed-point value.
**
** Notes:
** - Encapsulation ensures that _fixedPointValue cannot be
**   directly modified from outside the class.
** - _fractionalBits is shared among all instances, since
**   it is a fixed property of the representation and does
**   not change per object.
** - The print statements in the implementation are used
**   for debugging, showing when each special member function
**   is called.
*/
class Fixed
{
private:
	int					_fixedPointValue;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &other);
	Fixed&	operator=(const Fixed &other);
	~Fixed();

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
