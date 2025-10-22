/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 11:25:26 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(Fixed const &other) {

	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

//Int constructor
Fixed::Fixed(int const intValue) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

/*Float constructor*/
Fixed::Fixed(float const floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

/*   Conversion method
    - Casts _fixedPointValue to float for accurate division.
    - Divides by 2^_fractionalBits (256) to restore scale.
*/
float	Fixed::toFloat(void) const {
	float	result;

	result = (float)_fixedPointValue / (1 << _fractionalBits);
	return (result);
}

/* Conversion Method
     Right-shifts _fixedPointValue by _fractionalBits (8 bits).
     - This is equivalent to integer division by 256.
*/
int	Fixed::toInt(void) const {
	int	result;

	result = _fixedPointValue >> _fractionalBits;
	return (result);
}

//getter
int	Fixed::getRawBits(void) const {
	return (_fixedPointValue);
}

//setter
void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

Fixed& Fixed::min(Fixed &a, Fixed &b) {
	if (a < b)
		return a;
	return (b);
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b) {
	if (a < b)
		return a;
	return (b);
}

Fixed& Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return a;
	return (b);
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return a;
	return (b);
}

std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}

