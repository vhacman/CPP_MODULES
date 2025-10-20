/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:24:50 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 11:16:30 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

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
