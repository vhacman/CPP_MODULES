/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:50:25 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 19:02:56 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:

		std::string			_name;
		unsigned int		_hitPoints;
		unsigned int		_energyPoints;
		unsigned int		_attackDamage;


	public:
		//constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		//overload operator
		ClapTrap	&operator=(ClapTrap const &other);
		//deconstructors
		virtual	~ClapTrap();

		//methods
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
