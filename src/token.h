#ifndef TOKEN_H
#define TOKEN_H

typedef enum {
  T_LETTER,
  T_NUMBER,
  T_DOT,
  T_LBRACK,
  T_RBRACK,
  T_COLON,
  T_COMMA,
  T_PLUS,
  T_MINUS,
  T_STAR,
  T_SLASH,
  T_PERCENT,
  T_EXP,
  T_LSH,
  T_RSH,
  T_EQ,
  T_NEQ,
  T_LT,
  T_GT,
  T_LTE,
  T_GTE,
  T_LPAREN,
  T_RPAREN,
  T_EOF,
  T_ERROR
} TokenType;

typedef struct {
  TokenType type;
  char *lexeme;
  int line;
  int column;
} Token;

#endif
