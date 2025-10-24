/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:29:45 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/06 14:27:49 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
#	include "ansi_colors.hpp"

/*
**   Represents a single contact in the phonebook, storing
**   personal information such as name, phone number, and
**   a secret. Provides methods to set and display this data
**   in different formats.
*/
class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;
		bool		_isEmpty;

	public:
		Contact();
		~Contact();
		void		setContact(std::string firstName, std::string lastName,
							std::string nickname, std::string phoneNumber,
							std::string darkestSecret, int index);
		void		printContactTable(void) const;
		void		displayContactRow(void) const;
		void		printContactDetails(void) const;
		std::string	truncateToTen(std::string text) const;
		bool		getIfEmpty(void) const;
};
#endif
