/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:50:40 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:16:03 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//constructors
ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardingGate = false;

	std::cout << "\033[1;32mScavTrap default constructor called\033[0m"
				<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	_guardingGate = other._guardingGate;
	std::cout << "\033[1;32mScavTrap Copy ctor " << _name
				<< " has been called!\033[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardingGate = false;

	std::cout << "\033[1;32mScavTrap ctor for " << _name
				<< " has been called\033[0m" << std::endl;
}


//overloaded operator
ScavTrap &ScavTrap::operator=(ScavTrap const &other) {
	std::cout << "\033[1;32mScavTrap assignation operator called\033[0m" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		_guardingGate = other._guardingGate;
		std::cout << "\033[1;32mScavTrap " << _name
					<< " has been assigned\033[0m" << std::endl;
	}
	return (*this);
}

//destructor
ScavTrap::~ScavTrap() {
	std::cout << "\033[1;31mScavTrap destructor for "
				<< _name << " has been called!\033[0m" << std::endl;
}

//attack
void ScavTrap::attack(const std::string &target) {
	if (_energyPoints <= 0)
	{
		std::cout << "\033[0;31mScavTrap " << _name
					<< " has no energy to attack\033[0m" << std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "\033[0;31mScavTrap " << _name
					<< " died and is not able to attack\033[0m" << std::endl;
		return ;
	}
	std::cout << "\033[1;33mScavTrap " << _name << " fiercely attacks "
				<< target << ", causing " << _attackDamage
				<< " points of damage!\033[0m" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate() {
	if (_guardingGate == false)
	{
		_guardingGate = true;
		std::cout << "\033[1;36mScavTrap " << _name
					<< " is now in Gate keeper mode!\033[0m" << std::endl;
	}
	else
		std::cout << "\033[0;33mScavTrap " << this->_name
					<< " is already guarding the gate.\033[0m" << std::endl;
}
