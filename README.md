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


# EX01 – More Brainz

## Obiettivi
Questo esercizio estende il lavoro di **EX00** con un nuovo obiettivo:
gestire **un array dinamico di oggetti**.
Si tratta di un passo avanti importante perché permette di capire:
- Come funziona l’allocazione dinamica di **array di oggetti** con `new[]`.
- Come usare un **costruttore di default** per creare oggetti senza
parametri.
- Come assegnare successivamente valori agli attributi usando metodi
setter (`setName`).
- Come assicurarsi di liberare la memoria con `delete[]` per evitare
**memory leaks**.

---

## Sviluppo
Il progetto è stato sviluppato seguendo questi passaggi:

1. **Estensione della classe `Zombie`:**
   - Aggiunto il metodo `setName(std::string name)` per rinominare
     gli zombie creati con il costruttore di default.
   - La classe mantiene il metodo `announce()` e il distruttore che
     stampa un messaggio alla distruzione.

2. **Funzione `zombieHorde(int N, std::string name)`:**
   - Alloca dinamicamente un array di `N` oggetti `Zombie` su heap
     (`new Zombie[N]`).
   - Ogni oggetto è inizialmente creato con il costruttore di default.
   - Per ciascun elemento, costruisce un nome univoco concatenando
     la stringa base con l’indice (es. `"Zombie 1"`, `"Zombie 2"`).
   - Assegna il nome tramite `setName()` e chiama subito `announce()`.
   - Restituisce il puntatore al primo elemento dell’array.

3. **Funzione `main()`:**
   - Crea un horde di 10 zombie tramite `zombieHorde(10, "Zombie")`.
   - Se l’allocazione fallisce, termina il programma.
   - Dopo l’uso, libera la memoria con `delete[]`.

---
# EX03 – Unnecessary Violence 
## Pointers and References

## Obiettivi

Questo esercizio ha lo scopo di introdurre l’uso di: 
  1. Reference: alias obbligatori e non nullabili per oggetti esistenti.
  2. Puntatori: variabili che possono contenere l’indirizzo di un oggetto o essere null.
  3. Const reference nei metodi: per restituire oggetti complessi evitando copie e senza rischi di modifica dall’esterno.

Associazione vs Possesso: modellare correttamente le relazioni tra
oggetti, distinguendo tra composizione, aggregazione e semplice associazione.

L’esercizio dimostra come reference e puntatori influenzino la progettazione
delle classi e il loro comportamento, attraverso il caso di HumanA e
HumanB, entrambi collegati a un oggetto Weapon.

## sviluppo
 Lo sviluppo del progetto si articola in più passaggi:

Classe Weapon:

Contiene un attributo privato _type di tipo std::string.

Metodo getType() const: restituisce una const std::string& per
accedere al tipo senza creare copie.

Metodo setType(std::string newType): permette di modificare il tipo.

Classe HumanA:

Possiede un attributo Weapon& (reference obbligatoria).

Il costruttore richiede sempre un’arma valida.

Metodo attack(): stampa un messaggio usando sempre l’arma,
senza controlli aggiuntivi, perché la reference garantisce validità.

Classe HumanB:

Possiede un attributo Weapon* (puntatore opzionale).

Può essere inizialmente disarmato (nullptr).

Metodo setWeapon(Weapon&): consente di assegnare un’arma in un
secondo momento.

Metodo attack(): controlla se weapon è nullptr; in caso
positivo gestisce il caso disarmato.

main.cpp:

Dimostra la differenza tra HumanA e HumanB:

HumanA ha sempre un’arma, perché lavora con reference.

HumanB può essere disarmato, ma può ottenere o cambiare arma
durante la vita del programma.
---

