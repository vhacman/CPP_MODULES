/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OverloadOperators.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 11:22:28 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 12:14:09 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

bool	Fixed::operator>(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue > otherValue;
	return (result);
}

bool	Fixed::operator<(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue < otherValue;
	return (result);
}

bool	Fixed::operator>=(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue >= otherValue;
	return (result);
}

bool	Fixed::operator<=(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue <= otherValue;
	return (result);
}

bool	Fixed::operator==(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue == otherValue;
	return (result);
}

bool	Fixed::operator!=(Fixed const &other) const
{
	int		thisValue;
	int		otherValue;
	bool	result;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	result = thisValue != otherValue;
	return (result);
}

Fixed	Fixed::operator+(Fixed const &other) const {
	Fixed	result;
	int		thisValue;
	int		otherValue;
	int		sum;
	
	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	sum = thisValue + otherValue;
	result.setRawBits(sum);
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result;
	int		thisValue;
	int		otherValue;
	int		difference;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	difference = thisValue - otherValue;
	result.setRawBits(difference);
	return (result);
}

Fixed	Fixed::operator*(Fixed const &other) const
{
	Fixed	result;
	int		thisValue;
	int		otherValue;
	int		product;
	int		adjustedProduct;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	product = thisValue * otherValue;
	adjustedProduct = product >> _fractionalBits;
	result.setRawBits(adjustedProduct);
	return (result);
}

Fixed	Fixed::operator/(Fixed const &other) const
{
	Fixed	result;
	int		thisValue;
	int		otherValue;
	int		scaledDividend;
	int		quotient;

	thisValue = _fixedPointValue;
	otherValue = other._fixedPointValue;
	scaledDividend = thisValue << _fractionalBits;
	quotient = scaledDividend / otherValue;
	result.setRawBits(quotient);
	return (result);
}

Fixed	&Fixed::operator++(void)
{
	int		currentValue;

	currentValue = _fixedPointValue;
	currentValue++;
	_fixedPointValue = currentValue;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	int		currentValue;

	currentValue = _fixedPointValue;
	currentValue++;
	_fixedPointValue = currentValue;
	return (temp);
}

Fixed	&Fixed::operator--(void)
{
	int		currentValue;

	currentValue = _fixedPointValue;
	currentValue--;
	_fixedPointValue = currentValue;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	int		currentValue;

	currentValue = _fixedPointValue;
	currentValue--;
	_fixedPointValue = currentValue;
	return (temp);
}
