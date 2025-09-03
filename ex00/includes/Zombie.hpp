/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:37:38 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 15:24:11 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# include <string>

/*
** The Zombie class models a simple object with a name
** and the ability to "announce" itself to the console.
**
** Responsibilities:
** - Store a private name string.
** - Provide constructors to create a zombie with or without
**   an explicit name.
** - Provide a destructor to log when a zombie is destroyed.
** - Provide the announce() method to print the zombie's
**   presence in a fixed format.
*/
class Zombie {
	private:
		std::string	_name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void	announce(void);
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

#endif
