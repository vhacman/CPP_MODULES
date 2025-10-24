/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:11:05 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/08 13:54:04 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"
#include "ansi_colors.hpp"

/*
**   Implements a simple phonebook that can store up to
**   8 contacts. Provides functions to add new contacts,
**   list them, and display detailed information.
** Private methods (helpers, encapsulated logic):
*/
class	PhoneBook {
	private:
		Contact		_contacts[8];
		int			_currIdx;
		int			_totalContacts;
		std::string	_getInput(const std::string &prompt, bool isPhoneNumber);
		bool		_isValidIdx(const std::string &input, int &idx);
		int			_readValidIdx(void);
		void		_saveContact(const Contact &contact);
		Contact		_collectContactData(void);
		bool		_isValidPhoneNumber(const std::string &phoneNumber);

	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		searchContact();
		void		showContactDetails(int index);
		void		displayContacts();
};

#endif
