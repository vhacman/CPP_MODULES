/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_core.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:28:29 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 14:59:53 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** Default constructor for the PhoneBook class.
** Initializes:
**   - _currIdx       = 0 (next slot to insert)
**   - _totalContacts = 0 (no contacts yet)
*/
PhoneBook::PhoneBook() : _currIdx(0), _totalContacts(0) {}

/*
** Destructor for the PhoneBook class.
** No dynamic memory is allocated,
** so no special cleanup is required.
*/
PhoneBook::~PhoneBook() {}

/*
** Adds a new contact to the phonebook.
**
** Steps:
**   1. Calls _collectContactData() to gather input from the user.
**   2. Saves the newly created contact in the array
**      using _saveContact().
**
** This method updates the internal index and contact count
** as managed by _saveContact().
*/
void PhoneBook::addContact(void)
{
	Contact newContact = this->_collectContactData();
	this->_saveContact(newContact);
}

/*
** Searches and displays details of a specific contact.
**
** Steps:
**   1. If _totalContacts == 0, prints "Phonebook is empty!" and exits.
**   2. Calls displayContacts() to show the list in table form.
**   3. Reads a valid index with _readValidIdx().
**   4. Calls showContactDetails() to print full details
**      of the selected contact.
*/
void PhoneBook::searchContact(void)
{
	int	index;

	if (this->_totalContacts == 0)
	{
		std::cout << C_BRED << "Phonebook is empty!"
					<< C_RESET << std::endl;
		return ;
	}
	this->displayContacts();
	index = this->_readValidIdx();
	this->showContactDetails(index);
}
