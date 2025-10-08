// File: main.c
#include "lisp.h"
#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
static char buffer[2048];

/**
 * Windows-compatible readline function.
 * @param prompt The prompt to display.
 * @return The input string.
 */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer) + 1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy) - 1] = '\0';
  return cpy;
}

/**
 * Stub for add_history on Windows.
 */
void add_history(char* unused) {}
#endif

/* Global Parser Definitions */
mpc_parser_t* Number;
mpc_parser_t* Symbol;
mpc_parser_t* String;
mpc_parser_t* Comment;
mpc_parser_t* Sexpr;
mpc_parser_t* Qexpr;
mpc_parser_t* Expr;
mpc_parser_t* Lispy;

/**
 * Main entry point.
 * Handles interactive REPL or file loading.
 */
int main(int argc, char** argv) {
  /* Create Parsers */
  Number = mpc_new("number");
  Symbol = mpc_new("symbol");
  String = mpc_new("string");
  Comment = mpc_new("comment");
  Sexpr = mpc_new("sexpr");
  Qexpr = mpc_new("qexpr");
  Expr = mpc_new("expr");
  Lispy = mpc_new("lispy");

  /* Define Language Grammar */
  mpca_lang(MPCA_LANG_DEFAULT,
            "number  : /-?[0-9]+/ ; "
            "symbol  : /[a-zA-Z0-9_+\\-*\\/\\\\=<>!&]+/ ; "
            "string  : /\"(\\\\.|[^\"])*\"/ ; "
            "comment : /;[^\\r\\n]*/ ; "
            "sexpr   : '(' <expr>* ')' ; "
            "qexpr   : '{' <expr>* '}' ; "
            "expr    : <number> | <symbol> | <string> | <comment> | <sexpr> | <qexpr> ; "
            "lispy   : /^/ <expr>* /$/ ;",
            Number, Symbol, String, Comment, Sexpr, Qexpr, Expr, Lispy);

  /* Create Environment */
  lenv* e = lenv_new();
  lenv_add_builtins(e);

  /* Interactive REPL Mode */
  if (argc == 1) {
    puts("Lispy Version 0.0.0.1.0");
    puts("Press Ctrl+c to Exit\n");

    while (1) {
      char* input = readline("lispy> ");
      add_history(input);

      mpc_result_t r;
      if (mpc_parse("<stdin>", input, Lispy, &r)) {
        lval* x = lval_eval(e, lval_read(r.output));
        lval_println(x);
        lval_del(x);
        mpc_ast_delete(r.output);
      } else {
        mpc_err_print(r.error);
        mpc_err_delete(r.error);
      }
      free(input);
    }
  }

  /* File Loading Mode */
  if (argc >= 2) {
    for (int i = 1; i < argc; i++) {
      lval* args = lval_add(lval_sexpr(), lval_str(argv[i]));
      lval* x = builtin_load(e, args);
      if (x->type == LVAL_ERR) lval_println(x);
      lval_del(x);
    }
  }

  /* Cleanup */
  lenv_del(e);
  mpc_cleanup(8, Number, Symbol, String, Comment, Sexpr, Qexpr, Expr, Lispy);
  return 0;
}