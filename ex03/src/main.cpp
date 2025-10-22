/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 13:14:18 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	testStandardTriangle();
	std::cout << "\n";
	testAlternativeTriangle();
	std::cout << "\n";
	printSeparator();
	std::cout << "    TEST COMPLETED" << std::endl;
	printSeparator();
	std::cout << std::endl;
	return (0);
}
