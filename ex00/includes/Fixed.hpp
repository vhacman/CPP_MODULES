/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:51:58 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 11:16:11 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

/*
**   Represents a fixed-point number with 8 fractional bits.
** Private attributes:
**   - _fixedPointValue:
**       Stores the raw fixed-point value as an integer.
**   - static const int _fractionalBits = 8:
**       Constant number of fractional bits used for the
**       fixed-point representation. Declared static so
**       that all instances of Fixed share the same value.
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
