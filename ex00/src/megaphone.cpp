/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:53:31 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 16:35:38 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

void	printFeedbackNoise()
{
	std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *" << std::endl;
}

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


int	main(int ac, char **av)
{
	if (ac == 1)
		printFeedbackNoise();
	else
		printUpperCaseArgs(ac, av);
	return (0);
}
