// File: read.c
#include "lisp.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * Read a number from an AST node.
 * @param t The AST node.
 * @return lval number or error.
 */
lval* lval_read_num(mpc_ast_t* t) {
  errno = 0;
  long x = strtol(t->contents, NULL, 10);
  return errno != ERANGE ? lval_num(x) : lval_err("Invalid Number.");
}

/**
 * Read a string from an AST node, unescaping.
 * @param t The AST node.
 * @return lval string.
 */
lval* lval_read_str(mpc_ast_t* t) {
  t->contents[strlen(t->contents) - 1] = '\0';
  char* unescaped = malloc(strlen(t->contents + 1) + 1);
  strcpy(unescaped, t->contents + 1);
  unescaped = mpcf_unescape(unescaped);
  lval* str = lval_str(unescaped);
  free(unescaped);
  return str;
}

/**
 * Read an lval from an AST node recursively.
 * @param t The AST node.
 * @return The parsed lval.
 */
lval* lval_read(mpc_ast_t* t) {
  if (strstr(t->tag, "number")) return lval_read_num(t);
  if (strstr(t->tag, "string")) return lval_read_str(t);
  if (strstr(t->tag, "symbol")) return lval_sym(t->contents);

  lval* x = NULL;
  if (strcmp(t->tag, ">") == 0) x = lval_sexpr();
  if (strstr(t->tag, "sexpr")) x = lval_sexpr();
  if (strstr(t->tag, "qexpr")) x = lval_qexpr();

  for (int i = 0; i < t->children_num; i++) {
    if (strcmp(t->children[i]->contents, "(") == 0) continue;
    if (strcmp(t->children[i]->contents, ")") == 0) continue;
    if (strcmp(t->children[i]->contents, "}") == 0) continue;
    if (strcmp(t->children[i]->contents, "{") == 0) continue;
    if (strcmp(t->children[i]->tag, "regex") == 0) continue;
    if (strstr(t->children[i]->tag, "comment")) continue;
    x = lval_add(x, lval_read(t->children[i]));
  }
  return x;
}