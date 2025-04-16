#include "../../src/lexer.h"
#include "../../src/token.h"
#include <stdio.h>
#include <stdlib.h>

// Helper to convert TokenType to a string
static const char *token_type_to_string(TokenType type) {
  switch (type) {
  case T_IDENT:
    return "T_IDENT";
  case T_NUMBER:
    return "T_NUMBER";
  case T_LBRACK:
    return "T_LBRACK";
  case T_RBRACK:
    return "T_RBRACK";
  case T_LBRACE:
    return "T_LBRACE";
  case T_RBRACE:
    return "T_RBRACE";
  case T_COLON:
    return "T_COLON";
  case T_COMMA:
    return "T_COMMA";
  case T_PIPE:
    return "T_PIPE";
  case T_PLUS:
    return "T_PLUS";
  case T_MINUS:
    return "T_MINUS";
  case T_STAR:
    return "T_STAR";
  case T_SLASH:
    return "T_SLASH";
  case T_PERCENT:
    return "T_PERCENT";
  case T_EQ:
    return "T_EQ";
  case T_NEQ:
    return "T_NEQ";
  case T_LT:
    return "T_LT";
  case T_GT:
    return "T_GT";
  case T_LTE:
    return "T_LTE";
  case T_GTE:
    return "T_GTE";
  case T_LPAREN:
    return "T_LPAREN";
  case T_RPAREN:
    return "T_RPAREN";
  case T_OUTPUT:
    return "T_OUTPUT";
  case T_EOF:
    return "T_EOF";
  case T_ERROR:
    return "T_ERROR";
  default:
    return "UNKNOWN";
  }
}

int main(void) {
  // Read all of stdin into 'source'
  size_t cap = 1024, len = 0;
  char *source = malloc(cap);
  if (!source) {
    perror("malloc");
    return 1;
  }

  int ch;
  while ((ch = getchar()) != EOF) {
    if (len + 1 >= cap) {
      cap *= 2;
      source = realloc(source, cap);
      if (!source) {
        perror("realloc");
        return 1;
      }
    }
    source[len++] = (char)ch;
  }
  source[len] = '\0';

  // Now lex it
  printf("Lexing source:\n%s\n", source);
  Lexer lexer;
  lexer_init(&lexer, source);

  Token tok;
  do {
    tok = lexer_next_token(&lexer);
    printf("%-8s %-10s (line %d, col %d)\n", token_type_to_string(tok.type),
           tok.lexeme, tok.line, tok.column);
    free(tok.lexeme);
  } while (tok.type != T_EOF && tok.type != T_ERROR);

  free(source);
  return 0;
}