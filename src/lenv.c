// File: lenv.c
#include "lisp.h"
#include <stdlib.h>
#include <string.h>

/**
 * Create a new empty environment.
 * @return Pointer to the new lenv.
 */
lenv* lenv_new(void) {
  lenv* e = malloc(sizeof(lenv));
  e->par = NULL;
  e->count = 0;
  e->syms = NULL;
  e->vals = NULL;
  return e;
}

/**
 * Delete an environment and free its resources.
 * @param e The lenv to delete.
 */
void lenv_del(lenv* e) {
  for (int i = 0; i < e->count; i++) {
    free(e->syms[i]);
    lval_del(e->vals[i]);
  }
  free(e->syms);
  free(e->vals);
  free(e);
}

/**
 * Create a copy of an environment.
 * @param e The lenv to copy.
 * @return Pointer to the copied lenv.
 */
lenv* lenv_copy(lenv* e) {
  lenv* n = malloc(sizeof(lenv));
  n->par = e->par;
  n->count = e->count;
  n->syms = malloc(sizeof(char*) * n->count);
  n->vals = malloc(sizeof(lval*) * n->count);
  for (int i = 0; i < e->count; i++) {
    n->syms[i] = malloc(strlen(e->syms[i]) + 1);
    strcpy(n->syms[i], e->syms[i]);
    n->vals[i] = lval_copy(e->vals[i]);
  }
  return n;
}

/**
 * Get the value bound to a symbol in the environment or its parents.
 * @param e The environment.
 * @param k The symbol lval.
 * @return Copy of the bound value or error if unbound.
 */
lval* lenv_get(lenv* e, lval* k) {
  for (int i = 0; i < e->count; i++) {
    if (strcmp(e->syms[i], k->sym) == 0) {
      return lval_copy(e->vals[i]);
    }
  }
  if (e->par) {
    return lenv_get(e->par, k);
  } else {
    return lval_err("Unbound Symbol '%s'", k->sym);
  }
}

/**
 * Bind a value to a symbol in the local environment.
 * @param e The environment.
 * @param k The symbol lval.
 * @param v The value lval.
 */
void lenv_put(lenv* e, lval* k, lval* v) {
  for (int i = 0; i < e->count; i++) {
    if (strcmp(e->syms[i], k->sym) == 0) {
      lval_del(e->vals[i]);
      e->vals[i] = lval_copy(v);
      return;
    }
  }
  e->count++;
  e->vals = realloc(e->vals, sizeof(lval*) * e->count);
  e->syms = realloc(e->syms, sizeof(char*) * e->count);
  e->vals[e->count - 1] = lval_copy(v);
  e->syms[e->count - 1] = malloc(strlen(k->sym) + 1);
  strcpy(e->syms[e->count - 1], k->sym);
}

/**
 * Bind a value to a symbol in the global environment.
 * @param e The environment (will traverse to root).
 * @param k The symbol lval.
 * @param v The value lval.
 */
void lenv_def(lenv* e, lval* k, lval* v) {
  while (e->par) {
    e = e->par;
  }
  lenv_put(e, k, v);
}