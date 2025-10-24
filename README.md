![42 School](https://img.shields.io/badge/42%20School-CPP%20Modules-blue?style=for-the-badge&logo=42)
[![C++98](https://img.shields.io/badge/C++-98-00599C?style=for-the-badge&logo=c++)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-violet?style=for-the-badge)]()
[![Memory Leak Free](https://img.shields.io/badge/Valgrind-Leaks%20Free-success?style=for-the-badge)](https://valgrind.org/)

# CPP Modules

A comprehensive collection of C++ exercises from 42 School's curriculum, covering fundamental to advanced C++ programming concepts. 

## Table of Contents

- [Overview](#overview)
- [Requirements](#requirements)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Modules](#modules)
  - [CPP Module 00](#cpp-module-00)
  - [CPP Module 01](#cpp-module-01)
  - [CPP Module 02](#cpp-module-02)
- [Learning Objectives](#learning-objectives)
- [Resources](#resources)

## Overview

These modules are designed to introduce C++ programming from scratch, even for students with no prior C++ experience. Each module builds upon the previous one, progressively introducing more complex concepts while maintaining strict adherence to the C++98 standard.

## Requirements

- **Compiler:** `c++` with flags `-Wall -Wextra -Werror -std=c++98`
- **Platform:** Linux/Unix
- **Memory Leak Checker:** Valgrind (recommended)
- **Make:** GNU Make for building projects

### Compilation Rules

All projects follow these rules:
- Code must compile with C++98 standard
- No use of external libraries (except STL when permitted)
- No memory leaks allowed
- Code must follow the Orthodox Canonical Form (OCF) where applicable

## Project Structure

```
CPP_MODULES/
├── cpp00/          # Namespaces, classes, member functions, I/O streams
│   ├── ex00/       # Megaphone
│   ├── ex01/       # PhoneBook
│   ├── ex02/       # Account class
│   └── README.md
├── cpp01/          # Memory allocation, references, pointers, switch
│   ├── ex00/       # BraiiiiiiinnnzzzZ (Zombie)
│   ├── ex01/       # Moar brainz! (Zombie Horde)
│   ├── ex02/       # HI THIS IS BRAIN (References)
│   ├── ex03/       # Unnecessary violence (Weapon)
│   ├── ex04/       # Sed is for losers (File replacement)
│   ├── ex05/       # Harl 2.0
│   ├── ex06/       # Harl filter
│   └── README.md
├── cpp02/          # Ad-hoc polymorphism, operators, Orthodox Canonical Form
│   ├── ex00/       # Fixed-point number class (basic)
│   ├── ex01/       # Fixed-point with conversions
│   ├── ex02/       # Fixed-point with operator overloading
│   ├── ex03/       # BSP (Binary Space Partitioning)
│   └── README.md
└── README.md       # This file
```

## Compilation

Each exercise contains its own Makefile with standard rules:

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

Example usage:
```bash
cd cpp00/ex00
make
./megaphone "hello world"
```

## Modules

### CPP Module 00

**Focus:** Introduction to C++ basics, classes, and object-oriented programming fundamentals.

#### Exercises:
- **ex00 - Megaphone:** Command-line argument manipulation and string processing
- **ex01 - PhoneBook:** Interactive phonebook with classes, encapsulation, and array management
- **ex02 - Account:** Class implementation with static members and state management

[Detailed Module 00 README](cpp00/README.md)

### CPP Module 01

**Focus:** Memory allocation, pointers, references, and resource management.

#### Exercises:
- **ex00 - Zombie:** Stack vs heap allocation
- **ex01 - Zombie Horde:** Dynamic array allocation
- **ex02 - References:** Understanding references vs pointers
- **ex03 - Weapon:** Reference members in classes
- **ex04 - File Replacement:** File I/O and string manipulation
- **ex05 - Harl 2.0:** Pointers to member functions
- **ex06 - Harl Filter:** Switch statements and filtering

[Detailed Module 01 README](cpp01/README.md)

### CPP Module 02

**Focus:** Ad-hoc polymorphism, operator overloading, and Orthodox Canonical Form.

#### Exercises:
- **ex00 - Fixed:** Basic fixed-point number class
- **ex01 - Fixed with Conversions:** Type conversions and constructors
- **ex02 - Operator Overloading:** Comparison and arithmetic operators
- **ex03 - BSP:** Practical application with point-in-triangle algorithm

[Detailed Module 02 README](cpp02/README.md)

## Learning Objectives

### Module 00
- Understand basic C++ syntax and structure
- Learn class definition and implementation
- Master encapsulation and access control
- Work with input/output streams

### Module 01
- Master memory management (stack vs heap)
- Understand pointers and references
- Learn proper resource allocation and deallocation
- Implement pointers to member functions

### Module 02
- Implement the Orthodox Canonical Form
- Overload operators correctly
- Understand ad-hoc polymorphism
- Work with fixed-point arithmetic

## Resources

### Official Documentation
- [C++ Reference](https://en.cppreference.com/)
- [C++98 Standard](https://www.iso.org/standard/25845.html)

### Learning Materials
- [LearnCpp.com](https://www.learncpp.com/)
- [CPlusPlus.com Tutorial](http://www.cplusplus.com/doc/tutorial/)

### Memory Management
- [Valgrind Documentation](https://valgrind.org/docs/manual/quick-start.html)

### 42 School
- [42 Network](https://www.42network.org/)
- [42 Curriculum](https://meta.stackoverflow.com/questions/251597/are-questions-about-exercises-on-42-school-off-topic)


## Author

**vhacman** - 42 School Student

## License

This project is part of the 42 School curriculum and is intended for educational purposes.
