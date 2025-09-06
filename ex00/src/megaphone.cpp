/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:53:31 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 14:27:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

/*
** printFeedbackNoise():
** Prints a default message when no command-line arguments
** are provided. Simulates a loud noise to indicate missing input.
*/
void	printFeedbackNoise()
{
	std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
}

/*
** printUpperCaseArgs(ac, av):
** Iterates over all command-line arguments (except the program name),
** converts each character to uppercase, and prints the results.
** Arguments are separated by a space, and a newline is printed at the end.
**
** Parameters:
**   - ac: number of command-line arguments.
**   - av: array of argument strings.
**/
void	printUpperCaseArgs(int ac, char **av)
{
	int		i;
	size_t	j;

	i = 1;
	while (i < ac)
	{
		std::string arg(av[i]);
		j = 0;
		while (j < arg.size())
		{
			std::cout << (char)std::toupper(arg[j]);
			j++;
		}
		if (i < ac - 1)
			std::cout << ' ';
		i++;
	}
	std::cout << std::endl;
}

/*
** main():
** Entry point of the program.
**
** Behavior:
** - If no extra arguments are provided (ac == 1), call printFeedbackNoise().
** - Otherwise, call printUpperCaseArgs(ac, av) to print all arguments
**   in uppercase.
** - Returns 0 to indicate successful execution.
**/
int	main(int ac, char **av)
{
	if (ac == 1)
		printFeedbackNoise();
	else
		printUpperCaseArgs(ac, av);
	return (0);
}
