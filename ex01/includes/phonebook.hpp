/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:05:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 18:57:28 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "contact.hpp"

/*
** Classe PhoneBook
** Gestisce una rubrica a dimensione fissa (8 contatti).
** Usa inserimento circolare: quando la rubrica è piena, il contatto
** più vecchio viene sovrascritto dal nuovo.
** Fornisce funzioni per aggiungere, cercare e visualizzare contatti.
*/
class PhoneBook {
private:
	/*
	** Array fisso di contatti. La capacità è 8.
	** Gli slot non inizializzati sono marcati con _isEmpty nei Contact.
	*/
	Contact _contacts[8];

	/*
	** Indice di inserimento corrente (0..7). Avanza in modo circolare
	** ad ogni nuova aggiunta.
	*/
	int _currIdx;

	/*
	** Numero di contatti validi memorizzati (0..8). Non supera mai 8.
	*/
	int _totalContacts;

	/*
	** _getInput(prompt)
	** Legge una riga di input dall'utente mostrando il prompt dato.
	** Gestisce eventuali input vuoti riproponendo la richiesta se
	** necessario. Restituisce la stringa acquisita.
	*/
	std::string	_getInput(const std::string &prompt);

	/*
	** _isValidIdx(input, idx)
	** Verifica che 'input' rappresenti un indice valido di contatto.
	** Converte 'input' in intero e lo assegna a 'idx' se compreso
	** nell'intervallo dei contatti correnti (0.._totalContacts-1).
	** Restituisce true se valido, false altrimenti.
	*/
	bool	_isValidIdx(const std::string &input, int &idx);

	/*
	** readValidIdx()
	** Mostra il prompt e legge da stdin finché non ottiene un indice
	** valido (1.._totalContacts). Converte e restituisce l'indice
	** zero-based. In caso di EOF termina il programma.
	*/
	int	_readValidIdx(void);

public:
	/*Costruttore di default.*/
	PhoneBook();

	/*Distruttore.*/
	~PhoneBook();

	/*
	** Acquisisce i campi di un nuovo contatto dall'utente e lo salva
	** nello slot puntato da _currIdx. Aggiorna _currIdx in modo
	** circolare e incrementa _totalContacts fino al massimo di 8.
	*/
	void addContact(void);

	/*
	** Mostra l'elenco tabellare dei contatti, chiede un indice valido
	** e stampa tutti i dettagli del contatto selezionato.
	*/
	void searchContact(void);

	/*
	** showContactDetails(index)
	** Stampa i dettagli completi del contatto all'indice fornito
	** (zero-based). Presuppone che l'indice sia già stato validato.
	*/
	void showContactDetails(int index);

	/*
	** Stampa l'intestazione e una riga per ogni contatto valido,
	** formattando i campi a larghezza fissa per una tabella leggibile.
	*/
	void displayContacts(void);
};

#endif
