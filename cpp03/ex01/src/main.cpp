/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:50:45 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:21:03 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
	std::cout << "\033[1;36m=== Construction/Destruction Chaining ===\033[0m"
			<< std::endl;


	std::cout << "\n\033[1;34m--- Creating ScavTrap 'Guardian' ---\033[0m"
				<< std::endl;
	ScavTrap	scav1("Guardian");

	std::cout << "\n\033[1;34m--- Creating ScavTrap 'Defender' ---\033[0m"
				<< std::endl;
	ScavTrap	scav2("Defender");

	std::cout << "\n\033[1;36m=== Testing ScavTrap Specific Attack ===\033[0m"
				<< std::endl;
	scav1.attack("enemy");
	scav2.attack("intruder");

	std::cout << "\n\033[1;36m=== Testing Gate Keeper Mode ===\033[0m"
				<< std::endl;
	scav1.guardGate();
	scav2.guardGate();

	std::cout << "\n\033[1;36m=== Testing Inherited Methods ===\033[0m"
				<< std::endl;
	scav1.takeDamage(30);
	scav1.beRepaired(20);
	scav1.takeDamage(50);

	std::cout << "\n\033[1;36m=== Testing Copy Constructor ===\033[0m"
				<< std::endl;
	{
		std::cout << "\033[1;35mCreating copy of Guardian...\033[0m" << std::endl;
		ScavTrap	scav3(scav1);
		scav3.attack("test target");
		scav3.guardGate();
		std::cout << "\033[1;35mExiting scope (scav3 will be destroyed)...\033[0m"
					<< std::endl;
	}

	std::cout << "\n\033[1;36m=== Testing Assignment Operator ===\033[0m"
				<< std::endl;
	ScavTrap	scav4("Temporary");
	scav4 = scav2;
	scav4.attack("assigned target");

	std::cout << "\n\033[1;36m=== Testing ClapTrap (for comparison) ===\033[0m"
				<< std::endl;
	ClapTrap	clap("BasicBot");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << "\n\033[1;36m=== Testing Energy Depletion ===\033[0m"
				<< std::endl;
	ScavTrap	energyTest("EnergyTest");
	for (int i = 0; i < 52; i++) {
		energyTest.attack("dummy");
	}

	std::cout << "\n\033[1;36m=== Testing Death Scenario ===\033[0m"
				<< std::endl;
	ScavTrap	deathTest("Mortal");
	deathTest.takeDamage(100);
	deathTest.attack("ghost");
	deathTest.beRepaired(10);
	deathTest.guardGate();

	std::cout << "\n\033[1;36m=== Program Ending - Destructors Will Be Called ===\033[0m"
				<< std::endl;
	return (0);
}
