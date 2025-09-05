/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:14 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:47:44 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

/*
** HumanA constructor.
** Initializes a HumanA object with a given name and a reference
** to a Weapon object.
**   - name: the HumanA's name.
**   - weapon: a reference to an existing Weapon object.
**
** - Because _weaponREF is a reference, HumanA must always
**   be constructed with a valid Weapon.
**
** - Any later modifications to the Weapon object are automatically
**   visible to this HumanA, since references cannot be reseated.
*/
HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weaponREF(weapon) {
}

/*
** HumanA destructor.
** In this case, it does nothing special since HumanA does not
** manage dynamic memory.
*/
HumanA::~HumanA() {

}

/*
** Prints a message describing the HumanA attacking with their weapon.
** - Accesses the Weapon object through the reference _weaponREF.
** - Calls getType() on the Weapon to display its current type.
**    --> "Bob attacks with their: crude spiked club" <--
*/
void HumanA::attack() {
	std::cout << this->_name << " attacks with their: " << this->_weaponREF.getType() << std::endl;
}
