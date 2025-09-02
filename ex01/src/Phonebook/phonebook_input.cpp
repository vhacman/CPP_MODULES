/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_input.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 14:29:21 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/02 15:01:24 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


//funzione membro privata della classe PhoneBook. ritorna un std::string.
/*la funzione mostra un prompt all'utente, legge input da tastiera, se input è vuoto forza utente
a reinserirlo. se la lettura fallisce, restituisce stringa vuota
se input è valido, lo restituisce*/
std::string	PhoneBook::_getInput(const std::string &prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			return ("");
		if (!input.empty())
			return (input);
		else
			std::cout << "Field cannot be empty. Try Again." << std::endl;
	}
}

/*verifica se una strina di input rappresenta un indice valido per accedere
ai contatti del Phonebook*/
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


