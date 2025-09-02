/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:11:05 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 14:57:38 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "contact.hpp"
#include "ansi_colors.hpp"

class	PhoneBook {
	private:
		Contact		_contacts[8];
		int			_currIdx;
		int			_totalContacts;
		std::string	_getInput(const std::string &prompt);
		bool		_isValidIdx(const std::string &input, int &idx);
		int			_readValidIdx(void);

	public:
		PhoneBook();
		~PhoneBook();
		void		addContact();
		void		_saveContact(const Contact &contact);
		Contact		_collectContactData(void);
		void		searchContact();
		void		showContactDetails(int index);
		void		displayContacts();
};

#endif
