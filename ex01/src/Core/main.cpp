/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:35:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 14:30:57 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** Prints the program header and available commands
** to the standard output.
**   - Introduces the PhoneBook program to the user.
**   - Displays the list of valid commands in a clear
**     and styled format (using color macros).
** Example output:
**   ==== PHONEBOOK ====
**   Commands: ADD | SEARCH | EXIT
*/
static void	printBanner(void)
{
	std::cout << C_BCYAN << "==== PHONEBOOK ===="
				<< C_RESET << std::endl;

	std::cout << C_BYELLOW "Commands: "
				<< C_CYAN << "ADD" << C_RESET << " | "
				<< C_CYAN << "SEARCH" << C_RESET << " | "
				<< C_CYAN << "EXIT" << C_RESET
				<< std::endl << std::endl;
}

/*
** Interprets and executes user commands for the PhoneBook program.
**   - book: reference to the PhoneBook instance where actions are performed.
**   - cmd:  string containing the user’s command.
**   - If cmd == "ADD":
**       Calls book.addContact() to create and store a new contact.
**   - If cmd == "SEARCH":
**       Calls book.searchContact() to display the list of contacts
**       and allow the user to select one for detailed viewing.
**   - If cmd == "EXIT":
**       Prints a "Goodbye!" message in green and returns false
**       to signal the program should terminate.
**   - If cmd is empty:
**       Does nothing and keeps the program running (returns true).
**   - Otherwise (unknown command):
**       Prints an error message in red and shows the valid commands
**       (ADD, SEARCH, EXIT).
*/
static bool	processCommand(PhoneBook &book, const std::string &cmd)
{
	if (cmd == "ADD")
		book.addContact();
	else if (cmd == "SEARCH")
		book.searchContact();
	else if (cmd == "EXIT")
	{
		std::cout << C_BGREEN << "Goodbye!"
					<< C_RESET << std::endl;
		return (false);
	}
	else if (cmd.empty())
		return (true);
	else
	{
		std::cout << C_BRED
					<< "Unknown command. " << C_RESET
					<< "Use: " << C_BYELLOW << "ADD" << C_RESET
					<< " | " << C_BYELLOW << "SEARCH" << C_RESET
					<< " | " << C_BYELLOW << "EXIT" << C_RESET
					<< std::endl;
	}
	return (true);
}

/*
** Entry point of the PhoneBook program.
** 1) Create a PhoneBook object (initially empty).
** 2) Display the program banner and list of available commands
**    by calling printBanner().
** 3) Enter an infinite loop to continuously read user commands:
**      - Print a prompt symbol ("> ").
**      - Use std::getline() to read a full line from standard input.
**      - If input fails (e.g., EOF), print "Exiting program..."
**        and break the loop.
**      - Otherwise, call processCommand(book, cmd) to interpret
**        and execute the user command.
**      - If processCommand() returns false (when user types "EXIT"),
**        break the loop and terminate the program.

**   ==== PHONEBOOK ====
**   Commands: ADD | SEARCH | EXIT
**
**   > ADD
**   (prompts for contact data)
**   > SEARCH
**   (shows contact list and details)
**   > EXIT
**   Goodbye!
*/
int	main(void)
{
	PhoneBook		book;
	std::string		cmd;

	printBanner();
	while (true)
	{
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl << "Exiting program..." << std::endl;
			break ;
		}
		if (!processCommand(book, cmd))
			break ;
	}
	return (0);
}
