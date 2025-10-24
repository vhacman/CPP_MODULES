/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 14:24:50 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 10:52:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class	Fixed {

	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;

	public:
	//OCF
		Fixed();
		Fixed(Fixed const &other);
		Fixed	&operator=(Fixed const &other);
		~Fixed();
	//Parameterized Constructors
		Fixed(int const intValue); //from int
		Fixed(float const floatValue); //from float

	//Getter and setters 
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
	//converters
		float	toFloat(void) const;
		int		toInt(void) const;
};

//Overload of the insertion operator for output stream
std::ostream	&operator<<(std::ostream& out, Fixed const &fixed);


//Utility test functions
void			testFloatConversions(void);
void			testPrecision(void);
void			testAssignmentOperator(void);
void			testEdgeCases(void);

#endif
