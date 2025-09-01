/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:08:49 by vhacman           #+#    #+#             */
/*   Updated: 2025/09/01 18:34:44 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

/*
** Classe Contact
** Rappresenta un singolo contatto della rubrica.
** Contiene dati anagrafici (nome, cognome, nickname), numero di telefono
** e un campo testuale libero (darkest secret).
** I campi _index e _isEmpty gestiscono posizione e stato di inizializzazione.
*/
class Contact {
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		int			_index;
		bool			_isEmpty;

	public:
		/*
		** Costruttore di default.
		** Inizializza i campi a valori di default e imposta _isEmpty a true
		** per segnalare che lo slot non contiene ancora un contatto valido.
		*/
		Contact();

		/*
		** Distruttore.
		** Non esegue operazioni particolari. Presente per completezza e per
		** mantenere interfaccia chiara e simmetrica alla fase di costruzione.
		*/
		~Contact();

		/*
		** saveContact(...)
		** Popola il contatto con i dati forniti e imposta l'indice.
		** Parametri:
		**  - firstName: nome
		**  - lastName: cognome
		**  - nickname: soprannome
		**  - phoneNumber: numero di telefono
		**  - darkestSecret: campo libero
		**  - index: posizione logica nella rubrica
		** Effetti:
		**  - assegna i campi interni
		**  - imposta _isEmpty a false
		*/
		void saveContact(std::string firstName, std::string lastName,
							std::string nickname, std::string phoneNumber,
							std::string darkestSecret, int index);

		/*
		** showTitle()
		** Stampa l'intestazione della tabella dei contatti (colonne allineate)
		** senza modificare lo stato dell'oggetto.
		*/
		void	showTitle(void) const;

		/*
		** showRow()
		** Stampa una riga tabellare con i campi principali del contatto:
		** indice, nome, cognome, nickname. Non altera lo stato interno.
		*/
		void	showRow(void) const;

		/*
		** showAll()
		** Stampa tutti i dettagli del contatto in formato leggibile
		** (nome, cognome, nickname, telefono, darkest secret).
		*/
		void	showAll() const;

		/*
		** tenchar(text)
		** Restituisce 'text' formattata a larghezza massima di 10 caratteri.
		** Se eccede, tronca a 9 e aggiunge un '.' finale per indicare taglio.
		** Utile per colonne a larghezza fissa in stampa tabellare.
		*/
		std::string	tenchar(std::string text) const;

		/*
		** isEmpty()
		** Ritorna true se il contatto non è stato inizializzato (slot libero),
		** false altrimenti.
		*/
		bool	isEmpty(void) const;
};

#endif
