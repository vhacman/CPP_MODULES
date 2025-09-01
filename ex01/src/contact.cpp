/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:15:07 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 18:45:42 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

/*
** Costruttore di default.
** Inizializza l'indice a 0 e imposta _isEmpty a true,
** segnando il contatto come non ancora valido.
*/
Contact::Contact() : _index(0), _isEmpty(true)
{

}

/*
** Distruttore della classe.
** Non esegue alcuna operazione specifica poiché non ci
** sono risorse dinamiche da liberare.
*/
Contact::~Contact()
{

}

/*
** Riceve tutti i dati di un contatto e li assegna ai
** campi privati della classe.
** Parametri:
**  - firstName: nome
**  - lastName: cognome
**  - nickname: soprannome
**  - phoneNumber: numero di telefono
**  - darkestSecret: segreto
**  - index: posizione logica del contatto
**
**
**  - Popola i campi interni con i valori forniti.
**  - Imposta _isEmpty a false per indicare che il contatto ora contiene
**    dati validi.
*/
void Contact::saveContact(std::string firstName, std::string lastName, std::string nickname,
						 std::string phoneNumber, std::string darkestSecret, int index)
{
	this->_firstName = firstName;
	this->_lastName = lastName;
	this->_nickName = nickname;
	this->_phoneNumber = phoneNumber;
	this->_darkestSecret = darkestSecret;
	this->_index = index;
	this->_isEmpty = false;
}

/*
** Stampa l'intestazione della tabella dei contatti.
** Le colonne (Index, First Name, Last Name, Nickname)
** sono allineate a larghezza fissa (10 caratteri).
*/
void	Contact::showTitle(void) const
{
	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
}

/*
** Stampa una riga della tabella con i dati principali
** del contatto (indice, nome, cognome, nickname).
** Ogni campo è formattato con 10 caratteri massimi,
** usando la funzione tenchar() per gestire testi lunghi.
** Se il contatto è vuoto (_isEmpty = true), non stampa nulla.
*/
void	Contact::showRow(void) const
{
	if (this->_isEmpty)
		return ;
	std::cout << "|" << std::setw(10) << this->_index << "|";
	std::cout << std::setw(10) << this->tenchar(this->_firstName) << "|";
	std::cout << std::setw(10) << this->tenchar(this->_lastName) << "|";
	std::cout << std::setw(10) << this->tenchar(this->_nickName) << "|" << std::endl;
}

/*
** Mostra tutte le informazioni del contatto in formato
** descrittivo (nome, cognome, nickname, telefono, segreto).
** Se il contatto è vuoto (_isEmpty = true), stampa un
** messaggio "Contact is empty" e termina la funzione.
*/
void	Contact::showAll(void) const
{
	if (this->_isEmpty)
	{
		std::cout << "Contact is empty" << std::endl;
		return ;
	}
	std::cout << "First Name: " << this->_firstName << std::endl;
	std::cout << "Last Name: " << this->_lastName << std::endl;
	std::cout << "Nickname: " << this->_nickName << std::endl;
	std::cout << "Phone Number: " << this->_phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << this->_darkestSecret << std::endl;
}

/*
** Restituisce la stringa text adattata a 10 caratteri.
** - Se text è lunga ≤ 10, viene restituita invariata.
** - Se supera 10 caratteri, viene troncata a 9 e
**   completata con '.' per indicare il taglio.
** Usata per mantenere l'allineamento tabellare.
*/
std::string Contact::tenchar(std::string text) const
{
	if (text.length() > 10)
		text = text.substr(0, 9) + ".";
	return (text);
}

/*
** Restituisce lo stato del flag _isEmpty.
** - true  → contatto vuoto o non inizializzato
** - false → contatto valido con dati salvati
*/
bool	Contact::isEmpty(void) const
{
	return (this->_isEmpty);
}

