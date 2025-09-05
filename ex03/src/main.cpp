/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:34:19 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/05 14:54:09 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/*
** Demonstrates the difference in behavior between HumanA and HumanB
** when using a Weapon object.
**
** Key concepts:
** - HumanA is constructed with a reference to a Weapon. This means
**   it must always have a weapon, and the reference remains bound
**   to the same Weapon object.
** - HumanB can be constructed without a weapon and allows a weapon
**   to be set later via setWeapon(). This is implemented with a
**   pointer internally.
** This shows how references and pointers differ but both allow
** the weapon updates to propagate to the Human classes.
*/
int	main()
{
	{
		Weapon	club = Weapon("crude spiked club");

		HumanA	bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");

		HumanB	jim ("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	//caso per dimostrare NO WEAPON
	{
		HumanB	alice("Alice");
		alice.attack();
	}
	return (0);
}
