/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:35:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 15:08:30 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
