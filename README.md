# EX00 – BraiiiiiiinnnzzzZ

## Obiettivi
Questo primo esercizio ha lo scopo di introdurre i concetti
fondamentali della programmazione a oggetti in C++ e della gestione
della memoria.  
L’obiettivo principale è comprendere la differenza tra:
- **Allocazione dinamica (heap):** gli oggetti creati con `new`
  persistono oltre lo scope e devono essere liberati manualmente
  con `delete`.
- **Allocazione automatica (stack):** gli oggetti locali vengono
  creati e distrutti automaticamente al termine dello scope, senza
  bisogno di intervento esplicito.

Attraverso la classe `Zombie`, l’esercizio mostra il ciclo di vita
di un oggetto: costruzione, utilizzo e distruzione, con particolare
attenzione al ruolo di costruttori e distruttore.

## Sviluppo
Lo sviluppo del progetto si articola in più passaggi:

1. **Definizione della classe `Zombie`:**
   - Attributo privato `_name` per il nome.
   - Costruttori (default e parametrico) per inizializzare gli oggetti.
   - Metodo pubblico `announce()` per stampare un messaggio.
   - Distruttore che notifica la distruzione dell’oggetto.

2. **Funzioni helper:**
   - `newZombie(name)`: crea uno zombie su heap e restituisce un
     puntatore all’oggetto.
   - `randomChump(name)`: crea uno zombie su stack, lo fa annunciare
     subito e lascia che venga distrutto automaticamente.

3. **Dimostrazione in `main.cpp`:**
   - Creazione di uno zombie su heap tramite `new`.
   - Annuncio dello zombie e distruzione esplicita con `delete`.
   - Creazione temporanea di uno zombie su stack tramite
     `randomChump()`.
