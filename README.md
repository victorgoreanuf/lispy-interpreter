Lispy: A Simple Lisp Interpreter in C 🚀
Welcome to Lispy, a lightweight Lisp interpreter crafted in C during my internship at SPARK SOLUTION S.R.L. as part of my studies in Web Application Administration at the Center of Excellence in Informatics and Information Technologies (Republic of Moldova). This project brings the elegance of Lisp to life with a focus on S-expressions, functional programming, and recursion (think Fibonacci!). Powered by the Micro Parser Combinator (MPC) library, Lispy is a fun way to dive into interpreter design.
Why Lispy? Lisp's minimalist yet powerful syntax makes it a perfect playground for learning parsing, evaluation, and low-level C programming. Check out my full internship report here for the behind-the-scenes story! 📖
Key Features 🌟

Arithmetic Operations: Add, subtract, multiply, divide with ease (e.g., (+ 1 2) → 3).
List Manipulation: Functions like map, filter, and fold for powerful list processing.
Lambdas & Recursion: Define custom functions and compute things like (fib 10) → 55.
Standard Prelude: Load lib/library.lisp for a rich set of utilities (view it here).
Error Handling: Robust handling for invalid inputs, division by zero, and more.

Getting Started 🛠️
Prerequisites
To run Lispy, you'll need:

Compiler: GCC or Clang
Library: libedit (or readline on Linux) for the interactive REPL
Ubuntu: sudo apt-get install libedit-dev
macOS: brew install libedit
Windows: Use MinGW with libedit or a compatible setup

Make: For easy building with the provided Makefile
Dependencies: The MPC library (included as mpc.c and mpc.h)

Build Instructions
Lispy is split into multiple source files (main.c, lval.c, lenv.c, builtins.c, eval.c, read.c, mpc.c). Use the Makefile for a seamless build:
make
./lispy

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
