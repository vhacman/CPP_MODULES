/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:50:21 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:22:16 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "\033[0;32mDefault constructor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
		: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "\033[0;32mClapTrap " << _name << " has been called\033[0m"
				<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
			: _name(other._name),
				_hitPoints(other._hitPoints),
				_energyPoints(other._energyPoints),
				_attackDamage(other._attackDamage) {

	std::cout << "\033[0;32mClapTrap " << _name << " has been copied!\033[0m"
				<< std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &other) {
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
		std::cout << "\033[0;32mClapTrap " << _name << " has been assigned\033[0m"
					<< std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "\033[0;31mClapTrap " << _name << " has been destroyed!\033[0m"
				<< std::endl;
}

void ClapTrap::attack(const std::string &target){
	if (_energyPoints <= 0)
	{
		std::cout << "\033[0;31mClapTrap " << _name << " has no energy to attack\033[0m"
					<< std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "\033[0;31mClapTrap " << _name
					<< " died and is not able to attack\033[0m" << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "\033[1;33mClapTrap " << _name << " attacks " << target << ", causing "
			<< _attackDamage << " points of damage\033[0m" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "\033[0;35mClapTrap " << _name << " takes " << amount
				<< " points of damage\033[0m" << std::endl;
	if (amount >= _hitPoints)
	{
		_hitPoints = 0;
		std::cout << "\033[1;31mClapTrap " << _name << " is dead\033[0m" << std::endl;
	}
	else
	{
		_hitPoints -= amount;
		std::cout << "\033[0;36mClapTrap " << _name << " has now "
					<< _hitPoints << " hit Points\033[0m" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints <= 0)
	{
		std::cout << "\033[0;31mClapTrap " << _name
					<< " has no energy to repair itself\033[0m" << std::endl;
		return ;
	}
	if (_hitPoints <= 0)
	{
		std::cout << "\033[0;31mClapTrap " << _name
					<< " died and is not able to repair itself\033[0m" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "\033[1;32mClapTrap " << _name
				<< " is repairing itself with " << amount << " hit points\033[0m" << std::endl;
	std::cout << "\033[0;36mClapTrap " << _name
				<< " has now " << _hitPoints << " hit points\033[0m" << std::endl;
}
