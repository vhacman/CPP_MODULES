/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:40:13 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 19:06:12 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

/*
** Costruttore di default.
** Inizializza l'indice circolare di inserimento a 0.
** _totalContacts indica quanti contatti validi sono presenti.
*/
PhoneBook::PhoneBook() : _currIdx(0), _totalContacts(0)
{

}

/*
** Distruttore.
** Non richiede rilascio esplicito: non ci sono risorse dinamiche.
*/
PhoneBook::~PhoneBook()
{

}

/*
** Legge una riga da stdin mostrando il prompt.
** Se l'input è EOF, stampa un messaggio ed esce dal programma.
** Rifiuta input vuoti e ripete la richiesta finché non è valido.
** Ritorna la stringa inserita dall'utente.
*/
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

/*
** Acquisisce i campi del contatto tramite _getInput(...).
** Salva il contatto nello slot _currIdx con saveContact(...).
** Aggiorna _currIdx in modalità circolare (0..7).
** Incrementa _totalContacts fino a un massimo di 8.
** Stampa un messaggio di conferma con l'indice visibile (1..8).
*/
void	PhoneBook::addContact(void)
{
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	std::cout << "Adding new contact..." << std::endl;

	firstName = this->_getInput("Enter first name: ");
	lastName = this->_getInput("Enter last name: ");
	nickName = this->_getInput("Enter nickname: ");
	phoneNumber = this->_getInput("Enter phone number: ");
	darkestSecret = this->_getInput("Enter darkest secret: ");

	this->_contacts[this->_currIdx].saveContact(firstName, lastName, nickName, phoneNumber, darkestSecret, this->_currIdx);

	std::cout << "Contact added successfully at index " << (this->_currIdx + 1) << "!" << std::endl;

	this->_currIdx = (this->_currIdx + 1) % 8;
	if (this->_totalContacts < 8)
		this->_totalContacts++;
}

/*
** Se la rubrica è vuota, stampa un avviso e termina.
** Altrimenti stampa intestazione e righe dei contatti non vuoti.
** L'allineamento è delegato alle funzioni del tipo Contact.
*/
void PhoneBook::displayContacts(void)
{
	int	i;

	if (this->_totalContacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	this->_contacts[0].showTitle();
	for (i = 0; i < 8; i++)
	{
		if (!this->_contacts[i].isEmpty())
			this->_contacts[i].showRow();
	}
}

/*
** Verifica che 'input' sia un numero intero decimale valido.
** Effettua parsing manuale con controllo overflow su int32.
** Controlla che il valore sia nell'intervallo 1.._totalContacts.
** Se valido, assegna a 'index' il valore zero-based e ritorna true.
** In caso contrario, ritorna false senza modificare 'index'.
*/
bool PhoneBook::_isValidIdx(const std::string& input, int& index)
{
	int		result;
	int		digit;
	size_t	i;

	if (input.empty())
		return (false);
	for (i = 0; i < input.length(); i++)
	{
		if (input[i] < '0' || input[i] > '9')
			return (false);
	}
	result = 0;
	for (i = 0; i < input.length(); i++)
	{
		digit = input[i] - '0';
		if (result > (2147483647 - digit) / 10)
			return (false);
		result = result * 10 + digit;
	}
	if (result < 1 || result > this->_totalContacts)
		return (false);
	index = result - 1;
	return (true);
}
/*
** Legge un indice valido dall'utente.
** Mostra il prompt e continua a leggere finché non ottiene un indice
** valido nell'intervallo 1.._totalContacts.
** Gestisce EOF terminando il programma.
** Restituisce l'indice zero-based del contatto selezionato.
*/
int PhoneBook::_readValidIdx(void)
{
	std::string	input;
	int			index;

	while (true)
	{
		std::cout << "Enter index of contact to display (1-" << this->_totalContacts << "): ";
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "Exiting program..." << std::endl;
			std::exit(0);
		}
		if (!_isValidIdx(input, index))
		{
			std::cout << "Invalid index. Please enter a number between 1 and "
						<< this->_totalContacts << "." << std::endl;
			continue ;
		}
		break ;
	}
	return (index);
}

/*
** Stampa i dettagli completi del contatto all'indice specificato.
** Presuppone che l'indice sia già stato validato e sia zero-based.
** Mostra un'intestazione formattata seguita da tutti i campi del contatto.
*/
void PhoneBook::showContactDetails(int index)
{
	std::cout << std::endl << "Contact details:" << std::endl;
	std::cout << "=================" << std::endl;
	this->_contacts[index].showAll();
}

/*
** Funzione principale per cercare e visualizzare un contatto.
** Verifica se la rubrica è vuota, mostra l'elenco dei contatti,
** acquisisce un indice valido dall'utente e stampa i dettagli.
*/
void PhoneBook::searchContact(void)
{
	int	index;

	if (this->_totalContacts == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return ;
	}
	this->displayContacts();
	index = this->_readValidIdx();
	this->showContactDetails(index);
}
