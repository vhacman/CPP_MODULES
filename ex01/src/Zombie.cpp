/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:39:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 16:02:50 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** Default constructor.
*/
Zombie::Zombie(){
}

/*
** Parameterized constructor.
** Parameters:
**   - name: string used to initialize the _name field.
*/
Zombie::Zombie(std::string name){
	this->_name = name;
}

/*
** Destructor.
** Called automatically when the Zombie object is destroyed.
** Prints a message showing which zombie is being destroyed.
**
** Example output:
**   "Albert: destroyed"
*/
Zombie::~Zombie(){
	std::cout << this->_name << ": " << "destroyed" << std::endl;
}

/*
** announce():
** Prints the zombie's name followed by a fixed phrase.
** This simulates the zombie announcing itself.
*/
void Zombie::announce(){
	std::cout << this->_name << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

/*
** setName():
** Setter method used to assign or update the zombie's name
** after it has already been constructed.
**
** This method is necessary for arrays of Zombies created
** with the default constructor (e.g. in zombieHorde), since
** each element is built without a name and needs to be
** renamed individually.
*/
void	Zombie::setName(std::string name){
	this->_name = name;
}
