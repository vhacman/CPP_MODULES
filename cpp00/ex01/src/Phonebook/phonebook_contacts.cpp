/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_contacts.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:14:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/10/16 10:19:33 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** Prompts the user for all required contact fields:
**   - First Name
**   - Last Name
**   - Nickname
**   - Phone Number
**   - Darkest Secret
**
** Uses _getInput() to retrieve validated input for each field.
** Creates a new Contact instance, initializes it using setContact(),
** and assigns it the current index (_currIdx).
**
** Returns:
**   - A fully initialized Contact object ready to be stored.
*/
Contact	PhoneBook::_collectContactData(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	Contact		newContact;

	std::cout << C_BCYAN << "Adding new contact..." << C_RESET << std::endl;
	firstName = this->_getInput(std::string(C_MAGENTA) + "Enter first name: " + C_RESET, false);
	lastName = this->_getInput(std::string(C_MAGENTA) + "Enter last name: " + C_RESET, false);
	nickName = this->_getInput(std::string(C_MAGENTA) + "Enter nickname: " + C_RESET, false);
	phoneNumber = this->_getInput(std::string(C_MAGENTA) + "Enter phone number: " + C_RESET, true);
	darkestSecret = this->_getInput(std::string(C_MAGENTA) + "Enter darkest secret: " + C_RESET, false);
	newContact.setContact(firstName, lastName, nickName, phoneNumber, darkestSecret, this->_currIdx + 1);
	return (newContact);
}

/*
** Stores a Contact object in the phonebook at the current index.
**
** Steps:
**   1. Assigns the given contact to _contacts[_currIdx].
**   2. Prints a success message with the saved index.
**   3. Increments _currIdx, wrapping around with modulo 8,
**      since the phonebook can only hold 8 contacts.
**   4. Increases _totalContacts until it reaches the maximum (8).
**
** Parameters:
**   - contact: reference to a Contact object to be saved.
*/
void	PhoneBook::_saveContact(const Contact &contact)
{
	this->_contacts[this->_currIdx] = contact;
	std::cout << C_BGREEN << "Contact added successfully at index "
			<< (this->_currIdx + 1) << "!" << C_RESET << std::endl;
	this->_currIdx = (this->_currIdx + 1) % 8;
	if (this->_totalContacts < 8)
		this->_totalContacts++;
}
