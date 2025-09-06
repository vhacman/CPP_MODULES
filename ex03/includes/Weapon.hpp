/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:46:17 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

/*
**   Represents a weapon that can be used by a HumanA or HumanB.
**   Each Weapon has a type (e.g., "crude spiked club") that
**   determines the message shown during an attack.
** Private attributes:
**   - _type: string representing the name/type of the weapon.
** Public methods:
**   - Weapon():
**       Default constructor. Initializes the weapon with a
**       default type ("No Weapon").
**   - Weapon(std::string type):
**       Parameterized constructor. Initializes the weapon with
**       the given type string.
**   - ~Weapon():
**       Destructor. No special cleanup is required.
**   - const std::string &getType() const:
**       Returns a constant reference to the current weapon type,
**       avoiding unnecessary string copies and ensuring read-only access.
**   - void setType(std::string type):
**       Updates the weapon’s type with the given string.
**       Any HumanA or HumanB referencing or pointing to this
**       Weapon will immediately reflect the new type in their
**       attack() method.
*/
class Weapon {
private:
	std::string	_type;

public:
	Weapon();
	Weapon(std::string type);
	~Weapon();
	const std::string	&getType(void) const ;
	void				setType(std::string type);
};

#endif
