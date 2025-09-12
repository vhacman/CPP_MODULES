/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:24:50 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/12 14:51:13 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

/*
**   Represents a fixed-point number with 8 fractional bits.
**   Supports construction from integers or floats and
**   conversion back to both, while maintaining encapsulation.
**
** Private attributes:
**		- _fixedPointValue:
**			Integer storing the raw fixed-point representation.
**
**		- static const int _fractionalBits = 8:
**			Number of fractional bits used for the fixed-point
**			representation. Shared across all instances.
*/
class Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
		Fixed();
		Fixed(Fixed const &other);
		Fixed	&operator=(Fixed const &other);
		~Fixed();

		Fixed(int const intValue);
		Fixed(float const floatValue);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
};

/* Overloads the stream insertion operator so a Fixed
** can be printed directly. Outputs the value as a float
** for human-readable display.
*/
std::ostream	&operator<<(std::ostream& out, Fixed const &fixed);
void			testFloatConversions(void);
void			testPrecision(void);
void			testAssignmentOperator(void);
void			testEdgeCases(void);

#endif
