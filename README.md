# DFA-based-Password-Strength-Validator-

## Overview
A Password Strength Validator implemented in C using Deterministic Finite Automata (DFA) with Graphviz-based state transition visualization.
The validator analyzes a password by examining the presence of:

# Password Strength Validator using Deterministic Finite Automata (DFA)

## Overview

This project implements a Password Strength Validator using the concepts of **Deterministic Finite Automata (DFA)** from the Theory of Computation.

The system evaluates a password based on its composition and strength by analyzing:

* Uppercase letters
* Lowercase letters
* Digits
* Special characters
* Password length

Based on these characteristics, the password is classified as:

* Weak
* Secure
* Military Grade

The project also generates a visual DFA state transition diagram using **Graphviz**, allowing users to observe how the automaton processes each character of the password.

---

## Project Motivation

Password security is one of the most important aspects of modern cybersecurity. Weak passwords often lead to unauthorized access and security breaches.

This project demonstrates how theoretical concepts from Automata Theory can be applied to solve real-world security problems through password validation and state-based analysis.

---

## Features

### Password Analysis

The validator checks:

* Presence of uppercase letters (A–Z)
* Presence of lowercase letters (a–z)
* Presence of digits (0–9)
* Presence of special characters
* Minimum password length

### **Password Strength Classification**

| **Score Range** | **Classification** |
| ----------- | -------------- |
| Below 60    | Weak           |
| 60 – 84     | Secure         |
| 85 – 100    | Military Grade |

### **Password Improvement Suggestions**

The system suggests improvements such as:

* Add uppercase letters
* Add lowercase letters
* Add digits
* Add special characters
* Increase password length

### DFA Visualization

For every password entered:

1. State transitions are recorded.
2. A Graphviz DOT file is generated.
3. A DFA diagram is created automatically.
4. The diagram is displayed to the user.

---

## **Theory of Computation Concept**

This project is based on a Deterministic Finite Automaton (DFA).

### **Formal Definition**

M = (Q, Σ, δ, q₀, F)

Where:

* Q = Set of States
* Σ = Input Alphabet
* δ = Transition Function
* q₀ = Initial State
* F = Set of Accepting States

### **Input Categories**

| Symbol | Meaning           |
| ------ | ----------------- |
| U      | Uppercase Letter  |
| L      | Lowercase Letter  |
| D      | Digit             |
| S      | Special Character |

### **Acceptance Criteria**

A strong password should contain:

* At least one uppercase letter
* At least one lowercase letter
* At least one digit
* At least one special character
* Minimum length of 8 characters

---

## **Technologies Used**

* C Programming Language
* Theory of Computation (DFA)
* Graphviz
* Windows API
* Code::Blocks IDE

---

## **Project Structure**

Password-Strength-Validator-DFA/

├── src/

│   └── password_validator.c

├── screenshots/

│   ├── weak_case.png

│   ├── secure_case.png

│   ├── military_grade_case.png

│   └── dfa_diagram.png

├── docs/

│   └── TOC_Project_Report.pdf

├── README.md

├── LICENSE

└── .gitignore

---

## **Requirements**

### **Software**

* Code::Blocks IDE
* Graphviz
* Windows Operating System

### Graphviz Installation

Download Graphviz from:

https://graphviz.org/download/

Verify installation:

dot -V

---

## How to Run

### Using Code::Blocks

1. Open Code::Blocks.
2. Create a new Console Application (C).
3. Copy the source code into the project.
4. Build and Run using:

F9
or
Build → Build and Run

---

## Sample Inputs

### Weak Password

abc

### Secure Password

Password1

### Military Grade Password

Password@123

---

## Sample Output

<img width="566" height="290" alt="image" src="https://github.com/user-attachments/assets/f2986270-3c22-4128-a1af-babfc67a01c2" />
<img width="563" height="329" alt="image" src="https://github.com/user-attachments/assets/306c8985-e31c-4721-8996-dcadf138b0dd" />


---

## DFA State Diagram

The program automatically generates a DFA transition diagram using Graphviz.

Example:

* Input password characters are treated as input symbols.
* Each symbol causes a state transition.
* The final state determines password strength.

---

## Future Enhancements

* Dictionary-based password checking
* Entropy-based analysis
* Common password blacklist
* Pattern detection
* Cross-platform support
* GUI version using C++/Qt

---

## License

This project is licensed under the MIT License.

---

## Author

Developed as a Theory of Computation mini-project demonstrating the practical application of Deterministic Finite Automata in cybersecurity and password validation.
        
