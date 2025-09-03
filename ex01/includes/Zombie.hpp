/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:42:57 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 16:03:29 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie{
private:
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void	announce(void);
	void	setName(std::string name);
};

Zombie *zombieHorde(int N, std::string name);

#endif
