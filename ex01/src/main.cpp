/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:35:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 19:08:06 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

static void	printBanner(void)
{
	std::cout << "==== PHONEBOOK ====" << std::endl;
	std::cout << "Commands: ADD | SEARCH | EXIT" << std::endl;
}

static bool	processCommand(PhoneBook &book, const std::string &cmd)
{
	if (cmd == "ADD")
		book.addContact();
	else if (cmd == "SEARCH")
		book.searchContact();
	else if (cmd == "EXIT")
	{
		std::cout << "Goodbye!" << std::endl;
		return (false);
	}
	else if (cmd.empty())
		return (true);
	else
		std::cout << "Unknown command. Use: ADD | SEARCH | EXIT" << std::endl;
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
