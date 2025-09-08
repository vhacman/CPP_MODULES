
![Score](https://img.shields.io/badge/Score-100/100-brightgreen?style=for-the-badge)
[![42 Project](https://img.shields.io/badge/42%20Project-Philo-blue?style=for-the-badge&logo=42)](https://github.com/vhacman/philo)
[![C Language](https://img.shields.io/badge/Made%20with-C-00599C?style=for-the-badge&logo=c++)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Memory Leak Free](https://img.shields.io/badge/Valgrind-Leaks%20Free-success?style=for-the-badge)](https://valgrind.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-violet?style=for-the-badge)]()
[![License](https://img.shields.io/badge/license-42%20Project-informational?style=for-the-badge)]()
[![Status](https://img.shields.io/badge/42%20status-Completed-brightgreen?style=for-the-badge)]()
[![Created](https://img.shields.io/badge/Created-September_2025-blue?style=for-the-badge)]()

# EX00 – Megaphone

## Obiettivi

Questo esercizio introduce i concetti di base del C++ attraverso un
programma molto semplice che lavora con **input da linea di comando** e
manipolazione di **stringhe e caratteri**.
L’obiettivo principale è:

* Familiarizzare con la struttura di un programma C++ minimale.
* Comprendere l’uso degli **argomenti di `main(int argc, char** argv)`**.
* Imparare a iterare sugli argomenti ricevuti e a trasformarli.
* Utilizzare le funzioni della libreria `<cctype>` (ad esempio
  `toupper`) per modificare il contenuto di una stringa.
* Gestire il caso in cui non vengano passati argomenti.

---

## Sviluppo

1. **Struttura del programma:**

   * Il file `megaphone.cpp` contiene la funzione `main`.
   * Gli argomenti vengono letti da `argc` (numero di argomenti)
     e `argv` (array di stringhe C).

2. **Comportamento:**

   * Se non viene passato alcun argomento, il programma stampa un
     messaggio predefinito (“*LOUD AND UNBEARABLE FEEDBACK NOISE*”).
   * Se ci sono argomenti, ognuno di essi viene letto carattere per
     carattere e convertito in maiuscolo tramite la funzione `toupper`.
   * Tutti i caratteri trasformati vengono stampati consecutivamente
     su `std::cout`.

---

## Concetti chiave dimostrati

* **Funzione `main(int argc, char** argv)`:** gestione degli argomenti
passati da linea di comando.
* **Manipolazione di caratteri con `<cctype>`:** uso di `toupper` per
trasformare i caratteri in maiuscolo.
* **Controllo del flusso:** distinzione tra il caso con argomenti e
senza argomenti.
* **Input/Output in C++:** utilizzo di `std::cout` per la stampa a
schermo.

---

# EX01 – My Awesome PhoneBook

## Obiettivi

Questo esercizio introduce la programmazione a oggetti in C++ con un
progetto semplice ma completo: un **PhoneBook interattivo**.
L’obiettivo principale è:

* Definire e usare classi (`Contact` e `PhoneBook`) con attributi e metodi.
* Gestire input e output da terminale.
* Imparare a separare la logica in più file sorgente.
* Prendere dimestichezza con array statici, iterazioni e gestione di dati
  persistenti in memoria durante l’esecuzione del programma.

---

## Sviluppo

1. **Classe `Contact`:**
   * Contiene le informazioni di un contatto (nome, cognome, nickname,
     numero di telefono, segreto più oscuro).
   * Espone metodi per settare i dati e recuperarli.
   * Include funzioni di visualizzazione per mostrare i dati in forma breve
     (tabellare) o dettagliata.

2. **Classe `PhoneBook`:**
   * Gestisce un array circolare di massimo 8 contatti.
   * Implementa la logica per aggiungere un nuovo contatto (sovrascrivendo
     il più vecchio quando l’array è pieno).
   * Permette di cercare e visualizzare un contatto tramite indice.
   * Espone funzioni di input e output per dialogare con l’utente.

3. **Gestione dell’input:**
   * L’utente interagisce digitando comandi (`ADD`, `SEARCH`, `EXIT`).
   * In caso di `ADD`, vengono richiesti e salvati i dati del contatto.
   * In caso di `SEARCH`, vengono mostrati tutti i contatti in tabella,
     e l’utente può scegliere un indice per visualizzare i dettagli.
   * In caso di `EXIT`, il programma termina.

4. **Struttura del progetto:**
   * File separati per ogni parte: definizioni di classe (`.hpp`), metodi
     (`.cpp`), logica di input/output, e `main.cpp` come punto di ingresso.
   * File `ansi_colors.hpp` per gestire la colorazione dell’output a terminale.

---

## Concetti chiave dimostrati

* **Classi e incapsulamento:** separazione tra attributi privati e metodi
  pubblici per proteggere i dati.
* **Array statici e logica circolare:** gestione di un numero limitato
  di elementi con sovrascrittura dei più vecchi.
* **Suddivisione in file:** organizzazione del codice in più moduli per
  migliorarne leggibilità e manutenibilità.
* **Gestione input da utente:** validazione dei dati inseriti e
  interazione tramite terminale.
* **Formattazione dell’output:** uso di manipolatori e colori ANSI per
  visualizzazioni più chiare.

---

# EX02 – My Account

## Obiettivi

Questo esercizio ha lo scopo di approfondire il concetto di
**programmazione a oggetti** in C++, introducendo l’uso di:

* **Variabili e metodi statici**, condivisi tra tutte le istanze della classe.
* **Gestione dello stato individuale e globale**: distinguere tra attributi
  relativi al singolo oggetto (saldo del conto) e quelli condivisi
  dall’intera classe (numero totale di conti, saldo cumulativo, numero
  di depositi e prelievi globali).
* **Funzioni di logging**: registrare e mostrare lo stato di un oggetto o
  dell’intero sistema attraverso stampe formattate.
* **Costruttori e distruttori**: inizializzare correttamente un oggetto
  con valori di default o parametri e liberare le risorse al termine
  del ciclo di vita.

---

## Contesto narrativo

La storia di questo esercizio è ambientata nel tuo primo giorno di lavoro
presso **GlobalBanksters United**.
A causa di un errore, un file sorgente (`Account.cpp`) è stato cancellato,
e i colleghi non usano Git per versionare il codice.
Il tuo compito è ricostruire il file mancante basandoti su
`Account.hpp`, su `tests.cpp` e su un **log file** che mostra l’output
atteso del programma.

L’esercizio quindi unisce la pratica della programmazione con un
approccio di “reverse engineering” basato sui test e sui log.

---

## Sviluppo

1. **Classe `Account`:**

   * Attributi privati: includono il numero del conto, il saldo
     individuale, il numero di depositi e di prelievi.
   * Attributi statici: tracciano il numero totale di conti, il deposito
     complessivo e i prelievi complessivi.
   * Costruttore: inizializza un nuovo conto con un deposito iniziale,
     aggiornando le variabili statiche globali.
   * Distruttore: notifica la chiusura del conto e aggiorna i valori
     globali.

2. **Metodi principali:**

   * `makeDeposit(int amount)`: aggiunge denaro al conto e aggiorna i totali.
   * `makeWithdrawal(int amount)`: effettua un prelievo, se possibile,
     aggiornando i dati.
   * `checkAmount() const`: restituisce il saldo del conto.
   * `displayStatus() const`: mostra le informazioni di un singolo conto.
   * Metodi statici (`displayAccountsInfos`, `getNbAccounts`, ecc.):
     forniscono una panoramica dello stato globale di tutti i conti.

3. **Programma di test fornito (`tests.cpp`):**

   * Crea più oggetti `Account` con depositi iniziali differenti.
   * Esegue depositi e prelievi su vari conti.
   * Mostra lo stato sia dei singoli conti sia dell’intero insieme,
     evidenziando l’uso delle variabili statiche.

---

## Concetti chiave dimostrati

* **Differenza tra attributi d’istanza e attributi statici di classe.**
* **Controllo dello stato e logging** tramite metodi di stampa formattata.
* **Gestione del ciclo di vita degli oggetti** con costruttori e distruttori.
* **Uso dei metodi statici** per accedere a informazioni comuni a tutte le istanze.
* **Encapsulamento**: i dati sensibili (saldo, numero di operazioni)
  sono privati e modificabili solo attraverso metodi pubblici dedicati.

---
