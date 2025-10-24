/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidationAndProcess.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:11:30 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/08 18:20:39 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/*
** 1) Checks if the number of arguments is exactly 4:
**      ./program <filename> <s1> <s2>
**    - If not, prints usage instructions and returns false.
** 2) Assigns:
**      filename = av[1]
**      s1 = av[2]
**      s2 = av[3]
** 3) Ensures that s1 is not empty:
**    - If s1 is an empty string, prints an error message
**      and returns false.
** 4) If all checks pass, returns true.
*/
bool	validateArguments(int ac, char **av, std::string &filename,
								std::string &s1, std::string &s2)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./program <filename> <s1> <s2>" << std::endl;
		return (false);
	}
	filename = av[1];
	s1 = av[2];
	s2 = av[3];
	if (s1.empty())
	{
		std::cout << "Error: s1 must not be empty" << std::endl;
		return (false);
	}
	return (true);
}

/*
** 1) Calls findLatestReplaceFile(filename):
**      - Determines which file to use as input.
**      - If the file was already processed before, it may choose
**        the latest ".replace" version instead of the original.
**      - Stores result in actualInputFile.
** 2) Prints the file being used as input.
** 3) Calls readFileContent(actualInputFile):
**      - Reads the entire content of the file into a string.
**      - If the content is empty (read error), returns false.
** 4) Calls replaceAllOccurrences(content, s1, s2):
**      - Produces a new string with every occurrence of s1
**        replaced by s2.
**      - Stores the result in processedContent.
** 5) Defines the output file name as actualInputFile + ".replace".
** 6) Calls writeToFile(outfileName, processedContent):
**      - Writes the modified content to the new file.
**      - If writing fails, returns false.
** 7) Prints a success message including the output file name.
*/
bool	processFile(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::string	content;
	std::string	processedContent;
	std::string	outfileName;

	std::cout << "Using input file: " << filename << std::endl;
	content = readFileContent(filename);
	if (content.empty())
		return (false);
	processedContent = replaceAllOccurrences(content, s1, s2);
	outfileName = filename + ".replace";
	if (!writeToFile(outfileName, processedContent))
		return (false);
	std::cout << "File processed successfully. Output saved to: "
				<< outfileName << std::endl;
	return (true);
}
