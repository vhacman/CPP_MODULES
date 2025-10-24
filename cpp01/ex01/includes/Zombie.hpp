/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:42:57 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:47:56 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

/*
**   Represents a zombie character with a name. Zombies can
**   introduce themselves and can be created individually
**   or as part of a horde.
** Private attributes:
**   - _name: string storing the zombie’s name.
** Public methods:
**   - Zombie():
**       Default constructor. Creates a zombie with no name.
**   - Zombie(std::string name):
**       Parameterized constructor. Creates a zombie and assigns
**       the given name to it.
**   - ~Zombie():
**       Destructor. Prints a message indicating that the zombie
**       has been destroyed.
**   - void announce():
**       Prints a message where the zombie introduces itself
**       (e.g., "<name>: BraiiiiiiinnnzzzZ...").
**   - void setName(std::string name):
**       Assigns or updates the zombie’s name after construction.
**       Useful when zombies are created in an array (horde)
**       with the default constructor.
*/
class Zombie {
private:
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
};

/*
** Related function:
**   - Zombie *zombieHorde(int N, std::string name):
**       Creates a dynamic array of N zombies on the heap.
**       Each zombie is given a unique name based on the
**       provided base name (e.g., "Zombie 1", "Zombie 2").
**       Returns a pointer to the first zombie in the array.
**       The caller must free the memory with `delete[]`.
*/
Zombie *zombieHorde(int N, std::string name);

#endif
