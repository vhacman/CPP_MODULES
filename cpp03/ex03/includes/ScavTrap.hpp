/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:50:35 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:45:25 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {
	private:

		bool	_guardingGate;

	public:
		//Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		//overload operators
		ScavTrap	&operator=(ScavTrap const &other);
		//destructors
		virtual ~ScavTrap();

		//methods
		void	attack(const std::string &target);
		void	guardGate();
};

#endif
