# Lexer Test Report

## Test: complex_pipeline.ctl

| Token Type | Lexeme | Line | Column |
|------------|---------|------|--------|
| T_IDENT | `input` | 1 | 6 |
| T_COLON | `:` | 1 | 9 |
| T_LBRACK | `[` | 1 | 12 |
| T_NUMBER | `1` | 1 | 13 |
| T_COMMA | `,` | 1 | 14 |
| T_NUMBER | `2` | 1 | 15 |
| T_COMMA | `,` | 1 | 16 |
| T_NUMBER | `3` | 1 | 17 |
| T_COMMA | `,` | 1 | 18 |
| T_NUMBER | `4` | 1 | 19 |
| T_COMMA | `,` | 1 | 20 |
| T_NUMBER | `5` | 1 | 21 |
| T_COMMA | `,` | 1 | 22 |
| T_NUMBER | `6` | 1 | 23 |
| T_COMMA | `,` | 1 | 24 |
| T_NUMBER | `7` | 1 | 25 |
| T_COMMA | `,` | 1 | 26 |
| T_NUMBER | `8` | 1 | 27 |
| T_COMMA | `,` | 1 | 28 |
| T_NUMBER | `9` | 1 | 29 |
| T_COMMA | `,` | 1 | 30 |
| T_NUMBER | `10` | 1 | 32 |
| T_RBRACK | `]` | 1 | 33 |
| T_IDENT | `map` | 2 | 4 |
| T_COLON | `:` | 2 | 9 |
| T_LBRACE | `{` | 2 | 12 |
| T_IDENT | `x` | 2 | 14 |
| T_COLON | `:` | 2 | 16 |
| T_LPAREN | `(` | 2 | 18 |
| T_IDENT | `x` | 2 | 19 |
| T_STAR | `*` | 2 | 21 |
| T_NUMBER | `2` | 2 | 23 |
| T_PLUS | `+` | 2 | 25 |
| T_NUMBER | `1` | 2 | 27 |
| T_RPAREN | `)` | 2 | 28 |
| T_SLASH | `/` | 2 | 30 |
| T_LPAREN | `(` | 2 | 32 |
| T_IDENT | `x` | 2 | 33 |
| T_MINUS | `-` | 2 | 35 |
| T_NUMBER | `1` | 2 | 37 |
| T_RPAREN | `)` | 2 | 38 |
| T_RBRACE | `}` | 2 | 40 |
| T_IDENT | `filter` | 3 | 7 |
| T_COLON | `:` | 3 | 9 |
| T_LBRACE | `{` | 3 | 12 |
| T_IDENT | `x` | 3 | 14 |
| T_COLON | `:` | 3 | 16 |
| T_IDENT | `x` | 3 | 18 |
| T_PERCENT | `%` | 3 | 20 |
| T_NUMBER | `2` | 3 | 22 |
| T_EQ | `==` | 3 | 25 |
| T_NUMBER | `0` | 3 | 27 |
| T_RBRACE | `}` | 3 | 29 |
| T_IDENT | `filter` | 4 | 7 |
| T_COLON | `:` | 4 | 9 |
| T_LBRACE | `{` | 4 | 12 |
| T_IDENT | `x` | 4 | 14 |
| T_COLON | `:` | 4 | 16 |
| T_IDENT | `x` | 4 | 18 |
| T_GT | `>` | 4 | 20 |
| T_NUMBER | `3` | 4 | 22 |
| T_RBRACE | `}` | 4 | 24 |
| T_IDENT | `expand` | 5 | 7 |
| T_COLON | `:` | 5 | 9 |
| T_LBRACE | `{` | 5 | 12 |
| T_LBRACK | `[` | 5 | 14 |
| T_IDENT | `x` | 5 | 16 |
| T_COMMA | `,` | 5 | 17 |
| T_IDENT | `x` | 5 | 19 |
| T_STAR | `*` | 5 | 21 |
| T_IDENT | `x` | 5 | 23 |
| T_COMMA | `,` | 5 | 24 |
| T_LPAREN | `(` | 5 | 26 |
| T_IDENT | `x` | 5 | 27 |
| T_STAR | `*` | 5 | 29 |
| T_NUMBER | `2` | 5 | 31 |
| T_PLUS | `+` | 5 | 33 |
| T_NUMBER | `1` | 5 | 35 |
| T_RPAREN | `)` | 5 | 36 |
| T_RBRACK | `]` | 5 | 38 |
| T_PIPE | `|` | 5 | 40 |
| T_IDENT | `x` | 5 | 42 |
| T_RBRACE | `}` | 5 | 44 |
| T_IDENT | `map` | 6 | 4 |
| T_COLON | `:` | 6 | 9 |
| T_LBRACE | `{` | 6 | 12 |
| T_IDENT | `x` | 6 | 14 |
| T_COLON | `:` | 6 | 16 |
| T_IDENT | `x` | 6 | 18 |
| T_MINUS | `-` | 6 | 20 |
| T_NUMBER | `5` | 6 | 22 |
| T_RBRACE | `}` | 6 | 24 |
| T_IDENT | `filter` | 7 | 7 |
| T_COLON | `:` | 7 | 9 |
| T_LBRACE | `{` | 7 | 12 |
| T_IDENT | `x` | 7 | 14 |
| T_COLON | `:` | 7 | 16 |
| T_IDENT | `x` | 7 | 18 |
| T_GTE | `>=` | 7 | 21 |
| T_NUMBER | `0` | 7 | 23 |
| T_RBRACE | `}` | 7 | 25 |
| T_IDENT | `expand` | 8 | 7 |
| T_COLON | `:` | 8 | 9 |
| T_LBRACE | `{` | 8 | 12 |
| T_LBRACK | `[` | 8 | 14 |
| T_IDENT | `x` | 8 | 16 |
| T_SLASH | `/` | 8 | 18 |
| T_NUMBER | `2` | 8 | 20 |
| T_COMMA | `,` | 8 | 21 |
| T_IDENT | `x` | 8 | 23 |
| T_SLASH | `/` | 8 | 25 |
| T_NUMBER | `3` | 8 | 27 |
| T_RBRACK | `]` | 8 | 29 |
| T_PIPE | `|` | 8 | 31 |
| T_IDENT | `x` | 8 | 33 |
| T_RBRACE | `}` | 8 | 35 |
| T_IDENT | `output` | 9 | 7 |
| T_COLON | `:` | 9 | 9 |

