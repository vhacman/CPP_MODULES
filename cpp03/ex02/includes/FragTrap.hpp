/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/22 19:03:10 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	public:
		//Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		//overload operators
		FragTrap	&operator=(FragTrap const &other);
		//destructors
		virtual	~FragTrap();

		//methods
		void	highFivesGuys(void);
};

#endif
