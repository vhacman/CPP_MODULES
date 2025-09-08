/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:49:50 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/08 13:39:35 by vhacman          ###   ########.fr       */
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
** getLevelIndex(level):
** Maps a string representing a complaint level to its
** corresponding integer index.
** 1) Define an array of valid levels: {"DEBUG", "INFO",
**    "WARNING", "ERROR"}.
** 2) Iterate through the array (0 to 3).
** 3) If the input string matches levels[i], return i.
** 4) If no match is found, return -1 to indicate an
**    invalid/unknown level.
*/
int	Harl::getLevelIndex(std::string level) {
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i;

	i = 0;
	while(i < 4)
	{
		if(levels[i] == level)
			return i;
		i++;
	}
	return (-1);
}

/*
** Handles complaints depending on the severity level.
**   - level: string specifying the complaint level
**            ("DEBUG", "INFO", "WARNING", "ERROR").
** 1) Define an array of pointers to member functions (ptr[4]),
**    mapping to debug(), info(), warning(), and error().
** 2) Call getLevelIndex(level) to translate the string into
**    an integer index:
** 3) Use a switch statement on levelIndex:
**    - For index 0 (DEBUG):
**        Execute debug(), then fall through to INFO, WARNING, ERROR.
**    - For index 1 (INFO):
**        Execute info(), then fall through to WARNING, ERROR.
**    - For index 2 (WARNING):
**        Execute warning(), then fall through to ERROR.
**    - For index 3 (ERROR):
**        Execute error() only.
**    The intentional "fall through" allows messages of equal
**    or higher severity to be printed sequentially.
** 4) If levelIndex is invalid, print a default message:
**    "[ Probably complaining about insignificant problems ]".
*/
void	Harl::complain(std::string level) {
	int			levelIndex;
	void		(Harl::*ptr[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	levelIndex = getLevelIndex(level);
	switch (levelIndex)
	{
		case 0:
			(this->*ptr[0])();
		case 1:
			(this->*ptr[1])();
		case 2:
			(this->*ptr[2])();
		case 3:
			(this->*ptr[3])();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
