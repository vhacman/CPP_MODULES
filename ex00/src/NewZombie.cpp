/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 15:28:44 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** newZombie():creates a Zombie on the heap.
** Behavior:
** 1) Dynamically allocates a Zombie object with the given name
**    using the parameterized constructor.
** 2) Returns a pointer to the newly allocated Zombie.
**
** Notes:
** - Since the zombie is created on the heap, it persists after
**   the function ends. The caller is responsible for freeing the memory later
**   with 'delete' to avoid memory leaks.
*/
Zombie	*newZombie(std::string name){
	Zombie	*heapZombiePtr;

	heapZombiePtr = new Zombie(name);
	return (heapZombiePtr);
}
