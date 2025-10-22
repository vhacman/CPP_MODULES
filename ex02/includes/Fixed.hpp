/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:03:08 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 11:05:58 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class	Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
	//OCF
		Fixed();
		Fixed(Fixed const& other);
		Fixed	&operator=(Fixed const& other);
		~Fixed();
	//Parameterized constructors
		Fixed(int const intValue);
		Fixed(float const floatValue);
	//Accessors
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	//Convertion Methods
		float	toFloat(void) const;
		int		toInt(void) const;

	//Comparison operators
		bool	operator>(Fixed const &other) const;
		bool	operator<(Fixed const &other) const;
		bool	operator>=(Fixed const &other) const;
		bool	operator<=(Fixed const &other) const;
		bool	operator==(Fixed const &other) const;
		bool	operator!=(Fixed const &other) const;
	//Arithmetic operators, return new Fixed object
		Fixed	operator+(Fixed const &other) const;
		Fixed	operator-(Fixed const &other) const;
		Fixed	operator*(Fixed const &other) const;
		Fixed	operator/(Fixed const &other) const;
	//Increment and decrement operators
		Fixed&	operator++(void); //++a
		Fixed	operator++(int); //a++
		Fixed&	operator--(void); 
		Fixed	operator--(int);
	//Static member functions for min/max comparison
		static Fixed&			min(Fixed &a, Fixed &b);
		static Fixed const&		min(Fixed const &a, Fixed const &b);
		static Fixed&			max(Fixed &a, Fixed &b);
		static Fixed const&		max(Fixed const &a, Fixed const &b);
};

//Stream insertion operator overload. allow printing Fixed objects with std::cout
std::ostream	&operator<<(std::ostream& out, Fixed const &fixed);

#endif
