/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:45:32 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:34:14 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:45:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

/*
**   Represents a human character that always has a weapon.
**   The weapon is passed by reference during construction,
**   which means:
**     - HumanA cannot exist without a weapon.
**     - Any later modification to the Weapon object will
**       automatically affect HumanA, since the reference
**       is permanently bound.
** Private attributes:
**   - _name:      the HumanA’s name.
**   - _weaponREF: a reference to a Weapon object (must be valid
**                 at the time of construction and throughout
**                 the lifetime of the HumanA instance).
** Public methods:
**   - HumanA(std::string name, Weapon &weapon):
**       Constructor. Requires both the name and a reference
**       to an existing Weapon object.
**   - ~HumanA():
**       Destructor. No special cleanup is required.
**   - void attack():
**       Prints a message indicating that the HumanA is attacking
**       using the type of the weapon it references.
*/
class HumanA {
private:
	std::string	_name;
	Weapon		&_weaponREF;
public:
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void attack();
};

#endif
