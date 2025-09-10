/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/10 14:10:13 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = other;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called " << std::endl;
	return (this-> _fixedPointValue);
}

void	Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}
