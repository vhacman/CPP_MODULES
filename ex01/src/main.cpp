/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:39:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 16:04:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** 1) Declare a pointer to a Zombie, named `horde`.
** 2) Call zombieHorde(10, "Zombie"):
**      - Dynamically allocates an array of 10 Zombies on the heap.
**      - Each zombie is named "Zombie 1", "Zombie 2", ... "Zombie 10".
**      - Each zombie announces itself right after being named.
**      - The function returns a pointer to the first element of the array.
** 3) If allocation fails (horde == NULL), return 0 immediately.
** 4) Free the allocated array with `delete[]` to avoid memory leaks.
** 5) Return 0 to indicate successful program termination.
*/
int main(void)
{
	Zombie *horde;

	horde = zombieHorde(10, "Zombie");
	if (horde == NULL)
		return (0);
	delete[](horde);
	return 0;
}
