/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:05:24 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 12:13:03 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/*
** Local variables:
**   - filename: stores the name of the file to process.
**   - s1: first string to search for in the file.
**   - s2: replacement string to substitute in place of s1.
**
** Steps performed:
** 1) Call validateArguments():
** 2) Call processFile():
** 3) If both functions succeed, return 0 to indicate success.
*/
int	main(int ac, char **av)
{
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (!validateArguments(ac, av, filename, s1, s2))
		return (1);
	if (!processFile(filename, s1, s2))
		return (1);
	return (0);
}
