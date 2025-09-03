/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 15:27:08 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** randomChump(): demonstrates the creation of a
** Zombie object on the stack.
**
** Parameters:
**   - name: string used to initialize the Zombie's _name.
**
** Behavior:
** 1) A local Zombie object is created using the parameterized
**    constructor with the given name.
** 2) The zombie immediately calls announce(), printing its
**    name and the standard zombie message.
** 3) Since the Zombie is allocated on the stack, it is
**    automatically destroyed when the function scope ends,
**    and its destructor message is printed without requiring
**    explicit delete.
**
** Example output:
**   StackAllocated zombie: BraiiiiiiinnnzzzZ...
**   StackAllocated zombie: destroyed
*/
void	randomChump(std::string name){
	Zombie	stackZombie(name);
	stackZombie.announce();
}
