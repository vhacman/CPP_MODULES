/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:49:50 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:41:18 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
** Constructor & Destructor.
*/
Harl::Harl() {}
Harl::~Harl() {}

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-"
					"triple-pickle-special-ketchup burger. I really do!"
					<< std::endl << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. "
					"You didn’t put enough bacon in my burger! If you did, "
					"I wouldn’t be asking for more!"
					<< std::endl << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
					"I’ve been coming for years, whereas you started working "
					"here just last month."
					<< std::endl << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable! I want to speak to the manager now."
				<< std::endl << std::endl;
}

/*
** Dynamically selects and executes one of the Harl class’s
** logging methods (debug, info, warning, error) based on the
** given string level.
**
** Implementation details:
** - levels[]: array of strings containing valid log levels.
** - PTR[]: array of pointers to member functions corresponding
**   to each level.
** - Iterate through levels[], compare with the given string.
** - If match is found, call the associated method via the
**   function pointer and break the loop.
** - If no match is found, print "UNKNOWN".
*/
void	Harl::complain(std::string level){
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;
	void		(Harl::*PTR[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	i = 0;
	while (i < 4)
	{
		if (levels[i] == level)
		{
			(this->*PTR[i])();
			break ;
		}
		i++;
	}
	if (i == 4)
		std::cout << "UNKNOWN" << std::endl << std::endl;
}
