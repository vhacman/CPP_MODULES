/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:39:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 16:01:41 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
** zombieHorde():
** Create an array of Zombies dynamically (on the heap).
** Behavior:
** 1) Dynamically allocate an array of N Zombie objects
**    using the default constructor.
** 2) If allocation fails (horde == NULL), return NULL.
** 3) Loop from i = 0 to N - 1:
**      - Build a unique name by concatenating the base name
**        with the index (e.g. "Zombie 1", "Zombie 2").
**      - Call setName() on each Zombie to assign this name.
**      - Immediately call announce() so the zombie introduces itself.
** 4) Return a pointer to the first element of the allocated array.
**
** Notes:
** - The array is created with `new[]`, so it must be released
**   by the caller using `delete[]` to avoid memory leaks.
*/
Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*horde;
	int		i;

	horde = new Zombie[N];
	if (horde == NULL)
		return (NULL);
	for (i = 0; i < N; i++)
	{
		std::stringstream fullName;
		fullName << name << " " << (i + 1);
		horde[i].setName(fullName.str());
		horde[i].announce();
	}
	return (horde);
}
