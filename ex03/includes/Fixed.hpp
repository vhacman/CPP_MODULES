/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:03:08 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/17 16:53:37 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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

	/* ==================== */
	/* COMPARISON OPERATORS */
	/* ==================== */
		bool	operator>(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;

	/* ==================== */
	/* ARITHMETIC OPERATORS */
	/* ==================== */
		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;

	/* ============================== */
	/* INCREMENT/DECREMENT OPERATORS */
	/* ============================= */
		Fixed	&operator++(void);		// Pre-increment
		Fixed	operator++(int);		// Post-increment
		Fixed	&operator--(void);		// Pre-decrement
		Fixed	operator--(int);		// Post-decrement

	/* ========================= */
	/* STATIC MIN/MAX FUNCTIONS */
	/* ========================= */
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream& out, Fixed const &fixed);

#endif
