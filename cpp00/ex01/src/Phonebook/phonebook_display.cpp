/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_display.cc                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:30:42 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 15:02:42 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** Displays all stored contacts in a formatted table.
**
** Steps:
**   1. If _totalContacts == 0, prints "Phonebook is empty!" and exits.
**   2. Prints the contact table header using printContactTable().
**   3. Iterates through all 8 possible slots:
**        - If the slot is not empty, prints the row with displayContactRow().
**
** This ensures that only valid, initialized contacts are shown.
*/
void	PhoneBook::displayContacts(void)
{
	int	i;

	if (this->_totalContacts == 0)
	{
		std::cout << C_BRED << "Phonebook is empty!"
					<< C_RESET << std::endl;
		return ;
	}
	std::cout << C_BCYAN << std::endl
				<< "==== CONTACT LIST ===="
				<< C_RESET << std::endl;
	std::cout << C_BYELLOW;
	this->_contacts[0].printContactTable();
	std::cout << C_RESET;
	for (i = 0; i < 8; i++)
	{
		if (!this->_contacts[i].getIfEmpty())
		{
			std::cout << C_GREEN;
			this->_contacts[i].displayContactRow();
			std::cout << C_RESET;
		}
	}
}

/*
** Displays full details of a specific contact.
**
** Parameters:
**   - i: index of the contact in the phonebook
**
** Steps:
**   1. Prints a section header "Contact details:".
**   2. Calls printContactDetails() on the selected contact
**      to show all fields (first name, last name, etc.).
*/
void	PhoneBook::showContactDetails(int i)
{
	std::cout << std::endl
				<< C_BYELLOW << "Contact details:" << C_RESET << std::endl;
	std::cout << C_DIM << "=================" << C_RESET << std::endl;
	this->_contacts[i].printContactDetails();
}
