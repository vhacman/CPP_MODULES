/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:59:49 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 12:18:18 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.hpp"

/*
** 1) Copy the original string into 'result'.
** 2) Start searching from position 0.
** 3) Use find() to locate the next occurrence of s1.
** 4) If found:
**      - Erase s1 from 'result' at the found position.
**      - Insert s2 at the same position.
**      - Advance the position by the length of s2
**        to continue searching after the replacement.
** 5) Repeat until no more occurrences of s1 are found.
** 6) Return the modified string with all replacements applied.
*/
std::string	replaceAllOccurrences(const std::string& content,
								const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos;

	result = content;
	pos = 0;
	while ((pos = result.find(s1, pos)) != std::string::npos)
	{
		result.erase(pos, s1.length());
		result.insert(pos, s2);
		pos += s2.length();
	}
	return (result);
}
