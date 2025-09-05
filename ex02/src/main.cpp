/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:27:48 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 13:18:26 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

/*
** Demonstrates the difference between a pointer and a reference
** in C++
**
** This shows:
** - A pointer stores the address of the variable and must be dereferenced
**   with '*' to access the value.
** - A reference is an alias to the original variable and can be used
**   as if it were the variable itself.
**
*/
int	main(){
	std::string	String;
	std::string	*stringPTR;

	String = "HI THIS IS BRAIN";
	stringPTR = &String;
	std::string	&stringREF = String;

	std::cout << "The string address is: " << &String << std::endl;
	std::cout << "The address in stringPTR is: " << stringPTR << std::endl;
	std::cout << "The address in stringREF is: " << &stringREF << std::endl;
	std::cout << "The string value is: " << String << std::endl;
	std::cout << "Value *stringPTR: " << *stringPTR  << std::endl;
	std::cout << "Value stringREF: " << stringREF   << std::endl;
	return (0);
}