## Test: filter_even.ctl

| Token Type | Lexeme | Line | Column |
|------------|---------|------|--------|
| T_IDENT | `filter` | 1 | 7 |
| T_COLON | `:` | 1 | 8 |
| T_LBRACE | `{` | 1 | 10 |
| T_IDENT | `x` | 1 | 12 |
| T_COLON | `:` | 1 | 14 |
| T_IDENT | `x` | 1 | 16 |
| T_PERCENT | `%` | 1 | 18 |
| T_NUMBER | `2` | 1 | 20 |
| T_EQ | `==` | 1 | 23 |
| T_NUMBER | `0` | 1 | 25 |
| T_RBRACE | `}` | 1 | 27 |

## Test: full_pipeline.ctl

| Token Type | Lexeme | Line | Column |
|------------|---------|------|--------|
| T_IDENT | `data` | 1 | 5 |
| T_COLON | `:` | 1 | 6 |
| T_LBRACK | `[` | 1 | 8 |
| T_NUMBER | `1` | 1 | 9 |
| T_COMMA | `,` | 1 | 10 |
| T_NUMBER | `2` | 1 | 11 |
| T_COMMA | `,` | 1 | 12 |
| T_NUMBER | `3` | 1 | 13 |
| T_RBRACK | `]` | 1 | 14 |
| T_IDENT | `map` | 2 | 4 |
| T_COLON | `:` | 2 | 5 |
| T_LBRACE | `{` | 2 | 7 |
| T_IDENT | `x` | 2 | 9 |
| T_COLON | `:` | 2 | 11 |
| T_IDENT | `x` | 2 | 13 |
| T_STAR | `*` | 2 | 15 |
| T_NUMBER | `2` | 2 | 17 |
| T_RBRACE | `}` | 2 | 19 |
| T_OUTPUT | `output:` | 3 | 8 |

## Test: map_plus.ctl

| Token Type | Lexeme | Line | Column |
|------------|---------|------|--------|
| T_IDENT | `map` | 1 | 4 |
| T_COLON | `:` | 1 | 5 |
| T_LBRACE | `{` | 1 | 7 |
| T_IDENT | `x` | 1 | 9 |
| T_COLON | `:` | 1 | 11 |
| T_IDENT | `x` | 1 | 13 |
| T_PLUS | `+` | 1 | 15 |
| T_NUMBER | `1` | 1 | 17 |
| T_RBRACE | `}` | 1 | 19 |

## Test: simple_vector.ctl

| Token Type | Lexeme | Line | Column |
|------------|---------|------|--------|
| T_IDENT | `input` | 1 | 6 |
| T_COLON | `:` | 1 | 7 |
| T_LBRACK | `[` | 1 | 9 |
| T_NUMBER | `10` | 1 | 11 |
| T_COMMA | `,` | 1 | 12 |
| T_NUMBER | `20` | 1 | 14 |
| T_RBRACK | `]` | 1 | 15 |

