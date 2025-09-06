/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 13:50:34 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 14:17:24 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"

/*
** main():
** Entry point of the program. Demonstrates how the Harl class
** handles complaints based on a user-provided log level.
** Behavior:
** 1) Check if exactly one argument is provided (besides the program name).
**    - If not, print an error message explaining the valid options:
**      DEBUG, INFO, WARNING, ERROR.
**    - Exit the program with return code 0.
** 2) If a valid argument is given, pass it to _harl.complain().
**    - The complain() method will determine which messages to print,
**      depending on the severity level chosen
*/
int	main(int ac, char **av) {
	Harl	_harl;

	if (ac != 2)
	{
		std::cout << "Error: Please choose a level: DEBUG, INFO, WARNING, ERROR"
			<< std::endl;
		return (0);
	}
	_harl.complain(av[1]);
	return (0);
}
