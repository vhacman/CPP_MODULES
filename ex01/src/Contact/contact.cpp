/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:38:09 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 14:29:03 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/*
** Default constructor for the Contact class.
** Uses a member initialization list to set:
** - _index to 0
** - _isEmpty to true
** This ensures the object starts in a consistent state.
*/
Contact::Contact() : _index(0), _isEmpty(true) {}

/*
** Destructor for the Contact class.
** No dynamic resources are allocated, so it performs no action.
*/
Contact::~Contact() {}

/*
** setContact:
** Assigns values to all data fields of the contact, including
** first name, last name, nickname, phone number, and darkest secret.
** It also sets the index and changes _isEmpty to false,
** indicating that the contact is now initialized.
**
** - index: position of the contact in the phonebook
*/
void	Contact::setContact(std::string firstName, std::string lastName,
						std::string nickname, std::string phoneNumber,
						std::string darkestSecret, int index)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickname = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
	this->_index = index;
	this->_isEmpty = false;
}

/*
** getIfEmpty:
** Returns true if the contact is empty (never initialized),
** otherwise returns false.
*/
bool	Contact::getIfEmpty(void) const
{
	return (this->_isEmpty);
}
