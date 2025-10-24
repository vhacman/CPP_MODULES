/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 15:26:36 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** Default constructor.
** Initializes a Zombie object without setting its name.
** The _name field remains empty until explicitly assigned.
*/
Zombie::Zombie(){

}

/*
** Parameterized constructor.
** Initializes a Zombie with the given name string.
**
** Parameters:
**   - name: the string used to initialize the private _name field.
*/
Zombie::Zombie(std::string name){
	this->_name = name;
}

/*
** Destructor.
** Called automatically when a Zombie object is destroyed.
** Prints a message showing which zombie has been destroyed.
**
** Example output:
**   Albert: destroyed
*/
Zombie::~Zombie(){
	std::cout << this->_name << ": " << "destroyed" << std::endl;
}

/*
** announce():
** Prints the zombie's name followed by a fixed phrase,
** representing the zombie "announcing" itself.
**
** Example output:
**   Albert: BraiiiiiiinnnzzzZ...
*/
void Zombie::announce(){
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}
