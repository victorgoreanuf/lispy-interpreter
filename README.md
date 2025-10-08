Lispy: A Lisp Interpreter in C
Overview
Lispy is a Lisp interpreter implemented in C, developed during an internship at SPARK SOLUTION S.R.L. as part of studies in Web Application Administration at the Center of Excellence in Informatics and Information Technologies, Republic of Moldova. It supports S-expression evaluation, functions, lists, and recursion, using the Micro Parser Combinator (MPC) library for parsing. The project demonstrates proficiency in low-level programming, error handling, and parser design. For a detailed report, see docs/Raport.pdf.
Features

Arithmetic operations (e.g., addition, subtraction).
List manipulation functions (e.g., map, filter, fold).
Lambda functions and recursive computations (e.g., Fibonacci).
Standard prelude in lib/library.lisp.
Custom error handling for invalid inputs.

Installation and Build
Prerequisites

Compiler: GCC or Clang.
Library: libedit (Linux: libedit-dev, macOS: install via brew install libedit).
Windows: MinGW with libedit support.
Make utility for building with the provided Makefile.

Build Instructions
The project comprises multiple source files (main.c, lval.c, lenv.c, builtins.c, eval.c, read.c, mpc.c). Use the provided Makefile to build:
make
./lispy

To remove build artifacts:
make clean

Manual compilation:

Linux/macOS:gcc -std=c99 -Wall main.c lval.c lenv.c builtins.c eval.c read.c mpc.c -ledit -lm -o lispy
./lispy

Windows (MinGW):gcc -std=c99 -Wall main.c lval.c lenv.c builtins.c eval.c read.c mpc.c -o lispy.exe
lispy.exe

Upon successful build, the interactive lispy> prompt will appear.
Usage
Interactive REPL
Launch the REPL to evaluate expressions:
./lispy
lispy> (+ 1 2)
3
lispy> (fib 10)
55
lispy> (load "lib/library.lisp")
lispy> (map (\ {x} {+ x 1}) {1 2 3})
{2 3 4}

Running Scripts
Execute Lisp scripts by passing file paths:
./lispy lib/library.lisp tests/test.lisp

Standard Prelude
The lib/library.lisp file provides built-in functions:

Fibonacci: (fib 5) → 5
List operations: (sum {1 2 3}) → 6
Additional utilities for logic and list manipulation.

Development
As outlined in docs/Raport.pdf:

Objective: Develop a functional Lisp interpreter to demonstrate C programming and parsing skills.
Technology: C for core logic, MPC for parsing S-expressions.
Error Handling: Custom types for errors like invalid numbers or unbound symbols.
Optimization: Utilizes folds and recursion for efficient evaluation.
Structure: Modular design with separate files for value handling, environment, builtins, evaluation, and parsing.

The full development plan is detailed in the "Planul de dezvoltare" section of the report.
Testing
Testing was conducted manually, as described in docs/Raport.pdf:

Method: REPL interaction and script execution.
Scenarios: Arithmetic operations, error handling, and recursive functions (e.g., Fibonacci up to n=20).
Results: All test cases passed.

To run custom tests, add scripts to the tests/ directory and execute:
./lispy tests/test.lisp

Contributing
Contributions are welcome. Refer to CONTRIBUTING.md for guidelines on submitting pull requests.
License
This project is licensed under the MIT License. See LICENSE for details.
Acknowledgments

Mentors: Andrei Guzun (SPARK SOLUTION S.R.L.) and Zavadschi Vitalie (CEITI).
Inspired by Daniel Holden's "Build Your Own Lisp."
