/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:21 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:55:20 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/*
** Default constructor.
** Initializes a Weapon with the default type "No Weapon".
** This ensures that even without explicit initialization,
** a Weapon object always has a valid type string.
*/
Weapon::Weapon(void) {
	Weapon::_type = "No Weapon";
}

/*
** Parameterized constructor.
** Creates a Weapon with a specific type.
**
** Parameters:
**   - type: string describing the weapon (e.g., "crude spiked club").
*/
Weapon::Weapon(std::string type) {
	Weapon::_type = type;
}

/*
** Destructor.
** No dynamic memory is used, so no cleanup is required.
** Provided for completeness and good practice.
*/
Weapon::~Weapon(void){

}

/*
** getType(): Returns the current type of the Weapon.
**   return - A const reference to the string _type.
** - Returning by const reference avoids unnecessary copies.
** - The method itself is const because it does not modify
**   the Weapon object.
*/
const std::string	&Weapon::getType(void) const {
	return (Weapon::_type);
}

/*
** setType(): Updates the type of the Weapon.
**   - type: new string value for the weapon type.
** - Modifies the private member _type.
** - Since Humans store a reference or pointer to the Weapon,
**   any Human using this Weapon will immediately "see"
**   the updated type in their attack() output.
*/
void		Weapon::setType(std::string type){
	Weapon::_type = type;
}
