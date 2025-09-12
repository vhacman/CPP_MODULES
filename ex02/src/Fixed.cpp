/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 15:05:43 by vhacman          ###   ########.fr       */
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

Fixed::Fixed(int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = intValue << this->_fractionalBits;
}

Fixed::Fixed(float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = (int)(::roundf(floatValue * (1 << this->_fractionalBits)));
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> _fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float	Fixed::toFloat(void) const {
	return ((float)(this->_fixedPointValue) / (1 << Fixed::_fractionalBits));
}

int	Fixed::toInt(void) const {
	return (this->_fixedPointValue >> Fixed::_fractionalBits);
}

std::ostream&	operator<<(std::ostream &out, const Fixed &fixedValue) {
	out << fixedValue.toFloat();
	return (out);
}
