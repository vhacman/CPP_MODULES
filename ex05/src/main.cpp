/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:49:47 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 13:49:02 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

/*
** 1) Create an instance of Harl called `_harl`.
** 2) Call `_harl.complain("DEBUG")`:
**      - Executes Harl::debug() and prints the debug message.
** 3) Call `_harl.complain("INFO")`:
**      - Executes Harl::info() and prints the info message.
** 4) Call `_harl.complain("WARNING")`:
**      - Executes Harl::warning() and prints the warning message.
** 5) Call `_harl.complain("ERROR")`:
**      - Executes Harl::error() and prints the error message.
** 6) Call `_harl.complain("BOMB")`:
**      - Since "BOMB" is not a recognized level, it prints "UNKNOWN".
** 7) Call the methods again in reverse order ("ERROR", "WARNING",
**    "INFO", "DEBUG") to confirm that complain() dynamically
**    invokes the correct function each time.
*/
int	main(void){
	Harl	_harl;

	_harl.complain("DEBUG");
	_harl.complain("INFO");
	_harl.complain("WARNING");
	_harl.complain("ERROR");

	_harl.complain("BOMB");

	_harl.complain("ERROR");
	_harl.complain("WARNING");
	_harl.complain("INFO");
	_harl.complain("DEBUG");
	return (0);
}
