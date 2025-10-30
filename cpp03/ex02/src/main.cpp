/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:27:41 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/20 15:40:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	testClapTrap(void)
{
	std::cout << "\n=== Testing ClapTrap ===" << std::endl;
	ClapTrap	clap("Clappy");
	clap.attack("target");
	clap.takeDamage(5);
	clap.beRepaired(3);
	std::cout << std::endl;
}

void	testScavTrap(void)
{
	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("enemy");
	scav.takeDamage(30);
	scav.beRepaired(20);
	scav.guardGate();
	scav.guardGate(); // Test already guarding
	std::cout << std::endl;
}

void	testFragTrap(void)
{
	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap	frag("Fraggy");
	frag.attack("opponent");
	frag.takeDamage(40);
	frag.beRepaired(25);
	frag.highFivesGuys();
	std::cout << std::endl;
}

void	testConstructionDestruction(void)
{
	std::cout << "\n=== Testing Construction/Destruction Chaining ===" << std::endl;
	std::cout << "\n--- Creating FragTrap ---" << std::endl;
	FragTrap	frag("Destroyer");
	std::cout << "\n--- Destroying FragTrap (destructor chain test) ---" << std::endl;
}

void	testCopyConstructor(void)
{
	std::cout << "\n=== Testing Copy Constructor ===" << std::endl;
	FragTrap	frag1("Original");
	FragTrap	frag2(frag1);
	std::cout << std::endl;
}

void	testAssignmentOperator(void)
{
	std::cout << "\n=== Testing Assignment Operator ===" << std::endl;
	FragTrap	frag1("First");
	FragTrap frag2("Second");
	frag2 = frag1;
	std::cout << std::endl;
}

void	testMultipleFragTraps(void)
{
	std::cout << "\n=== Testing Multiple FragTraps ===" << std::endl;
	FragTrap frag1("Alpha");
	FragTrap frag2("Beta");
	FragTrap frag3("Gamma");

	frag1.highFivesGuys();
	frag2.highFivesGuys();
	frag3.highFivesGuys();

	frag1.attack("Beta");
	frag2.takeDamage(30);
	frag2.beRepaired(15);

	std::cout << std::endl;
}

void	testPolymorphism(void)
{
	std::cout << "\n=== Testing Polymorphism ===" << std::endl;
	ClapTrap	*clap = new ClapTrap("PolyClap");
	ClapTrap	*scav = new ScavTrap("PolyScav");
	ClapTrap	*frag = new FragTrap("PolyFrag");

	clap->attack("target1");
	scav->attack("target2");
	frag->attack("target3");

	delete (clap);
	delete (scav);
	delete (frag);
	std::cout << std::endl;
}

int	main(void)
{
	testClapTrap();
	testScavTrap();
	testFragTrap();
	testConstructionDestruction();
	testCopyConstructor();
	testAssignmentOperator();
	testMultipleFragTraps();
	testPolymorphism();

	std::cout << "\n=== All tests completed ===" << std::endl;
	return (0);
}
