/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 10:54:38 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other._fixedPointValue;
	}
	return (*this);
}

/*     Initializes a Fixed object from a standard integer value.
     - Converts intValue to fixed-point format by shifting
       it left by _fractionalBits bits (multiplying by 2^_fractionalBits).
*/
Fixed::Fixed(int intValue) {
	std::cout << "Int constructor called" << std::endl;
	int	result;

	result = intValue << this->_fractionalBits;
	this->_fixedPointValue = result;
}

/*     Initializes a Fixed object from a floating-point value.
     - Multiplies floatValue by 2^_fractionalBits to scale it
       into fixed-point form.
     - Uses roundf() to round the result to the nearest integer
       for accurate representation.
*/
Fixed::Fixed(float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	int	result;

	result = (int)(::roundf(floatValue * (1 << this->_fractionalBits)));
	this->_fixedPointValue = result;
}

/* Returns the current raw fixed-point value (_fixedPointValue).*/
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> _fixedPointValue);
}

/* Sets the internal fixed-point value to 'raw'.*/
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

/*
       Converts the internal fixed-point value to a floating-point number.
      - Divides _fixedPointValue by 2^_fractionalBits to restore the
        original floating-point scale.
*/
float	Fixed::toFloat(void) const {
	float	result;

	result = (float)(this->_fixedPointValue) / (1 << Fixed::_fractionalBits);
	return (result);
}

/*
    Converts the internal fixed-point value to an integer by
    discarding the fractional part.
     - Right-shifts _fixedPointValue by _fractionalBits bits,
       dividing by 2^_fractionalBits.
*/
int	Fixed::toInt(void) const {
	int	result;

	result = this->_fixedPointValue >> Fixed::_fractionalBits;
	return (result);
}

/*
   operator<< (overload):
   Enables direct streaming of a Fixed object to an output stream.
 
   Parameters:
     - out: reference to the target std::ostream.
     - fixedValue: const reference to the Fixed object to print.*/
std::ostream&	operator<<(std::ostream &out, const Fixed &fixedValue) {
	out << fixedValue.toFloat();
	return (out);
}
