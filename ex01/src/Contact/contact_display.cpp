/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_display.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:01:40 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/03 10:28:54 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/*
** Prints the full details of a contact:
**   - First Name
**   - Last Name
**   - Nickname
**   - Phone Number
**   - Darkest Secret
**
** If the contact is empty (_isEmpty == true),
** it prints "Contact is empty" instead.
*/
void	Contact::printContactDetails(void) const
{
	if (this->_isEmpty)
	{
		std::cout << C_BRED << "Contact is empty"
		          << C_RESET << std::endl;
		return ;
	}
	std::cout << C_BYELLOW << "First Name: " << C_RESET
		<< C_GREEN << this->_firstName << C_RESET << std::endl;
	std::cout << C_BYELLOW << "Last Name: " << C_RESET
		<< C_GREEN << this->_lastName << C_RESET << std::endl;
	std::cout << C_BYELLOW << "Nickname: " << C_RESET
		<< C_GREEN << this->_nickname << C_RESET << std::endl;
	std::cout << C_BYELLOW << "Phone Number: " << C_RESET
		<< C_GREEN << this->_phoneNumber << C_RESET << std::endl;
	std::cout << C_BYELLOW << "Darkest Secret: " << C_RESET
		<< C_GREEN << this->_darkestSecret << C_RESET << std::endl;
}

/*
** Prints a single row containing the contact’s:
**   - Index
**   - First Name
**   - Last Name
**   - Nickname
**
** Each field is truncated & right-aligned
** to a width of 10 characters using setw().
** If the contact is empty, nothing is printed.
*/
void	Contact::displayContactRow(void) const
{
	if (this->_isEmpty)
		return ;
	std::cout << "|" << std::setw(10) << this->_index << "|";
	std::cout << std::setw(10) << this->truncateToTen(this->_firstName) << "|";
	std::cout << std::setw(10) << this->truncateToTen(this->_lastName) << "|";
	std::cout << std::setw(10) << this->truncateToTen(this->_nickname) << "|" << std::endl;
}

/*
** Utility function used to format strings for display in the contact table.
**
** - If the string length > 10, it truncates
**   to the first 9 characters and adds a '.'.
** - Otherwise, returns the string unchanged.
*/
std::string Contact::truncateToTen(std::string text) const
{
	if (text.length() > 10)
		text = text.substr(0, 9) + ".";
	return (text);
}

/*
** Prints the header of the contact table:
**   - Column names: Index, First Name, Last Name, Nickname
**   - A separator line for formatting
**
** This is used before displaying individual rows
** with displayContactRow().
*/
void	Contact::printContactTable(void) const
{
	std::cout << C_BYELLOW
			<< "|" << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << "|"
			<< C_RESET << std::endl;
	std::cout << C_DIM
			<< "|----------|----------|----------|----------|"
			<< C_RESET << std::endl;
}
