/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 13:36:13 by vhacman          ###   ########.fr       */
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

	if (this != &other)  // Protegge da auto-assegnazione (a = a)
		_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*   - Left-shifts intValue by _fractionalBits (8 bits).
**   - This scales the integer: intValue * 2^8 = intValue * 256.*/
Fixed::Fixed(int const intValue) {
	std::cout << "Int constructor called" << std::endl;
	_fixedPointValue = intValue << _fractionalBits;
}

/*  - Multiplies floatValue by 2^_fractionalBits (256).
**   - Uses roundf() to round to nearest integer for accuracy.
**   - Casts result to int to store in _fixedPointValue.*/
Fixed::Fixed(float const floatValue) {
	std::cout << "Float constructor called" << std::endl;
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

/*   - Casts _fixedPointValue to float for accurate division.
**   - Divides by 2^_fractionalBits (256) to restore scale.*/
float	Fixed::toFloat(void) const {
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

/* Right-shifts _fixedPointValue by _fractionalBits (8 bits).
**   - This is equivalent to integer division by 256.*/
int	Fixed::toInt(void) const {
	return (_fixedPointValue >> _fractionalBits);
}

//getter
int	Fixed::getRawBits(void) const {
	return (_fixedPointValue);
}

//setter
void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

/*   - Compares raw internal values directly (no conversion needed).
**   - Works because scaling is identical for both operands.*/
bool	Fixed::operator>(Fixed const &other) const
{
		return (_fixedPointValue > other._fixedPointValue);
}

/*
** operator< - Less than
** Returns: true if this object's value < other's value, false otherwise.
** const method: Both parameters are const (not modified).
** Implementation: Compares raw internal values directly.
** Example: if (a < b) where a = 1.5f, b = 2.0f
**   - Compares: 384 < 512 → true
*/
bool	Fixed::operator<(Fixed const &other) const
{
	return (_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	return (_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	return (_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator==(Fixed const &other) const
{
	return (_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	return (_fixedPointValue != other._fixedPointValue);
}

/*   - Adds raw values directly (no scaling correction needed).
**   - Because both operands have same scale (2^8), sum is correct.*/
Fixed	Fixed::operator+(Fixed const &other) const {
	Fixed	result;

	result.setRawBits(_fixedPointValue + other._fixedPointValue);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const {

	Fixed	result;

	result.setRawBits(_fixedPointValue - other._fixedPointValue);
	return (result);
}

/*
**   - Multiplies raw values, then RIGHT-SHIFTS by _fractionalBits.
**   - The right-shift CORRECTS for the scaling.*/
Fixed	Fixed::operator*(Fixed const &other) const {
	Fixed	result;

	result.setRawBits((_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return (result);
}

/***   - LEFT-SHIFTS the dividend by _fractionalBits, then divides.
**   - The left-shift PRESERVES precision for the fixed-point result.*/
Fixed	Fixed::operator/(Fixed const &other) const {
	Fixed	result;

	result.setRawBits((_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return (result);
}

/**   - Increments _fixedPointValue by 1 (smallest representable unit).
**   - Returns reference to *this for chaining: ++a;*/
Fixed	&Fixed::operator++(void) {
	_fixedPointValue++;
	return (*this);
}

/*
** operator++ (postfix) - Post-increment
** Parameters:
**   - int: dummy parameter distinguishing post-increment from pre-increment.
** Returns: Copy of the object's OLD value (by value, not reference).
** Purpose: Increment the value but return the OLD value.*/
Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);

	_fixedPointValue++;
	return (temp);
}

/***   - Decrements _fixedPointValue by 1.
**   - Returns reference to *this for chaining: --a;*/
Fixed	&Fixed::operator--(void) {
	_fixedPointValue--;
	return (*this);
}

/*
** operator-- (postfix) - Post-decrement
** Parameters:
**   - int: dummy parameter distinguishing post-decrement from pre-decrement.
** Returns: Copy of the object's OLD value (by value, not reference).
** Purpose: Decrement the value but return the OLD value.
** Implementation:
**   - Creates temporary copy of current object.
**   - Decrements the actual object.
**   - Returns the temporary (old value).
*/
Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);

	_fixedPointValue--;
	return (temp);
}

/* ========================================================================== */
/* STATIC UTILITY METHODS - MIN AND MAX                                      */
/* ========================================================================== */

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

/*
** operator<< (global function)
** Purpose: Enable direct printing of Fixed objects to output streams.
** Parameters:
**   - out: Reference to output stream (std::cout, std::ofstream, etc.)
**   - fixed: Const reference to Fixed object to print.
** Returns: Reference to output stream (for chaining: std::cout << a << b;)
** Implementation:
**   - Calls toFloat() to convert to human-readable decimal form.
**   - Inserts result into output stream.
**   - Returns stream reference for chaining.
** Why global function?
**   - Left operand is std::ostream (not Fixed), so can't be a member method.
**   - If it were a member, would be: fixed << std::cout (backwards!)
**   - Global function allows: std::cout << fixed (correct order)
*/
std::ostream& operator<<(std::ostream &out, Fixed const &fixed) {
	out << fixed.toFloat();
	return (out);
}

