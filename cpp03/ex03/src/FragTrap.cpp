/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:42:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//constructors
FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "\033[1;34mFragTrap default constructor called\033[0m"
				<< std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
	std::cout << "\033[1;34mFragTrap Copy ctor " << _name
				<< " has been called!\033[0m" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;

	std::cout << "\033[1;34mFragTrap ctor for " << _name
				<< " has been called\033[0m" << std::endl;
}

//overloaded operator
FragTrap &FragTrap::operator=(FragTrap const &other) {
	std::cout << "\033[1;34mFragTrap assignation operator called\033[0m" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		std::cout << "\033[1;34mFragTrap " << _name
					<< " has been assigned\033[0m" << std::endl;
	}
	return (*this);
}

//destructor
FragTrap::~FragTrap() {
	std::cout << "\033[1;35mFragTrap destructor for "
				<< _name << " has been called!\033[0m" << std::endl;
}

//highFivesGuys
void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << _name
				<< " requests a positive high five!" << std::endl;
}
