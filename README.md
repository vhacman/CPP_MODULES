![Score](https://img.shields.io/badge/Score-100/100-brightgreen?style=for-the-badge)
[![42 Project](https://img.shields.io/badge/42%20Project-CPP02-blue?style=for-the-badge&logo=42)](https://github.com/vhacman/CPP01)
[![C++ Language](https://img.shields.io/badge/Made%20with-C++-00599C?style=for-the-badge&logo=c++)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Memory Leak Free](https://img.shields.io/badge/Valgrind-Leaks%20Free-success?style=for-the-badge)](https://valgrind.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-violet?style=for-the-badge)]()
[![License](https://img.shields.io/badge/license-42%20Project-informational?style=for-the-badge)]()
[![Status](https://img.shields.io/badge/42%20status-Completed-brightgreen?style=for-the-badge)]()
[![Created](https://img.shields.io/badge/Created-September_2025-blue?style=for-the-badge)]()

# CPP Module 02 - Numeri a Virgola Fissa (Fixed-Point Numbers)

## Descrizione

Questo modulo esplora il concetto dei **numeri a virgola fissa** (fixed-point numbers) in C++, un'alternativa ai numeri in virgola mobile (floating-point) utile quando si necessita di rappresentazioni numeriche precise e deterministiche.

## Esercizi

### Ex00:

**Obiettivo:** Implementare una classe `Fixed` che rappresenta un numero a virgola fissa.

**Caratteristiche:**
- Valore intero privato per memorizzare il numero in formato fixed-point
- Numero di bit frazionari costante: **8 bit**
- Implementazione della forma canonica ortodossa:
  - Costruttore di default
  - Costruttore di copia
  - Operatore di assegnazione
  - Distruttore

---

### Ex01:

**Obiettivo:** Estendere la classe `Fixed` con costruttori parametrizzati e funzioni di conversione.

**Nuove funzionalit�:**
- Costruttore che accetta un intero
- Costruttore che accetta un float
- Metodo `toInt()` - converte il valore fixed-point in intero
- Metodo `toFloat()` - converte il valore fixed-point in float
- Sovraccarico dell'operatore `<<` per l'output su stream

**Conversione:**
- **Da int a fixed-point:** `value << fractionalBits`
- **Da float a fixed-point:** `roundf(value * (1 << fractionalBits))`
- **Da fixed-point a float:** `fixedValue / (float)(1 << fractionalBits)`

---

### Ex02:

**Obiettivo:** Implementare operatori sovraccaricati per la classe `Fixed`.

**Operatori implementati:**

#### Operatori di Confronto
- `>` (maggiore di)
- `<` (minore di)
- `>=` (maggiore o uguale)
- `<=` (minore o uguale)
- `==` (uguale)
- `!=` (diverso)

#### Operatori Aritmetici
- `+` (addizione)
- `-` (sottrazione)
- `*` (moltiplicazione)
- `/` (divisione)

#### Operatori di Incremento/Decremento
- `++` (pre-incremento e post-incremento)
- `--` (pre-decremento e post-decremento)

#### Funzioni Statiche
- `min(a, b)` - ritorna il minore tra due numeri Fixed
- `max(a, b)` - ritorna il maggiore tra due numeri Fixed
- Versioni sia const che non-const

---

### Ex03: BSP (Binary Space Partitioning)

**Obiettivo:** Utilizzare la classe `Fixed` in un'applicazione pratica per determinare se un punto si trova all'interno di un triangolo.

**Classi implementate:**

#### Classe Point
Rappresenta un punto 2D con coordinate x e y come numeri Fixed.
- Attributi privati `const Fixed _x` e `const Fixed _y`
- Costruttori e forma canonica ortodossa
- Metodi getter `getX()` e `getY()`

#### Funzione bsp()
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```

**Algoritmo BSP:**
1. Calcola il prodotto vettoriale (cross product) tra il punto e ciascun lato del triangolo
2. Verifica se il punto giace su un bordo o vertice (ritorna `false`)
3. Controlla se tutti i prodotti vettoriali hanno lo stesso segno

**Logica:**
- Se un punto è **DENTRO** il triangolo, si trova dallo **stesso lato** rispetto a tutti e tre i lati
- Tutti i prodotti vettoriali avranno lo stesso segno (tutti positivi o tutti negativi)
- Se i segni sono misti, il punto è **FUORI**
- Se un valore è zero, il punto è su un bordo è considerato **FUORI**
---

## Concetti Chiave Appresi

### 1. Numeri a Virgola Fissa
- Rappresentazione di numeri decimali usando interi
- Precisione fissa e calcoli deterministici
- Trade-off tra range e precisione

### 2. Forma Canonica Ortodossa (Orthodox Canonical Form)
Ogni classe dovrebbe implementare:
- Costruttore di default
- Costruttore di copia
- Operatore di assegnazione
- Distruttore

### 3. Sovraccarico degli Operatori (Operator Overloading)
- Operatori di confronto
- Operatori aritmetici
- Operatori di incremento/decremento (pre e post)
- Operatori di stream

### 4. Membri Statici
- `static const` per valori condivisi tra tutte le istanze
- Funzioni statiche `min()` e `max()`

### 5. Const Correctness
- Metodi `const` che non modificano l'oggetto
- Parametri `const` per riferimenti
- Sovraccarico const/non-const

---

## Compilazione

Ogni esercizio include un Makefile con i seguenti target:

```bash
make        # Compila il progetto
make clean  # Rimuove file oggetto
make fclean # Rimuove file oggetto ed eseguibile
make re     # Ricompila tutto da zero
```

**Compilatore:** `c++`
**Flag:** `-Wall -Wextra -Werror -std=c++98`

---

## 👤 Autore
**vhacman**
- Github: [vhacman](https://github.com/vhacman)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)

## ⚖️ Licenza
Questo progetto fa parte del curriculum della 42 School. Si prega di fare riferimento alle loro linee guida per l'utilizzo e la distribuzione.

---

# Contatti
[![LinkedIn](https://img.shields.io/badge/LinkedIn-blue?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/viorica-gabriela-hacman-63a412267/)
[![Facebook](https://img.shields.io/badge/Facebook-1877F2?style=for-the-badge&logo=facebook&logoColor=white)](https://www.facebook.com/profile.php?id=100090802467237)
[![Instagram](https://img.shields.io/badge/Instagram-E4405F?style=for-the-badge&logo=instagram&logoColor=white)](https://www.instagram.com/vgabrielah_/)

---
