/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 11:20:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
}

Fixed::Fixed(Fixed const &other) : _fixedPointValue(other._fixedPointValue) {
}

Fixed	&Fixed::operator=(Fixed const &other) {
	if (this != &other)
		_fixedPointValue = other._fixedPointValue;
	return (*this);
}

Fixed::~Fixed() {
}

Fixed::Fixed(int const intValue) {
	_fixedPointValue = intValue << _fractionalBits;
}

Fixed::Fixed(float const floatValue) {
	_fixedPointValue = roundf(floatValue * (1 << _fractionalBits));
}

float	Fixed::toFloat(void) const {
	return ((float)_fixedPointValue / (1 << _fractionalBits));
}

int	Fixed::toInt(void) const {
	return (_fixedPointValue >> _fractionalBits);
}

int	Fixed::getRawBits(void) const {
	return (_fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	_fixedPointValue = raw;
}

bool	Fixed::operator>(Fixed const &other) const {
	return (_fixedPointValue > other._fixedPointValue);
}

bool	Fixed::operator<(Fixed const &other) const {
	return (_fixedPointValue < other._fixedPointValue);
}

bool	Fixed::operator>=(Fixed const &other) const {
	return (_fixedPointValue >= other._fixedPointValue);
}

bool	Fixed::operator<=(Fixed const &other) const {
	return (_fixedPointValue <= other._fixedPointValue);
}

bool	Fixed::operator==(Fixed const &other) const {
	return (_fixedPointValue == other._fixedPointValue);
}

bool	Fixed::operator!=(Fixed const &other) const {
	return (_fixedPointValue != other._fixedPointValue);
}

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

Fixed	Fixed::operator*(Fixed const &other) const {
	Fixed	result;

	result.setRawBits((_fixedPointValue * other._fixedPointValue) >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &other) const {
	Fixed	result;

	result.setRawBits((_fixedPointValue << _fractionalBits) / other._fixedPointValue);
	return (result);
}

Fixed	&Fixed::operator++(void) {
	_fixedPointValue++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);

	_fixedPointValue++;
	return (temp);
}

Fixed	&Fixed::operator--(void) {
	_fixedPointValue--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);

	_fixedPointValue--;
	return (temp);
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
