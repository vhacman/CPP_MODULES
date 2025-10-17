![Score](https://img.shields.io/badge/Score-100/100-brightgreen?style=for-the-badge)
[![42 Project](https://img.shields.io/badge/42%20Project-CPP00-blue?style=for-the-badge&logo=42)](https://github.com/vhacman/CPP01)
[![C++ Language](https://img.shields.io/badge/Made%20with-C++-00599C?style=for-the-badge&logo=c++)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Memory Leak Free](https://img.shields.io/badge/Valgrind-Leaks%20Free-success?style=for-the-badge)](https://valgrind.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-violet?style=for-the-badge)]()
[![License](https://img.shields.io/badge/license-42%20Project-informational?style=for-the-badge)]()
[![Status](https://img.shields.io/badge/42%20status-Completed-brightgreen?style=for-the-badge)]()
[![Created](https://img.shields.io/badge/Created-September_2025-blue?style=for-the-badge)]()


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

# EX02 – HI THIS IS BRAIN
## Pointers & References, indirizzi e valori

### Obiettivi
Questo esercizio completa il quadro iniziato con EX00/EX01 introducendo, in pratica, indirizzi di memoria, puntatori e reference. L’idea è vedere con mano che:

- Un puntatore contiene l’indirizzo di un oggetto e si dereferenzia con * per ottenerne il valore.

- Una reference è un alias dell’oggetto: non è null, non va dereferenziata e ha lo stesso indirizzo dell’oggetto referenziato.

- Stampando indirizzi e valori, capisci subito le differenze di rappresentazione e di utilizzo.

il `main` funge da laboratorio:
- HumanA con Weapon → sempre armato, l’arma può cambiare tipo e lui "vede" subito l’aggiornamento.
- HumanB con Weapon → inizialmente disarmato, poi riceve un’arma e la usa, con lo stesso comportamento reattivo ai cambiamenti.
- HumanB senza Weapon → dimostra che il puntatore può rimanere NULL e l’attacco si adatta.

---
# EX03 – Unnecessary Violence
## Pointers and References

## Obiettivi

Questo esercizio ha lo scopo di introdurre l’uso di:
  1. Reference: alias obbligatori e non nullabili per oggetti esistenti.
  2. Puntatori: variabili che possono contenere l’indirizzo di un oggetto o essere null.
  3. Const reference nei metodi: per restituire oggetti complessi evitando copie e senza rischi di modifica dall’esterno.
  4. Associazione vs Possesso: modellare correttamente le relazioni tra oggetti, distinguendo tra composizione, aggregazione e semplice associazione.

**L’esercizio dimostra come reference e puntatori influenzino la progettazione delle classi e il loro comportamento, attraverso il caso di HumanA e HumanB, entrambi collegati a un oggetto Weapon.**

## Sviluppo

Lo sviluppo del progetto si articola in più passaggi:

- Classe Weapon:
Contiene un attributo privato _type di tipo std::string.
Metodo getType() const: restituisce una const std::string& per
accedere al tipo senza creare copie.
Metodo setType(std::string newType): permette di modificare il tipo.

- Classe HumanA:
Possiede un attributo Weapon& (reference obbligatoria).
Il costruttore richiede sempre un’arma valida.
Metodo attack(): stampa un messaggio usando sempre l’arma,
senza controlli aggiuntivi, perché la reference garantisce validità.
- Classe HumanB:
Possiede un attributo Weapon* (puntatore opzionale).
Può essere inizialmente disarmato (nullptr).
Metodo setWeapon(Weapon&): consente di assegnare un’arma in un
secondo momento.
Metodo attack(): controlla se weapon è nullptr; in caso
positivo gestisce il caso disarmato.
main.cpp:
Dimostra la differenza tra HumanA e HumanB:
HumanA ha sempre un’arma, perché lavora con reference.

HumanB può essere disarmato, ma può ottenere o cambiare arma durante la vita del programma.
---
## Concetti chiave dimostrati

- Reference: obbligatorie, non possono essere nulle, garantiscono
stabilità del legame.

- Puntatori: opzionali, possono essere riassegnati, ma richiedono
controlli per evitare errori di dereferenziazione.

- Const correctness:
  - const & nei metodi per evitare copie inutili e proteggere l’incapsulamento.
  - Metodi dichiarati const per distinguere le operazioni di sola lettura da quelle che modificano lo stato interno.

- Associazione vs Possesso:
  - Né HumanA né HumanB possiedono l’oggetto Weapon, ma si limitano ad associarsi a esso.

- Polimorfismo statico:
  - Entrambi implementano attack() con la stessa interfaccia, ma comportamenti diversi, senza ricorrere a ereditarietà o metodi virtuali.

Perfetto! Ti preparo **EX04** in forma schematica, così è coerente con EX00–EX03 che hai già fatto.

---

# EX04 – Sed is for losers

## Obiettivi

Questo esercizio introduce la gestione dei file in C++ e la manipolazione
delle stringhe. L’obiettivo principale è:

* Aprire un file di input in sola lettura e crearne uno di output in scrittura.
* Leggere il contenuto riga per riga.
* Cercare e sostituire tutte le occorrenze di una sottostringa `s1` con `s2`.
* Scrivere il risultato in un nuovo file con estensione `.replace`.

L’esercizio vieta l’uso diretto di `std::string::replace`, per spingere
a implementare manualmente la logica di ricerca e sostituzione con
metodi come `find`, `erase`, `insert` e `substr`.

---

## Sviluppo

1. **Gestione dei file:**

   * Il programma riceve tre argomenti da riga di comando: nome file, `s1`, `s2`.
   * Usa `std::ifstream` per aprire il file di input.
   * Crea un nuovo file di output con `std::ofstream`, aggiungendo `.replace` al nome.
   * Controlla che i file siano aperti correttamente con `is_open()`.

2. **Elaborazione del contenuto:**

   * Legge il file riga per riga tramite `std::getline`.
   * Per ogni riga, cerca le occorrenze di `s1` con `find`.
   * Quando trova una corrispondenza, sostituisce manualmente con `s2`
     usando combinazioni di `erase` e `insert` oppure costruendo una nuova stringa.
   * Ripete fino a sostituire tutte le occorrenze nella riga.

3. **Scrittura nel file di output:**

   * Ogni riga elaborata viene scritta nel file `.replace`.
   * Al termine, gli stream vengono chiusi (automaticamente con RAII o manualmente con `close()`).

---

## Concetti chiave dimostrati

* Uso delle classi `std::ifstream` e `std::ofstream`.
* Controllo e gestione degli errori nell’apertura dei file.
* Lettura sequenziale di un file con `getline`.
* Ricerca e sostituzione di sottostringhe senza `replace`.
* Applicazione del RAII: i file vengono chiusi automaticamente alla fine dello scope.

---
# EX05 – Harl 2.0

## Obiettivi

Questo esercizio introduce l’uso dei **puntatori a funzioni membro** in C++.
L’obiettivo è automatizzare il comportamento della classe `Harl`, che deve
emettere diversi messaggi in base al livello di log (`DEBUG`, `INFO`,
`WARNING`, `ERROR`) senza ricorrere a catene di `if/else if/else`.

I punti chiave sono:

* Definire quattro metodi privati: `debug()`, `info()`, `warning()`, `error()`.
* Creare un metodo pubblico `complain(std::string level)` che, usando una
  tabella di puntatori a funzioni membro, richiama direttamente il metodo
  corrispondente al livello passato.
* Gestire il caso di livello non valido con un messaggio di fallback.

---

## Sviluppo

1. **Classe `Harl`:**

   * Contiene i quattro metodi privati corrispondenti ai livelli.
   * Implementa `complain(std::string level)` come interfaccia pubblica.
   * I metodi sono privati per forzare l’uso di `complain()` come unico punto di accesso.

2. **Tabella di puntatori a funzioni:**

   * Si crea un array di stringhe con i nomi dei livelli.
   * In parallelo, si definisce un array di puntatori a metodi membro
     che punta a `debug`, `info`, `warning`, `error`.
   * Un ciclo confronta la stringa passata con l’array dei livelli:
     quando trova corrispondenza, invoca il metodo corretto tramite
     `(this->*pointer)()`.

3. **Programma di test (`main.cpp`):**

   * Crea un’istanza di `Harl`.
   * Chiama `complain()` con tutti i livelli validi per dimostrare il funzionamento.
   * Chiama `complain()` con un livello non valido per verificare la gestione dell’errore.

---

## Concetti chiave dimostrati

* **Puntatori a funzioni membro:** tecnica per associare stringhe a metodi
  senza ricorrere a strutture condizionali annidate.
* **Incapsulamento:** i metodi di log rimangono privati, accessibili solo
  tramite l’interfaccia pubblica `complain()`.
* **Polimorfismo statico:** la scelta del metodo avviene a tempo di esecuzione
  in base al livello, senza uso di virtual o ereditarietà.
* **Gestione input non valido:** il programma non va in errore ma risponde con
  un messaggio guida.
---

# EX06 – Harl filter

## Obiettivi

Questo esercizio estende **Harl 2.0** introducendo un meccanismo di
**filtraggio dei livelli**.
L’obiettivo è simulare un logger più realistico: in base al livello
passato da riga di comando, Harl deve stampare **quel livello e tutti i
successivi** in ordine di gravità (`DEBUG`, `INFO`, `WARNING`, `ERROR`).

Se il livello non è riconosciuto, il programma deve stampare un
messaggio generico per indicare che il reclamo non rientra nei livelli
previsti.

---

## Sviluppo

1. **Classe `Harl`:**

   * Mantiene i quattro metodi privati già visti (`debug`, `info`,
     `warning`, `error`).
   * Il metodo `complain(std::string level)` diventa il punto centrale
     per selezionare il comportamento.

2. **Implementazione del filtro:**

   * Si crea un array con i livelli in ordine crescente di severità.
   * Si cerca la corrispondenza tra il livello passato e l’array.
   * Una volta trovato, vengono invocati **in cascata** tutti i metodi
     corrispondenti dal livello selezionato fino a `ERROR`.

3. **Gestione input non valido:**

   * Se il livello non corrisponde a nessuno dei valori attesi,
     viene stampato un messaggio di default:
     `"Probably complaining about insignificant problems"`.

4. **Programma di test (`main.cpp`):**

   * Legge l’argomento passato da riga di comando come livello.
   * Chiama `complain()` per stampare i messaggi filtrati.
   * Verifica sia il caso di livelli validi che di livello sconosciuto.

---

## Concetti chiave dimostrati

* **Filtraggio dei livelli di log:** simulazione di un logger reale,
  con output crescente in base alla severità.
* **Riutilizzo del codice di EX05:** uso dei puntatori a funzioni
  membro per evitare `if/else` complessi.
* **Gestione robusta degli input:** comportamento definito anche in
  caso di livello non valido.
* **Astrazione crescente:** da EX05 a EX06 si passa da un semplice
  dispatcher a un sistema di log con filtro di severità.

---
