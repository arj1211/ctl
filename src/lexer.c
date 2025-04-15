#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

void lexer_init(Lexer *lexer, const char *source)
{
    lexer->src = source;
    lexer->pos = 0;
    lexer->line = 1;
    lexer->column = 1;
}

static char peek(Lexer *l)
{
    return l->src[l->pos];
}

static char advance(Lexer *l)
{
    char c = l->src[l->pos++];
    if (c == '\n')
    {
        l->line++;
        l->column = 1;
    }
    else
    {
        l->column++;
    }
    return c;
}

static Token make_token(Lexer *l, TokenType type, const char *start, int length)
{
    Token t;
    t.type = type;
    t.lexeme = strndup(start, length);
    t.line = l->line;
    t.column = l->column;
    return t;
}

static Token make_simple(Lexer *l, TokenType type)
{
    return make_token(l, type, l->src + l->pos - 1, 1);
}

Token lexer_next_token(Lexer *l)
{
    while (isspace(peek(l)))
        advance(l);

    char c = peek(l);
    if (c == '\0')
        return make_token(l, T_EOF, "", 0);

    if (isalpha(c))
    {
        int start = l->pos;
        while (isalnum(peek(l)) || peek(l) == '_')
            advance(l);
        int len = l->pos - start;
        const char *word = l->src + start;

        if (strncmp(word, "output", 6) == 0 && peek(l) == ':')
        {
            advance(l);
            return make_token(l, T_OUTPUT, word, len + 1);
        }

        return make_token(l, T_IDENT, word, len);
    }

    if (isdigit(c))
    {
        int start = l->pos;
        while (isdigit(peek(l)))
            advance(l);
        if (peek(l) == '.')
        {
            advance(l);
            while (isdigit(peek(l)))
                advance(l);
        }
        return make_token(l, T_NUMBER, l->src + start, l->pos - start);
    }

    switch (advance(l))
    {
    case '[':
        return make_simple(l, T_LBRACK);
    case ']':
        return make_simple(l, T_RBRACK);
    case '{':
        return make_simple(l, T_LBRACE);
    case '}':
        return make_simple(l, T_RBRACE);
    case ':':
        return make_simple(l, T_COLON);
    case ',':
        return make_simple(l, T_COMMA);
    case '|':
        return make_simple(l, T_PIPE);
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
    case '=':
        if (peek(l) == '=')
        {
            advance(l);
            return make_token(l, T_EQ, "==", 2);
        }
        break;
    case '!':
        if (peek(l) == '=')
        {
            advance(l);
            return make_token(l, T_NEQ, "!=", 2);
        }
        break;
    case '<':
        if (peek(l) == '=')
        {
            advance(l);
            return make_token(l, T_LTE, "<=", 2);
        }
        return make_simple(l, T_LT);
    case '>':
        if (peek(l) == '=')
        {
            advance(l);
            return make_token(l, T_GTE, ">=", 2);
        }
        return make_simple(l, T_GT);
    }

    return make_token(l, T_ERROR, l->src + l->pos - 1, 1);
}
