# Lispy: A Simple Lisp Interpreter in C

## Overview

Lispy is a lightweight Lisp interpreter written in C, developed during my internship at **SPARK SOLUTION S.R.L.** as part of my studies in Web Application Administration at the Center of Excellence in Informatics and Information Technologies (Republic of Moldova). This project implements a basic S-expression evaluator with support for functions, lists, and recursion (e.g., Fibonacci). It's inspired by classic Lisp dialects and uses the Micro Parser Combinator (MPC) library for parsing.

Key highlights:

- **Internship Context**: Built to demonstrate low-level programming skills, error handling, and testing. See the full report in [docs/Raport.pdf](docs/Raport.pdf).
- **Why Lisp?** Lisp's simplicity and power make it ideal for exploring interpreters—perfect for learning about parsing, evaluation, and functional programming.
- **Features**: Arithmetic ops, list manipulation (e.g., `map`, `filter`, `fold`), lambdas, and a standard prelude (`lib/library.lisp`).

## Installation and Build

### Prerequisites

- GCC (or Clang) compiler
- On Linux: `libedit-dev` for readline support

### Build Instructions

From `docs/Run_Terminal.txt`:

> > > > > > > 3d3c3a8b36044f4a2888638b79bd9e2d78288ff2

Clean up build artifacts:
make clean

Manual Compilation (if you prefer):

Linux/macOS:gcc -std=c99 -Wall main.c lval.c lenv.c builtins.c eval.c read.c mpc.c -ledit -lm -o lispy
./lispy

Windows (MinGW):gcc -std=c99 -Wall main.c lval.c lenv.c builtins.c eval.c read.c mpc.c -o lispy.exe
lispy.exe

Once built, you'll see the interactive lispy> prompt. Ready to code? Let's go! 🎉
Usage Examples 💻
Interactive REPL
Jump into the REPL and try these:
./lispy
lispy> (+ 1 2)
3
lispy> (fib 10)
55
lispy> (load "lib/library.lisp") # Load the standard prelude
lispy> (map (\ {x} {+ x 1}) {1 2 3})
{2 3 4}

Running Scripts
Execute Lisp scripts directly:
./lispy lib/library.lisp tests/test.lisp

Library Highlights
Explore the standard prelude (lib/library.lisp) for goodies like:

Fibonacci: (fib 5) → 5
List Ops: (sum {1 2 3}) → 6
Logic & More: Atoms, conditionals, and advanced list functions

Project Plan 📋
As detailed in my internship report (docs/Raport.pdf):

Objective: Create a functional Lisp interpreter to showcase C programming and parsing skills.
Tech Stack: C for the core logic, MPC for parsing S-expressions.
Error Handling: Custom error types for invalid inputs (e.g., "Invalid Number").
Optimization: Efficient use of folds, recursion, and list operations.
Testing: Manual tests for arithmetic, recursion, and list ops.

Dive into the "Planul de dezvoltare" section of the report for the full scoop! 📝
Testing 🧪
Testing was conducted manually, as outlined in the report:

Method: REPL interaction and script execution.
Scenarios: Basic operations, error cases, and Fibonacci up to n=20.
Results: All tests passed—check the report for details!

Want to add your own tests? Drop them in the tests/ folder and run:
./lispy tests/test.lisp

Contributing 🤝
Love Lispy? Want to make it better? Check out the CONTRIBUTING.md for how to jump in. Pull requests are welcome! 🙌
License 📜
Lispy is released under the MIT License. Feel free to use, modify, and share!
Acknowledgments 🙏

Mentors: Big thanks to Andrei Guzun (SPARK SOLUTION S.R.L.) and Zavadschi Vitalie (school) for their guidance.
Inspiration: Built with love, inspired by Daniel Holden's "Build Your Own Lisp".

Star this repo if Lispy sparks joy! 🌟 GitHub Repo
