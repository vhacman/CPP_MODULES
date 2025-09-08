/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_operations.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:10:12 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 12:18:10 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

/*
** Behavior:
** 1) Start with currentFile = baseFilename.
** 2) Define testFile = baseFilename + ".replace".
** 3) Loop:
**      - Try to open testFile in read mode.
**      - If the file exists (stream opens successfully):
**          * Close the stream.
**          * Update currentFile = testFile.
**          * Append another ".replace" to testFile and repeat.
**      - If the file does not exist, break the loop.
** 4) Return currentFile, which will be the last existing file in
**    the chain of ".replace" files.
*/
std::string	findLatestReplaceFile(const std::string& baseFilename)
{
	std::string		currentFile;
	std::string		testFile;
	std::fstream	testStream;

	currentFile = baseFilename;
	testFile = baseFilename + ".replace";
	while (true)
	{
		testStream.open(testFile.c_str(), std::ios::in);
		if (testStream.is_open())
		{
			testStream.close();
			currentFile = testFile;
			testFile += ".replace";
		}
		else
			break;
	}
	return (currentFile);
}

/*
** 1) Open the file in read mode.
**    - If the file cannot be opened, print an error message
**      and return an empty string.
** 2) Read the file line by line using std::getline().
** 3) Append each line to the result string 'content'.
** 4) After each line (except the last one), append a newline
**    character '\n' to preserve original formatting.
** 5) Close the file.
** 6) Return the complete content as a single string.
*/
std::string	readFileContent(const std::string& filename)
{
	std::fstream	inFile;
	std::string		line;
	std::string		content;

	inFile.open(filename.c_str(), std::ios::in);
	if (!inFile.is_open())
	{
		std::cout << "Error: cannot open input file '" << filename << "'" << std::endl;
		return ("");
	}
	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += '\n';
	}
	inFile.close();
	return (content);
}

/*
** 1) Open the file in output mode with truncation:
**      - If the file already exists, its content is erased.
**      - If it does not exist, a new file is created.
** 2) If the file cannot be opened, print an error message
**    and return false.
** 3) Write the full content string into the file.
** 4) Close the file after writing.
** 5) Return true to indicate success.
*/
bool	writeToFile(const std::string& filename, const std::string& content)
{
	std::fstream	outFile;

	outFile.open(filename.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cout << "Error: cannot create output file '" << filename << "'" << std::endl;
		return (false);
	}
	outFile << content;
	outFile.close();
	return (true);
}
