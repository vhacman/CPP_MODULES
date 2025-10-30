/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:50:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:50:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//constructors
DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), FragTrap(), ScavTrap() {
	this->_name = "default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "\033[1;36mDiamondTrap default constructor called\033[0m"
				<< std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;

	std::cout << "\033[1;36mDiamondTrap ctor for " << this->_name
				<< " has been called\033[0m" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other) {
	this->_name = other._name;
	std::cout << "\033[1;36mDiamondTrap Copy ctor " << this->_name
				<< " has been called!\033[0m" << std::endl;
}

//overloaded operator
DiamondTrap &DiamondTrap::operator=(DiamondTrap const &other) {
	std::cout << "\033[1;36mDiamondTrap assignation operator called\033[0m" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->_name = other._name;
		std::cout << "\033[1;36mDiamondTrap " << this->_name
					<< " has been assigned\033[0m" << std::endl;
	}
	return (*this);
}

//destructor
DiamondTrap::~DiamondTrap() {
	std::cout << "\033[1;35mDiamondTrap destructor for "
				<< this->_name << " has been called!\033[0m" << std::endl;
}

//whoAmI
void DiamondTrap::whoAmI() {
	std::cout << "\033[1;33m=== Who Am I? ===\033[0m" << std::endl;
	std::cout << "My DiamondTrap name is: " << this->_name << std::endl;
	std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
	std::cout << "\033[1;33m================\033[0m" << std::endl;
}
