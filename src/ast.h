#ifndef AST_H
#define AST_H

#include "token.h"
#include <stdbool.h>
#include <stddef.h>

typedef enum {
  AST_PROGRAM, // List of statements
  AST_VECTOR,  // Vector literal [1,2,3]
  AST_MAP,     // { x : expr }
  AST_FILTER,  // { x : bool_expr }
  AST_EXPAND,  // { [expr1,expr2] | x }
  AST_OUTPUT,  // output:
  AST_BINOP,   // Binary operations (+,-,*,/,%)
  AST_NUMBER,  // Numeric literal
  AST_VAR,     // Variable reference
  AST_COMPARE  // Comparison (==, !=, <, >, <=, >=)
} AstNodeType;

// Forward declaration for recursive types
typedef struct AstNode AstNode;

// Vector of AST nodes
typedef struct {
  AstNode **items;
  size_t len;
  size_t cap;
} AstList;

// Vector of numbers
typedef struct {
  double *items;
  size_t len;
  size_t cap;
} Vector;

struct AstNode {
  AstNodeType type;
  int line; // Source location for error reporting
  int column;

  union {
    // AST_PROGRAM
    AstList statements;

    // AST_VECTOR
    Vector vector;

    // AST_MAP, AST_FILTER
    struct {
      char *binding; // Variable name
      AstNode *expr; // Expression to evaluate
    } transform;

    // AST_EXPAND
    struct {
      AstList exprs; // List of expressions to output
      char *binding; // Input variable name
    } expand;

    // AST_BINOP, AST_COMPARE
    struct {
      AstNode *left;
      AstNode *right;
      TokenType op; // Operator type from token.h
    } operation;

    // AST_NUMBER
    double number;

    // AST_VAR
    char *name;
  } as;
};

// Constructor functions
AstNode *ast_new_program(void);
AstNode *ast_new_vector(double *numbers, size_t count);
AstNode *ast_new_map(const char *binding, AstNode *expr);
AstNode *ast_new_filter(const char *binding, AstNode *expr);
AstNode *ast_new_expand(const char *binding, AstNode **exprs, size_t count);
AstNode *ast_new_output(void);
AstNode *ast_new_binop(TokenType op, AstNode *left, AstNode *right);
AstNode *ast_new_number(double value);
AstNode *ast_new_var(const char *name);
AstNode *ast_new_compare(TokenType op, AstNode *left, AstNode *right);

// Memory management
void ast_free(AstNode *node);

#endif