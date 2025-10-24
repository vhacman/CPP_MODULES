/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_input.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:29:21 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/08 14:04:02 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** _isValidPhoneNumber():
** Validates whether a given string is a proper phone number.
** 1) If the string is empty, return false (invalid input).
** 2) Iterate through each character of the string:
**      - If any character is not a digit (checked with std::isdigit),
**        return false immediately.
** 3) If the loop finishes without finding invalid characters,
**    return true (the string contains only digits).
**   - true  → phoneNumber is non-empty and contains only digits.
**   - false → phoneNumber is empty or contains invalid characters.
*/
bool	PhoneBook::_isValidPhoneNumber(const std::string &phoneNumber)
{
	size_t	i;
	
	if (phoneNumber.empty())
		return (false);
	for (i = 0; i < phoneNumber.length(); i++)
	{
		if (!std::isdigit(phoneNumber[i]))
			return (false);
	}
	return (true);
}

/*
** _getInput():
** Reads and validates user input from standard input (stdin),
** optionally checking if the input is a valid phone number.
** 1) Display the prompt and read a line from stdin.
**    - If reading fails (EOF), return an empty string.
** 2) If the input is empty:
**      - Print an error message: "Field cannot be empty".
**      - Restart the loop and ask again.
** 3) If isPhoneNumber is true:
**      - Call _isValidPhoneNumber(input).
**      - If validation fails, print an error message and
**        ask again.
** 4) If all checks pass, return the valid input string.
**
** Return value:
**   - A non-empty, valid string entered by the user.
**   - An empty string if input reading fails (e.g., EOF).
*/
std::string	PhoneBook::_getInput(const std::string &prompt, bool isPhoneNumber)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return ("");
		if (input.empty())
		{
			std::cout << "Field cannot be empty. Try Again." << std::endl;
			continue ;
		}
		if (isPhoneNumber && !_isValidPhoneNumber(input))
		{
			std::cout << "Invalid phone number. Please enter only digits." << std::endl;
			continue ;
		}
		return (input);
	}
}

/*
** _isValidIdx():
** Validates whether a given string represents a valid index
** for accessing a contact in the phonebook.
** Behavior:
** 1) If the input is empty, return false.
** 2) Iterate over each character in the input:
**      - If any character is not a digit ('0'–'9'),
**        return false immediately.
** 3) Convert the string to an integer using atoi().
** 4) Check if the integer is within the valid range:
**      - Must be >= 1 and <= _totalContacts.
**      - If out of range, return false.
** 5) If valid, assign result - 1 to 'index'
**    (convert from 1-based user input to 0-based array index).
** 6) Return true to indicate a valid index.
** Return value:
**   - true  → input is a valid index (stored in 'index').
**   - false → input is empty, non-numeric, or out of range.
*/
bool PhoneBook::_isValidIdx(const std::string &input, int &index)
{
	int		result;
	size_t	i;
	char	c;

	if (input.empty())
		return (false);
	for (i = 0; i < input.size(); i++)
	{
		c = input[i];
		if (c < '0' || c > '9')
			return (false);
	}
	result = atoi(input.c_str());
	if (result < 1 || result > this->_totalContacts)
		return (false);
	index = result - 1;
	return (true);
}

/*
** _readValidIdx():
** Continuously prompts the user to enter a valid contact index
** until a correct value is provided or input ends.
** 1) If there are no contacts (_totalContacts == 0):
**      - Print a red message: "No contacts to display."
**      - Exit the program immediately with status 0.
** 2) Otherwise, enter an infinite loop:
**      - Print a cyan prompt asking the user to enter an index
**        between 1 and _totalContacts.
**      - Read a full line from standard input into 'input'.
**      - If reading fails (EOF), print "Exiting program..."
**        in dim color and terminate the program with exit(0).
**      - Call _isValidIdx(input, index) to validate the user input.
**        • If valid, return the corresponding 0-based index.
**        • If invalid, print an error message in red and prompt again.
** Return value:
**   - Returns a valid 0-based index chosen by the user.
**   - Exits the program if there are no contacts or on EOF.
*/
int PhoneBook::_readValidIdx(void)
{
	std::string	input;
	int			index;
	if (this->_totalContacts == 0)
	{
		std::cout << C_BRED << "No contacts to display."
					<< C_RESET << std::endl;
		std::exit(0);
	}
	while (true)
	{
		std::cout << C_BCYAN << "Enter index of contact to display (1-"
					<< this->_totalContacts << "): " << C_RESET;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl
						<< C_DIM << "Exiting program..."
						<< C_RESET << std::endl;
			std::exit(0);
		}
		if (_isValidIdx(input, index))
			return (index);
		std::cout << C_BRED << "Invalid index. " << C_RESET
					<< "Please enter a number between 1 and "
					<< this->_totalContacts << "." << std::endl;
	}
}
