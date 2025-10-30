/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:42:19 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 14:42:26 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:41:41 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 14:41:46 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int	main(void) {
	std::cout << "\n=== TEST 1: Creation and basic attack ===" << std::endl;
	ClapTrap	robot1("Robot1");
	robot1.attack("Enemy1");
	robot1.attack("Enemy2");
	std::cout << std::endl;

	std::cout << "\n=== TEST 2: Taking damage ===" << std::endl;
	robot1.takeDamage(3);
	robot1.takeDamage(5);
	std::cout << std::endl;

	std::cout << "\n=== TEST 3: Being repaired ===" << std::endl;
	robot1.beRepaired(4);
	robot1.beRepaired(2);
	std::cout << std::endl;

	std::cout << "\n=== TEST 4: Energy depletion ===" << std::endl;
	for (int i = 0; i < 8; i++)
		robot1.attack("Target");
	std::cout << std::endl;

	std::cout << "\n=== TEST 5: Dead robot cannot act ===" << std::endl;
	ClapTrap	robot2("Robot2");
	robot2.takeDamage(15);
	robot2.attack("Someone");
	robot2.beRepaired(5);
	std::cout << std::endl;

	std::cout << "\n=== TEST 6: Copy constructor ===" << std::endl;
	ClapTrap	robot3("Robot3");
	ClapTrap	robot4(robot3);
	robot4.attack("TestTarget");
	std::cout << std::endl;

	std::cout << "\n=== TEST 7: Assignment operator ===" << std::endl;
	ClapTrap	robot5("Robot5");
	robot5.takeDamage(3);
	ClapTrap	robot6("Robot6");
	robot6 = robot5;
	std::cout << std::endl;

	std::cout << "\n=== End of tests - Automatic destruction ===" << std::endl;
	return (0);
}

