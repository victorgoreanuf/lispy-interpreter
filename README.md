# Lispy: A Simple Lisp Interpreter in C

[![Build Status](https://github.com/goreanuvictor/lispy-interpreter/actions/workflows/ci.yml/badge.svg)](https://github.com/goreanuvictor/lispy-interpreter/actions)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![GitHub stars](https://img.shields.io/github/stars/goreanuvictor/lispy-interpreter.svg?style=social)](https://github.com/goreanuvictor/lispy-interpreter/stargazers)

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

- **Windows**: `gcc -std=c99 -Wall mpc.c src/lisp.c -o lispy.exe && lispy.exe`
- **Ubuntu/Linux**: `cc -std=c99 -Wall -ledit mpc.c src/lisp.c -o lispy && ./lispy`

Run in interactive mode: You'll see `lispy> ` prompt.

## Usage

### Interactive REPL

```bash
./lispy
lispy> (+ 1 2)
3
lispy> (fib 10)
55
lispy> (load "lib/library.lisp")  # Load standard prelude
lispy> (map (\ {x} {+ x 1}) {1 2 3})
{2 3 4}
```

### Running Scripts

Pass files as arguments:

```bash
./lispy lib/library.lisp tests/test.lisp
```

### Examples from Library

- Fibonacci: `(fib 5)` → 5
- List Ops: `(sum {1 2 3})` → 6
- See `lib/library.lisp` for full prelude (atoms, functions, logic, lists, etc.).

## Project Plan and Development

From my internship report ([docs/Raport.pdf](docs/Raport.pdf)):

1. **Objectives**: Build a functional Lisp interpreter.
2. **Tech Stack**: C for core, MPC for parsing.
3. **Error Handling**: Custom error types (e.g., invalid numbers).
4. **Testing**: Manual verification of scenarios like recursion and list ops.
5. **Optimization**: Used folds, recursion, and efficient list handling.

Full plan in the report's "Planul de dezvoltare" section.

## Testing

Manual testing was performed as described in the report:

- **Method**: Interactive REPL and script execution.
- **Scenarios**: Basic ops, errors, Fibonacci up to n=20.
- **Results**: All passed; see report for details.

Add your own tests in `tests/` and run via `./lispy tests/test.lisp`.

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines. Pull requests welcome!

## License

MIT License. See [LICENSE](LICENSE).

## Acknowledgments

- Internship mentors: Andrei Guzun (company) and Zavadschi Vitalie (school).
- Inspired by "Build Your Own Lisp" by Daniel Holden.

Star this repo if it impresses you! 🌟
