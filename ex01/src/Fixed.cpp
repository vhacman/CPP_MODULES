/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 14:23:04 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** Fixed():
** Default constructor. Initializes the internal fixed-point
** value (_fixedPointValue) to 0 and prints a message.
*/
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
** Fixed(const Fixed &other):
** Copy constructor. Initializes a new Fixed object by copying
** the _fixedPointValue from another instance. Prints a message.
**
*/
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

/*
** ~Fixed():
** Destructor. Called automatically when a Fixed object goes out
** of scope or is deleted. Prints a message.
*/
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
** operator=(const Fixed &other):
** Copy assignment operator. Assigns the value from another Fixed
** instance to the current one, checking for self-assignment.
** - Uses getRawBits() to retrieve the raw value from 'other'.
** - Returns a reference to *this to allow chain assignment.
** - Prints a message each time it is called.
*/
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

/*
** Integer constructor. Initializes a Fixed object from
** a standard integer value.
**
** Behavior:
**   - Prints "Int constructor called".
**   - Converts intValue to fixed-point format by shifting
**     it left by _fractionalBits bits (equivalent to
**     multiplying by 2^_fractionalBits).
**
** Example:
**   Fixed a(3);
**   // _fixedPointValue = 3 << 8 = 768
*/
Fixed::Fixed(int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << this->_fractionalBits;
}

/*
** Floating-point constructor. Initializes a Fixed object
** from a floating-point value.
**
** Behavior:
**   - Prints "Float constructor called".
**   - Multiplies floatValue by 2^_fractionalBits to scale it
**     into fixed-point form.
**   - Uses roundf() to round the result to the nearest integer
**     for accurate representation.
**
** Example:
**   Fixed b(3.14f);
**   // _fixedPointValue ≈ roundf(3.14 * 256) ≈ 804
*/
Fixed::Fixed(float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(::roundf(floatValue * (1 << this->_fractionalBits)));
}

/*
** Returns the current raw fixed-point value (_fixedPointValue).
** Also prints a message when called.
*/
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> _fixedPointValue);
}

/*
** setRawBits(int const raw):
** Sets the internal fixed-point value to 'raw'.
** Does not print anything.
*/
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

/*
** Converts the internal fixed-point value to a floating-point number.
**   - Divides _fixedPointValue by 2^_fractionalBits to restore the
**     original floating-point scale.
**   - Casts the result to float for accurate decimal representation.
**   - The fixed-point value expressed as a float.
**
** Example:
**   If _fixedPointValue = 256 and _fractionalBits = 8,
**   toFloat() returns 1.0.
*/
float	Fixed::toFloat(void) const {
	return ((float)(this->_fixedPointValue) / (1 << Fixed::_fractionalBits));
}

/*
** Converts the internal fixed-point value to an integer by
** discarding the fractional part.
**   - Right-shifts _fixedPointValue by _fractionalBits bits,
**     effectively dividing by 2^_fractionalBits.
** Return:
**   - The integer portion of the fixed-point value.
**
** Example:
**   If _fixedPointValue = 640 and _fractionalBits = 8,
**   toInt() returns 2 (fraction truncated).
*/
int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> Fixed::_fractionalBits);
}

/*
** operator<< (overload):
** Enables direct streaming of a Fixed object to an output stream.
**
** Parameters:
**   - out: reference to the target std::ostream.
**   - fixedValue: const reference to the Fixed object to print.
**
** Behavior:
**   - Inserts the floating-point representation of fixedValue
**     into the output stream using toFloat().
**
** Return:
**   - Reference to the output stream to allow chaining of << operators.
**
** Example:
**   Fixed a(3.5f);
**   std::cout << a;   // prints "3.5"
*/
std::ostream&	operator<<(std::ostream &out, const Fixed &fixedValue) {
	out << fixedValue.toFloat();
	return (out);
}
