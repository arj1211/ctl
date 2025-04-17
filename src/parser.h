#ifndef PARSER_H
#define PARSER_H

#include "ast.h"
#include "lexer.h"

typedef struct {
  Lexer *lexer;
  Token current;
  Token previous;
  bool had_error;
  const char *error_msg;
} Parser;

void parser_init(Parser *parser, Lexer *lexer);
AstNode *parse_program(Parser *parser);
bool parser_had_error(Parser *parser);
const char *parser_error_message(Parser *parser);

#endif
