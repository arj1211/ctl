#include "lexer.h"
#include "token.h"
#include <assert.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void lexer_init(Lexer *lexer, const char *source) {
  lexer->src = source;
  lexer->pos = 0;
  lexer->line = 1;
  lexer->column = 1;
}

static char peek(Lexer *l) { return l->src[l->pos]; }

static char isEOF(char c) { return c == '\0'; }

static bool isCommentStart(char c) { return c == '@'; }

static char advance(Lexer *l) {
  char c = l->src[l->pos++];
  if (c == '\n') {
    l->line++;
    l->column = 1;
  } else {
    l->column++;
  }
  return c;
}

static void skipComment(Lexer *l) {
  assert(isCommentStart(peek(l)));
  /* keep advancing if
  - current char is NOT \n
  - current char is NOT EOF
  */
  while ((peek(l) != '\n') && !isEOF(peek(l)))
    advance(l);
}

static Token make_token(Lexer *l, TokenType type, const char *start,
                        int length) {
  Token t;
  t.type = type;
  t.lexeme = strndup(start, length);
  t.line = l->line;
  t.column = l->column;
  return t;
}

static Token make_simple(Lexer *l, TokenType type) {
  return make_token(l, type, l->src + l->pos - 1, 1);
}

Token lexer_next_token(Lexer *l) {
  while (isspace(peek(l)))
    advance(l);

  // if we're at a comment, skip till non-whitespace, non-comment or till EOF
  while (isCommentStart(peek(l)) && !isEOF(peek(l))) {
    skipComment(l);
    while (isspace(peek(l)))
      advance(l);
  }

  char c = peek(l);
  if (isEOF(c))
    return make_token(l, T_EOF, "", 0);

  if (isdigit(c)) {
    int start = l->pos;
    while (isdigit(peek(l)))
      advance(l);
    if (peek(l) == '.') {
      advance(l);
      while (isdigit(peek(l)))
        advance(l);
    }
    return make_token(l, T_NUMBER, l->src + start, l->pos - start);
  }
  if (isalpha(c)) {
    advance(l);
    return make_simple(l, T_LETTER);
  }

  switch (advance(l)) {
  case ':':
    return make_simple(l, T_COLON);
  case '[':
    return make_simple(l, T_LBRACK);
  case ']':
    return make_simple(l, T_RBRACK);
  case '(':
    return make_simple(l, T_LPAREN);
  case ')':
    return make_simple(l, T_RPAREN);
  case ',':
    return make_simple(l, T_COMMA);
  case '.':
    return make_simple(l, T_DOT);
  case '+':
    return make_simple(l, T_PLUS);
  case '-':
    return make_simple(l, T_MINUS);
  case '*':
    return make_simple(l, T_STAR);
  case '/':
    return make_simple(l, T_SLASH);
  case '%':
    return make_simple(l, T_PERCENT);
  case '^':
    return make_simple(l, T_EXP);
  case '<':
    if (peek(l) == '<') {
      advance(l);
      return make_token(l, T_LSH, "<<", 2);
    } else if (peek(l) == '=') {
      advance(l);
      return make_token(l, T_LTE, "<=", 2);
    }
    return make_simple(l, T_LT);
  case '>':
    if (peek(l) == '>') {
      advance(l);
      return make_token(l, T_RSH, ">>", 2);
    } else if (peek(l) == '=') {
      advance(l);
      return make_token(l, T_GTE, ">=", 2);
    }
    return make_simple(l, T_GT);
  case '=':
    if (peek(l) == '=') {
      advance(l);
      return make_token(l, T_EQ, "==", 2);
    }
    break;
  case '!':
    if (peek(l) == '=') {
      advance(l);
      return make_token(l, T_NEQ, "!=", 2);
    }
    break;
  }

  return make_token(l, T_ERROR, l->src + l->pos - 1, 1);
}
