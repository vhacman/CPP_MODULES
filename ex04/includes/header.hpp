/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:30:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 12:17:55 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEADER_HPP
# define HEADER_HPP

# include <iostream>
# include <string>
# include <fstream>

/*
** findLatestReplaceFile():
**   Finds the most recent version of a file by checking
**   for chained ".replace" files.
*/
std::string	findLatestReplaceFile(const std::string& baseFilename);

/*
** writeToFile():
**   Writes the given content into a file.
**   Returns true on success, false on failure.
*/
bool		writeToFile(const std::string& filename,
						const std::string& content);

/*
** replaceAllOccurrences():
**   Returns a copy of the input string where every occurrence
**   of s1 is replaced by s2.
*/
std::string	replaceAllOccurrences(const std::string& content,
									const std::string& s1,
									const std::string& s2);

/*
** readFileContent():
**   Reads the full content of a file into a single string.
**   Returns an empty string if the file cannot be opened.
*/
std::string	readFileContent(const std::string& filename);

/*
** processFile():
**   Full workflow: locate latest file, read content, replace
**   all s1 occurrences with s2, and write result into a new
**   ".replace" file. Returns true on success, false otherwise.
*/
bool		processFile(const std::string &filename,
						const std::string &s1,
						const std::string &s2);

/*
** validateArguments():
**   Validates command-line arguments and extracts filename,
**   s1, and s2. Returns true if valid, false otherwise.
*/
bool		validateArguments(int ac, char **av,
								std::string &filename,
								std::string &s1,
								std::string &s2);

#endif
