#include "ast.h"
#include <stdlib.h>
#include <string.h>

// Helper functions for dynamic arrays
static void ast_list_init(AstList *list) {
  list->items = NULL;
  list->len = 0;
  list->cap = 0;
}

static void ast_list_append(AstList *list, AstNode *node) {
  if (list->len >= list->cap) {
    list->cap = list->cap ? list->cap * 2 : 8;
    list->items = realloc(list->items, list->cap * sizeof(AstNode *));
  }
  list->items[list->len++] = node;
}

static void vector_init(Vector *vec) {
  vec->items = NULL;
  vec->len = 0;
  vec->cap = 0;
}

static void vector_append(Vector *vec, double num) {
  if (vec->len >= vec->cap) {
    vec->cap = vec->cap ? vec->cap * 2 : 8;
    vec->items = realloc(vec->items, vec->cap * sizeof(double));
  }
  vec->items[vec->len++] = num;
}

// Constructor functions
AstNode *ast_new_program(void) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_PROGRAM;
  ast_list_init(&node->as.statements);
  return node;
}

AstNode *ast_new_vector(double *numbers, size_t count) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_VECTOR;
  vector_init(&node->as.vector);
  for (size_t i = 0; i < count; i++) {
    vector_append(&node->as.vector, numbers[i]);
  }
  return node;
}

AstNode *ast_new_map(const char *binding, AstNode *expr) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_MAP;
  node->as.transform.binding = strdup(binding);
  node->as.transform.expr = expr;
  return node;
}

AstNode *ast_new_filter(const char *binding, AstNode *expr) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_FILTER;
  node->as.transform.binding = strdup(binding);
  node->as.transform.expr = expr;
  return node;
}

AstNode *ast_new_expand(const char *binding, AstNode **exprs, size_t count) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_EXPAND;
  node->as.expand.binding = strdup(binding);
  ast_list_init(&node->as.expand.exprs);
  for (size_t i = 0; i < count; i++) {
    ast_list_append(&node->as.expand.exprs, exprs[i]);
  }
  return node;
}

AstNode *ast_new_output(void) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_OUTPUT;
  return node;
}

AstNode *ast_new_binop(TokenType op, AstNode *left, AstNode *right) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_BINOP;
  node->as.operation.op = op;
  node->as.operation.left = left;
  node->as.operation.right = right;
  return node;
}

AstNode *ast_new_number(double value) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_NUMBER;
  node->as.number = value;
  return node;
}

AstNode *ast_new_var(const char *name) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_VAR;
  node->as.name = strdup(name);
  return node;
}

AstNode *ast_new_compare(TokenType op, AstNode *left, AstNode *right) {
  AstNode *node = calloc(1, sizeof(AstNode));
  node->type = AST_COMPARE;
  node->as.operation.op = op;
  node->as.operation.left = left;
  node->as.operation.right = right;
  return node;
}

// Memory management
void ast_free(AstNode *node) {
  if (!node)
    return;

  switch (node->type) {
  case AST_PROGRAM:
    for (size_t i = 0; i < node->as.statements.len; i++) {
      ast_free(node->as.statements.items[i]);
    }
    free(node->as.statements.items);
    break;

  case AST_VECTOR:
    free(node->as.vector.items);
    break;

  case AST_MAP:
  case AST_FILTER:
    free(node->as.transform.binding);
    ast_free(node->as.transform.expr);
    break;

  case AST_EXPAND:
    free(node->as.expand.binding);
    for (size_t i = 0; i < node->as.expand.exprs.len; i++) {
      ast_free(node->as.expand.exprs.items[i]);
    }
    free(node->as.expand.exprs.items);
    break;

  case AST_BINOP:
  case AST_COMPARE:
    ast_free(node->as.operation.left);
    ast_free(node->as.operation.right);
    break;

  case AST_VAR:
    free(node->as.name);
    break;

  default:
    break;
  }

  free(node);
}