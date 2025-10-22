/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 09:34:23 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*
** Default constructor. Initializes the internal fixed-point
** value (_fixedPointValue) to 0 and prints a message.
*/
Fixed::Fixed() : _fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*
** Copy constructor. Initializes a new Fixed object by copying
** the _fixedPointValue from another instance. Prints a message.
*/
Fixed::Fixed(const Fixed &other) : _fixedPointValue(other._fixedPointValue) {
	std::cout << "Copy Constructor called" << std::endl;
}

/*
** Destructor. Called automatically when a Fixed object goes out
** of scope or is deleted. Prints a message.
*/
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

/*
** Copy assignment operator. Assigns the value from another Fixed
** instance to the current one, checking for self-assignment.
** - Uses getRawBits() to retrieve the raw value from 'other'.
** - Returns a reference to *this to allow chain assignment.
** - Prints a message each time it is called.*/
Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

/* Returns the current raw fixed-point value (_fixedPointValue).
** Also prints a message when called.*/
int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this-> _fixedPointValue); // this-> oggetto in questione
}

/*
** Sets the internal fixed-point value to 'raw'.*/
void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}
