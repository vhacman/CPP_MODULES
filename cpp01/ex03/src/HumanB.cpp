/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:17 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:55:39 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"

/*
** HumanB constructor.
** Initializes a HumanB object with a given name and
** sets the weapon pointer to NULL.
**   - name: the HumanB's name.
** - Unlike HumanA, HumanB does not require a weapon
**   at construction time.
** - A weapon can be assigned later via setWeapon().
*/
HumanB::HumanB(std::string name) : _name(name), _weaponPTR(NULL) {

}

/*
** HumanB destructor.
** No special cleanup is required since HumanB does not
** own or allocate dynamic memory.
*/
HumanB::~HumanB() {

}

/*
** attack():
** Prints a message describing HumanB's attack.
**
** Behavior:
** - If _weapon is NULL, HumanB attacks with no weapon.
** - Otherwise, HumanB attacks using the weapon's type.
**
** Example outputs:
**   "Jim attacks with no weapon"
**   "Jim attacks with their crude spiked club"
*/
void	HumanB::attack() {
	if(this->_weaponPTR)
		std::cout << this->_name << " attacks with their "
			<< this->_weaponPTR->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with no weapon" << std::endl;
}

/*
** setWeapon():
** Assigns a Weapon to HumanB after construction.
**   - weapon: reference to an existing Weapon object.
**
** - Stores the address of the provided Weapon inside _weaponPTR.
** - Since only a pointer is stored, HumanB does not take
**   ownership of the Weapon. It assumes the Weapon object
**   remains valid for as long as HumanB uses it.
** - Any changes to the Weapon (via setType()) are immediately
**   visible when HumanB calls attack().
*/
void	HumanB::setWeapon(Weapon &weapon) {
	this->_weaponPTR = &weapon;
}
