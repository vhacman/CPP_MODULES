/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:51:58 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 14:17:27 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

/*
**   Represents a fixed-point number with 8 fractional bits.
**   Demonstrates encapsulation and the "canonical form"
** Private attributes:
**   - _fixedPointValue:
**       Stores the raw fixed-point value as an integer.
**       This member is private, so it cannot be accessed
**       directly outside the class. Access must be done
**       via getter/setter methods.
**   - static const int _fractionalBits = 8:
**       Constant number of fractional bits used for the
**       fixed-point representation. Declared static so
**       that all instances of Fixed share the same value.
** - Encapsulation ensures that _fixedPointValue cannot be
**   directly modified from outside the class.
** - _fractionalBits is shared among all instances, since
**   it is a fixed property of the representation and does
**   not change per object.
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
