#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

static void advance(Parser *p) {
  p->previous = p->current;
  p->current = lexer_next_token(p->lexer);
}

static bool check(Parser *p, TokenType type) { return p->current.type == type; }

static bool match(Parser *p, TokenType type) {
  if (check(p, type)) {
    advance(p);
    return true;
  }
  return false;
}

static void error(Parser *p, const char *msg) {
  if (!p->had_error) {
    p->had_error = true;
    p->error_msg = msg;
  }
}

static void consume(Parser *p, TokenType type, const char *msg) {
  if (check(p, type)) {
    advance(p);
    return;
  }
  error(p, msg);
}

// Forward declarations for recursive descent
static AstNode *parse_statement(Parser *p);
static AstNode *parse_expression(Parser *p);
static AstNode *parse_term(Parser *p);
static AstNode *parse_factor(Parser *p);
static AstNode *parse_primary(Parser *p);

// Implementation of recursive descent parser
static AstNode *parse_vector_literal(Parser *p) {
  Vector vec = {0};
  vector_init(&vec);

  if (!match(p, T_LBRACK)) {
    error(p, "Expected '['");
    return NULL;
  }

  if (!check(p, T_RBRACK)) {
    do {
      if (check(p, T_NUMBER)) {
        advance(p);
        vector_append(&vec, atof(p->previous.lexeme));
      } else {
        error(p, "Expected number in vector literal");
        return NULL;
      }
    } while (match(p, T_COMMA));
  }

  consume(p, T_RBRACK, "Expected ']' after vector literal");
  return ast_new_vector(vec.items, vec.len);
}

static AstNode *parse_map_or_filter(Parser *p) {
  if (!match(p, T_LBRACE)) {
    error(p, "Expected '{'");
    return NULL;
  }

  // Parse binding
  if (!check(p, T_IDENT)) {
    error(p, "Expected identifier");
    return NULL;
  }
  char *binding = strdup(p->current.lexeme);
  advance(p);

  consume(p, T_COLON, "Expected ':' after binding");

  // Parse expression
  AstNode *expr = parse_expression(p);
  if (!expr)
    return NULL;

  consume(p, T_RBRACE, "Expected '}' after expression");

  // Determine if this is a map or filter based on expression type
  return (expr->type == AST_COMPARE) ? ast_new_filter(binding, expr)
                                     : ast_new_map(binding, expr);
}

static AstNode *parse_expand(Parser *p) {
  // Similar to parse_map_or_filter but handles vector expressions
  // Implementation left as an exercise
  return NULL;
}

static AstNode *parse_statement(Parser *p) {
  if (match(p, T_OUTPUT)) {
    consume(p, T_COLON, "Expected ':' after 'output'");
    return ast_new_output();
  }

  // Parse identifier and colon
  if (!check(p, T_IDENT)) {
    error(p, "Expected identifier");
    return NULL;
  }
  advance(p);

  consume(p, T_COLON, "Expected ':' after identifier");

  // Parse the rest based on what follows
  if (check(p, T_LBRACK)) {
    return parse_vector_literal(p);
  } else if (check(p, T_LBRACE)) {
    return parse_map_or_filter(p);
  }

  error(p, "Expected vector literal, map, filter, or expand expression");
  return NULL;
}

AstNode *parse_program(Parser *p) {
  AstNode *program = ast_new_program();

  advance(p); // Prime the parser

  while (!check(p, T_EOF)) {
    AstNode *stmt = parse_statement(p);
    if (stmt) {
      ast_list_append(&program->as.statements, stmt);
    }
    if (p->had_error)
      break;
  }

  return program;
}

void parser_init(Parser *p, Lexer *lexer) {
  p->lexer = lexer;
  p->had_error = false;
  p->error_msg = NULL;
}

bool parser_had_error(Parser *p) { return p->had_error; }

const char *parser_error_message(Parser *p) { return p->error_msg; }