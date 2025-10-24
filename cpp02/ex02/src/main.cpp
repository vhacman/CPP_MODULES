/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:05:52 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 12:37:39 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void	printSeparator(std::string const &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

static void	testConstructors(void)
{
	printSeparator("CONSTRUCTORS");
	
	Fixed	a;
	Fixed	b(42);
	Fixed	c(42.42f);
	Fixed	d(b);
	
	std::cout << "a (default): " << a << std::endl;
	std::cout << "b (int 42): " << b << std::endl;
	std::cout << "c (float 42.42f): " << c << std::endl;
	std::cout << "d (copy of b): " << d << std::endl;
}

static void	testComparison(void)
{
	printSeparator("COMPARISON OPERATORS");
	
	Fixed	a(10);
	Fixed	b(20);
	Fixed	c(10);
	
	std::cout << "a = " << a << "\n" <<  "b = " << b << "\n" << "c = " << c << "\n" << std::endl;
	std::cout << "a > b: " << (a > b ? "true" : "false") << std::endl;
	std::cout << "a < b: " << (a < b ? "true" : "false") << std::endl;
	std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
	std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
	std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
	std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl;
}

static void	testArithmetic(void)
{
	printSeparator("ARITHMETIC OPERATORS");
	
	Fixed	a(10.5f);
	Fixed	b(2.5f);
	
	std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
	Fixed	result1 = a + b;
	std::cout << "a + b = " << result1 << std::endl;
	Fixed	result2 = a - b;
	std::cout << "a - b = " << result2 << std::endl;
	Fixed	result3 = a * b;
	std::cout << "a * b = " << result3 << std::endl;
	Fixed	result4 = a / b;
	std::cout << "a / b = " << result4 << std::endl;
}

static void	testIncrement(void)
{
	printSeparator("INCREMENT/DECREMENT OPERATORS");
	
	Fixed	a(5);
	
	std::cout << "Initial value a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a after pre-increment (++a): " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a after post-increment (a++): " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a after pre-decrement (--a): " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a after post-decrement (a--): " << a << std::endl;
}

static void	testMinMax(void)
{
	printSeparator("MIN/MAX STATIC FUNCTIONS TEST");
	
	Fixed	a(42.42f);
	Fixed	b(10.5f);
	Fixed	const c(100.25f);
	Fixed	const d(50.75f);
	
	std::cout << "a = " << a << "\n" << "b = " << b << std::endl;
	std::cout << "Fixed::min(a, b) = " << Fixed::min(a, b) << std::endl;
	std::cout << "Fixed::max(a, b) = " << Fixed::max(a, b) << std::endl;
	
	std::cout << "\nc = " << c << "\n" << "d = " << d << std::endl;
	std::cout << "Fixed::min(c, d) = " << Fixed::min(c, d) << std::endl;
	std::cout << "Fixed::max(c, d) = " << Fixed::max(c, d) << std::endl;
}

static void	testConversions(void)
{
	printSeparator("CONVERSION METHODS TEST");
	
	Fixed	a(42);
	Fixed	b(42.42f);
	
	std::cout << "a constructed from int 42:" << std::endl;
	std::cout << "  toInt(): " << a.toInt() << std::endl;
	std::cout << "  toFloat(): " << a.toFloat() << std::endl;
	
	std::cout << "b constructed from float 42.42f:" << std::endl;
	std::cout << "  toInt(): " << b.toInt() << std::endl;
	std::cout << "  toFloat(): " << b.toFloat() << std::endl;
}

static void	testSubjectExample(void)
{
	printSeparator("SUBJECT EXAMPLE TEST");
	
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
}

int	main(void)
{
	testConstructors();
	testComparison();
	testArithmetic();
	testIncrement();
	testMinMax();
	testConversions();
	testSubjectExample();
	return (0);
}