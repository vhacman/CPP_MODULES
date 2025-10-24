/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:09 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:46:25 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "Weapon.hpp"

/*
**   Represents a human character that may or may not have a weapon.
**   Unlike HumanA, this class stores a pointer to a Weapon, which
**   allows the weapon to be assigned after the object is created.
** Private attributes:
**   - _name:      the HumanB’s name.
**   - _weaponPTR: a pointer to a Weapon object. It can be null,
**                 meaning the HumanB currently has no weapon.
** Public methods:
**   - HumanB(std::string name):
**       Constructor. Initializes the HumanB with a name and sets
**       _weaponPTR to nullptr (no weapon assigned yet).
**   - ~HumanB():
**       Destructor. No special cleanup is required because the class
**       does not own the Weapon object (it only stores a pointer).
**   - void attack():
**       Prints a message describing the HumanB’s attack.
**       - If _weaponPTR is null, prints that the human attacks with
**         no weapon.
**       - Otherwise, prints the weapon type using _weaponPTR->getType()
**   - void setWeapon(Weapon &weapon):
**       Assigns a weapon to HumanB by storing its address in _weaponPTR.
**       - Since it stores only a pointer, the Weapon object must remain
**         valid for the lifetime of the HumanB that uses it.
*/
class HumanB {
private:
	std::string	_name;
	Weapon		*_weaponPTR;

public:
	HumanB(std::string name);
	~HumanB();
	void	attack();
	void	setWeapon(Weapon &weapon);
};

#endif
