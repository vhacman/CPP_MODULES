/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:51:58 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 10:41:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class	Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		//OCF
		Fixed();
		Fixed(const Fixed &other);
		Fixed&	operator=(const Fixed &other);
		~Fixed();
		//getter && setter
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
