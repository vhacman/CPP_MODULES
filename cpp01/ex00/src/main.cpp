/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:35 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 15:25:14 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** main():
** Entry point of the program.
**
** Steps performed:
** 1) Dynamically allocate a new Zombie named "Albert"
**    using the Zombie constructor directly with `new`.
**    - A pointer to the Zombie is stored in `zombie`.
**    - If allocation fails (NULL), return 1 as error code.
**
** 2) Call announce() on the heap-allocated zombie,
**    printing its name and the standard zombie message.
**
** 3) Call randomChump("StackAllocated zombie"):
**    - Creates a temporary Zombie object on the stack.
**    - The zombie announces itself immediately.
**    - It is destroyed automatically when the function ends.
**
** 4) Delete the heap-allocated Zombie (`zombie`) to free memory
**    and call its destructor.
**
** 5) Return 0 to indicate successful program termination.
*/
int main(void)
{
	Zombie	*zombie;

	zombie = new Zombie("Albert");
	if (zombie == NULL)
		return (1);
	zombie->announce();
	randomChump("StackAllocated zombie");
	delete (zombie);
	return (0);
}
