# Lexer Test Report

## Test: arithmetic_on_literals_and_symbols.ctl

```
@ 7. Arithmetic on literals and symbols
[1,2] : a * 3:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 2 | 2 |
| T_NUMBER | `1` | 2 | 3 |
| T_COMMA | `,` | 2 | 4 |
| T_NUMBER | `2` | 2 | 5 |
| T_RBRACK | `]` | 2 | 6 |
| T_COLON | `:` | 2 | 8 |
| T_LETTER | `a` | 2 | 10 |
| T_STAR | `*` | 2 | 12 |
| T_NUMBER | `3` | 2 | 14 |
| T_COLON | `:` | 2 | 15 |

## Test: bare_vector_literal.ctl

```
@ 5. Bare vector literal
1,2,3:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_NUMBER | `1` | 2 | 2 |
| T_COMMA | `,` | 2 | 3 |
| T_NUMBER | `2` | 2 | 4 |
| T_COMMA | `,` | 2 | 5 |
| T_NUMBER | `3` | 2 | 6 |
| T_COLON | `:` | 2 | 7 |

## Test: bracketed_vector_literal.ctl

```
@ 6. Bracketed vector literal
[4,5,6]:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 2 | 2 |
| T_NUMBER | `4` | 2 | 3 |
| T_COMMA | `,` | 2 | 4 |
| T_NUMBER | `5` | 2 | 5 |
| T_COMMA | `,` | 2 | 6 |
| T_NUMBER | `6` | 2 | 7 |
| T_RBRACK | `]` | 2 | 8 |
| T_COLON | `:` | 2 | 9 |

## Test: combined_arithmetic_and_comparison.ctl

```
@ 13. Combined arithmetic and comparison
(x * 2 + 1) / (x - 1) >= 5:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LPAREN | `(` | 2 | 2 |
| T_LETTER | `x` | 2 | 3 |
| T_STAR | `*` | 2 | 5 |
| T_NUMBER | `2` | 2 | 7 |
| T_PLUS | `+` | 2 | 9 |
| T_NUMBER | `1` | 2 | 11 |
| T_RPAREN | `)` | 2 | 12 |
| T_SLASH | `/` | 2 | 14 |
| T_LPAREN | `(` | 2 | 16 |
| T_LETTER | `x` | 2 | 17 |
| T_MINUS | `-` | 2 | 19 |
| T_NUMBER | `1` | 2 | 21 |
| T_RPAREN | `)` | 2 | 22 |
| T_GTE | `>=` | 2 | 25 |
| T_NUMBER | `5` | 2 | 27 |
| T_COLON | `:` | 2 | 28 |

## Test: comparison_between_an_expr_and_literal.ctl

```
@ 8. Comparison between an expr and literal
(x - 2) == 7:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LPAREN | `(` | 2 | 2 |
| T_LETTER | `x` | 2 | 3 |
| T_MINUS | `-` | 2 | 5 |
| T_NUMBER | `2` | 2 | 7 |
| T_RPAREN | `)` | 2 | 8 |
| T_EQ | `==` | 2 | 11 |
| T_NUMBER | `7` | 2 | 13 |
| T_COLON | `:` | 2 | 14 |

## Test: complex_pipeline.ctl

```
@ this is a comment
[1,2,3,4,5,6,7,8,9,10] @ this is also a comment
@ this is a comment
:x : (x * 2 + 1) / (x - 1) @ this is also a comment
@ this is a comment
:x : x % 2 == 0 @ this is also a comment
@ this is a comment
:x : x > 3 @ this is also a comment
@ this is a comment
:x : x - 5 @ this is also a comment
@ this is a comment
:x : x >= 0 @ this is also a comment
@ this is a comment
: @ this is also a comment
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 2 | 2 |
| T_NUMBER | `1` | 2 | 3 |
| T_COMMA | `,` | 2 | 4 |
| T_NUMBER | `2` | 2 | 5 |
| T_COMMA | `,` | 2 | 6 |
| T_NUMBER | `3` | 2 | 7 |
| T_COMMA | `,` | 2 | 8 |
| T_NUMBER | `4` | 2 | 9 |
| T_COMMA | `,` | 2 | 10 |
| T_NUMBER | `5` | 2 | 11 |
| T_COMMA | `,` | 2 | 12 |
| T_NUMBER | `6` | 2 | 13 |
| T_COMMA | `,` | 2 | 14 |
| T_NUMBER | `7` | 2 | 15 |
| T_COMMA | `,` | 2 | 16 |
| T_NUMBER | `8` | 2 | 17 |
| T_COMMA | `,` | 2 | 18 |
| T_NUMBER | `9` | 2 | 19 |
| T_COMMA | `,` | 2 | 20 |
| T_NUMBER | `10` | 2 | 22 |
| T_RBRACK | `]` | 2 | 23 |
| T_COLON | `:` | 4 | 2 |
| T_LETTER | `x` | 4 | 3 |
| T_COLON | `:` | 4 | 5 |
| T_LPAREN | `(` | 4 | 7 |
| T_LETTER | `x` | 4 | 8 |
| T_STAR | `*` | 4 | 10 |
| T_NUMBER | `2` | 4 | 12 |
| T_PLUS | `+` | 4 | 14 |
| T_NUMBER | `1` | 4 | 16 |
| T_RPAREN | `)` | 4 | 17 |
| T_SLASH | `/` | 4 | 19 |
| T_LPAREN | `(` | 4 | 21 |
| T_LETTER | `x` | 4 | 22 |
| T_MINUS | `-` | 4 | 24 |
| T_NUMBER | `1` | 4 | 26 |
| T_RPAREN | `)` | 4 | 27 |
| T_COLON | `:` | 6 | 2 |
| T_LETTER | `x` | 6 | 3 |
| T_COLON | `:` | 6 | 5 |
| T_LETTER | `x` | 6 | 7 |
| T_PERCENT | `%` | 6 | 9 |
| T_NUMBER | `2` | 6 | 11 |
| T_EQ | `==` | 6 | 14 |
| T_NUMBER | `0` | 6 | 16 |
| T_COLON | `:` | 8 | 2 |
| T_LETTER | `x` | 8 | 3 |
| T_COLON | `:` | 8 | 5 |
| T_LETTER | `x` | 8 | 7 |
| T_GT | `>` | 8 | 9 |
| T_NUMBER | `3` | 8 | 11 |
| T_COLON | `:` | 10 | 2 |
| T_LETTER | `x` | 10 | 3 |
| T_COLON | `:` | 10 | 5 |
| T_LETTER | `x` | 10 | 7 |
| T_MINUS | `-` | 10 | 9 |
| T_NUMBER | `5` | 10 | 11 |
| T_COLON | `:` | 12 | 2 |
| T_LETTER | `x` | 12 | 3 |
| T_COLON | `:` | 12 | 5 |
| T_LETTER | `x` | 12 | 7 |
| T_GTE | `>=` | 12 | 10 |
| T_NUMBER | `0` | 12 | 12 |
| T_COLON | `:` | 14 | 2 |

## Test: deeply_nested_with_multiple_ops.ctl

```
@ 14. Deeply nested with multiple ops
((a << 3) - (b % 5)) ^ (c + (d / 2)):
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LPAREN | `(` | 2 | 2 |
| T_LPAREN | `(` | 2 | 3 |
| T_LETTER | `a` | 2 | 4 |
| T_LSH | `<<` | 2 | 7 |
| T_NUMBER | `3` | 2 | 9 |
| T_RPAREN | `)` | 2 | 10 |
| T_MINUS | `-` | 2 | 12 |
| T_LPAREN | `(` | 2 | 14 |
| T_LETTER | `b` | 2 | 15 |
| T_PERCENT | `%` | 2 | 17 |
| T_NUMBER | `5` | 2 | 19 |
| T_RPAREN | `)` | 2 | 20 |
| T_RPAREN | `)` | 2 | 21 |
| T_EXP | `^` | 2 | 23 |
| T_LPAREN | `(` | 2 | 25 |
| T_LETTER | `c` | 2 | 26 |
| T_PLUS | `+` | 2 | 28 |
| T_LPAREN | `(` | 2 | 30 |
| T_LETTER | `d` | 2 | 31 |
| T_SLASH | `/` | 2 | 33 |
| T_NUMBER | `2` | 2 | 35 |
| T_RPAREN | `)` | 2 | 36 |
| T_RPAREN | `)` | 2 | 37 |
| T_COLON | `:` | 2 | 38 |

## Test: filter_even.ctl

```
x : x % 2 == 0
:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `x` | 1 | 2 |
| T_COLON | `:` | 1 | 4 |
| T_LETTER | `x` | 1 | 6 |
| T_PERCENT | `%` | 1 | 8 |
| T_NUMBER | `2` | 1 | 10 |
| T_EQ | `==` | 1 | 13 |
| T_NUMBER | `0` | 1 | 15 |
| T_COLON | `:` | 2 | 2 |

## Test: full_pipeline.ctl

```
[1,2,3]
:x : x * 2
:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 1 | 2 |
| T_NUMBER | `1` | 1 | 3 |
| T_COMMA | `,` | 1 | 4 |
| T_NUMBER | `2` | 1 | 5 |
| T_COMMA | `,` | 1 | 6 |
| T_NUMBER | `3` | 1 | 7 |
| T_RBRACK | `]` | 1 | 8 |
| T_COLON | `:` | 2 | 2 |
| T_LETTER | `x` | 2 | 3 |
| T_COLON | `:` | 2 | 5 |
| T_LETTER | `x` | 2 | 7 |
| T_STAR | `*` | 2 | 9 |
| T_NUMBER | `2` | 2 | 11 |
| T_COLON | `:` | 3 | 2 |

## Test: full_program_chaining_everything.ctl

```
@ 15. Full program chaining everything
[1,2,3] : p + q * r : (p % 2) == 0 : (q >> 1) <= (r ^ 2) : z - (x + y):
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 2 | 2 |
| T_NUMBER | `1` | 2 | 3 |
| T_COMMA | `,` | 2 | 4 |
| T_NUMBER | `2` | 2 | 5 |
| T_COMMA | `,` | 2 | 6 |
| T_NUMBER | `3` | 2 | 7 |
| T_RBRACK | `]` | 2 | 8 |
| T_COLON | `:` | 2 | 10 |
| T_LETTER | `p` | 2 | 12 |
| T_PLUS | `+` | 2 | 14 |
| T_LETTER | `q` | 2 | 16 |
| T_STAR | `*` | 2 | 18 |
| T_LETTER | `r` | 2 | 20 |
| T_COLON | `:` | 2 | 22 |
| T_LPAREN | `(` | 2 | 24 |
| T_LETTER | `p` | 2 | 25 |
| T_PERCENT | `%` | 2 | 27 |
| T_NUMBER | `2` | 2 | 29 |
| T_RPAREN | `)` | 2 | 30 |
| T_EQ | `==` | 2 | 33 |
| T_NUMBER | `0` | 2 | 35 |
| T_COLON | `:` | 2 | 37 |
| T_LPAREN | `(` | 2 | 39 |
| T_LETTER | `q` | 2 | 40 |
| T_RSH | `>>` | 2 | 43 |
| T_NUMBER | `1` | 2 | 45 |
| T_RPAREN | `)` | 2 | 46 |
| T_LTE | `<=` | 2 | 49 |
| T_LPAREN | `(` | 2 | 51 |
| T_LETTER | `r` | 2 | 52 |
| T_EXP | `^` | 2 | 54 |
| T_NUMBER | `2` | 2 | 56 |
| T_RPAREN | `)` | 2 | 57 |
| T_COLON | `:` | 2 | 59 |
| T_LETTER | `z` | 2 | 61 |
| T_MINUS | `-` | 2 | 63 |
| T_LPAREN | `(` | 2 | 65 |
| T_LETTER | `x` | 2 | 66 |
| T_PLUS | `+` | 2 | 68 |
| T_LETTER | `y` | 2 | 70 |
| T_RPAREN | `)` | 2 | 71 |
| T_COLON | `:` | 2 | 72 |

## Test: language_examples.ctl

```
@ 1. Single numeric literal
42:

@ 2. Single symbol
x:

@ 3. Simple arithmetic
x + 5:

@ 4. Simple comparison
y >= 10:

@ 5. Bare vector literal
1,2,3:

@ 6. Bracketed vector literal
[4,5,6]:

@ 7. Arithmetic on literals and symbols
[1,2] : a * 3:

@ 8. Comparison between an expr and literal
(x - 2) == 7:

@ 9. Mixed ops with precedence via grouping
(3 + x) * (y - 4):

@ 10. Nested parentheses
((x + 1) * (x - 1)) / (x ^ 2):

@ 11. Modulo and shift
x % 4 : x << 2:

@ 12. Vector plus comparison
[0,1,2] : z != 0:

@ 13. Combined arithmetic and comparison
(x * 2 + 1) / (x - 1) >= 5:

@ 14. Deeply nested with multiple ops
((a << 3) - (b % 5)) ^ (c + (d / 2)):

@ 15. Full program chaining everything
[1,2,3] : p + q * r : (p % 2) == 0 : (q >> 1) <= (r ^ 2) : z - (x + y):
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_NUMBER | `42` | 2 | 3 |
| T_COLON | `:` | 2 | 4 |
| T_LETTER | `x` | 5 | 2 |
| T_COLON | `:` | 5 | 3 |
| T_LETTER | `x` | 8 | 2 |
| T_PLUS | `+` | 8 | 4 |
| T_NUMBER | `5` | 8 | 6 |
| T_COLON | `:` | 8 | 7 |
| T_LETTER | `y` | 11 | 2 |
| T_GTE | `>=` | 11 | 5 |
| T_NUMBER | `10` | 11 | 8 |
| T_COLON | `:` | 11 | 9 |
| T_NUMBER | `1` | 14 | 2 |
| T_COMMA | `,` | 14 | 3 |
| T_NUMBER | `2` | 14 | 4 |
| T_COMMA | `,` | 14 | 5 |
| T_NUMBER | `3` | 14 | 6 |
| T_COLON | `:` | 14 | 7 |
| T_LBRACK | `[` | 17 | 2 |
| T_NUMBER | `4` | 17 | 3 |
| T_COMMA | `,` | 17 | 4 |
| T_NUMBER | `5` | 17 | 5 |
| T_COMMA | `,` | 17 | 6 |
| T_NUMBER | `6` | 17 | 7 |
| T_RBRACK | `]` | 17 | 8 |
| T_COLON | `:` | 17 | 9 |
| T_LBRACK | `[` | 20 | 2 |
| T_NUMBER | `1` | 20 | 3 |
| T_COMMA | `,` | 20 | 4 |
| T_NUMBER | `2` | 20 | 5 |
| T_RBRACK | `]` | 20 | 6 |
| T_COLON | `:` | 20 | 8 |
| T_LETTER | `a` | 20 | 10 |
| T_STAR | `*` | 20 | 12 |
| T_NUMBER | `3` | 20 | 14 |
| T_COLON | `:` | 20 | 15 |
| T_LPAREN | `(` | 23 | 2 |
| T_LETTER | `x` | 23 | 3 |
| T_MINUS | `-` | 23 | 5 |
| T_NUMBER | `2` | 23 | 7 |
| T_RPAREN | `)` | 23 | 8 |
| T_EQ | `==` | 23 | 11 |
| T_NUMBER | `7` | 23 | 13 |
| T_COLON | `:` | 23 | 14 |
| T_LPAREN | `(` | 26 | 2 |
| T_NUMBER | `3` | 26 | 3 |
| T_PLUS | `+` | 26 | 5 |
| T_LETTER | `x` | 26 | 7 |
| T_RPAREN | `)` | 26 | 8 |
| T_STAR | `*` | 26 | 10 |
| T_LPAREN | `(` | 26 | 12 |
| T_LETTER | `y` | 26 | 13 |
| T_MINUS | `-` | 26 | 15 |
| T_NUMBER | `4` | 26 | 17 |
| T_RPAREN | `)` | 26 | 18 |
| T_COLON | `:` | 26 | 19 |
| T_LPAREN | `(` | 29 | 2 |
| T_LPAREN | `(` | 29 | 3 |
| T_LETTER | `x` | 29 | 4 |
| T_PLUS | `+` | 29 | 6 |
| T_NUMBER | `1` | 29 | 8 |
| T_RPAREN | `)` | 29 | 9 |
| T_STAR | `*` | 29 | 11 |
| T_LPAREN | `(` | 29 | 13 |
| T_LETTER | `x` | 29 | 14 |
| T_MINUS | `-` | 29 | 16 |
| T_NUMBER | `1` | 29 | 18 |
| T_RPAREN | `)` | 29 | 19 |
| T_RPAREN | `)` | 29 | 20 |
| T_SLASH | `/` | 29 | 22 |
| T_LPAREN | `(` | 29 | 24 |
| T_LETTER | `x` | 29 | 25 |
| T_EXP | `^` | 29 | 27 |
| T_NUMBER | `2` | 29 | 29 |
| T_RPAREN | `)` | 29 | 30 |
| T_COLON | `:` | 29 | 31 |
| T_LETTER | `x` | 32 | 2 |
| T_PERCENT | `%` | 32 | 4 |
| T_NUMBER | `4` | 32 | 6 |
| T_COLON | `:` | 32 | 8 |
| T_LETTER | `x` | 32 | 10 |
| T_LSH | `<<` | 32 | 13 |
| T_NUMBER | `2` | 32 | 15 |
| T_COLON | `:` | 32 | 16 |
| T_LBRACK | `[` | 35 | 2 |
| T_NUMBER | `0` | 35 | 3 |
| T_COMMA | `,` | 35 | 4 |
| T_NUMBER | `1` | 35 | 5 |
| T_COMMA | `,` | 35 | 6 |
| T_NUMBER | `2` | 35 | 7 |
| T_RBRACK | `]` | 35 | 8 |
| T_COLON | `:` | 35 | 10 |
| T_LETTER | `z` | 35 | 12 |
| T_NEQ | `!=` | 35 | 15 |
| T_NUMBER | `0` | 35 | 17 |
| T_COLON | `:` | 35 | 18 |
| T_LPAREN | `(` | 38 | 2 |
| T_LETTER | `x` | 38 | 3 |
| T_STAR | `*` | 38 | 5 |
| T_NUMBER | `2` | 38 | 7 |
| T_PLUS | `+` | 38 | 9 |

## Test: map_plus.ctl

```
x : x + 1:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `x` | 1 | 2 |
| T_COLON | `:` | 1 | 4 |
| T_LETTER | `x` | 1 | 6 |
| T_PLUS | `+` | 1 | 8 |
| T_NUMBER | `1` | 1 | 10 |
| T_COLON | `:` | 1 | 11 |

## Test: mixed_ops_with_precedence_via_grouping.ctl

```
@ 9. Mixed ops with precedence via grouping
(3 + x) * (y - 4):
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LPAREN | `(` | 2 | 2 |
| T_NUMBER | `3` | 2 | 3 |
| T_PLUS | `+` | 2 | 5 |
| T_LETTER | `x` | 2 | 7 |
| T_RPAREN | `)` | 2 | 8 |
| T_STAR | `*` | 2 | 10 |
| T_LPAREN | `(` | 2 | 12 |
| T_LETTER | `y` | 2 | 13 |
| T_MINUS | `-` | 2 | 15 |
| T_NUMBER | `4` | 2 | 17 |
| T_RPAREN | `)` | 2 | 18 |
| T_COLON | `:` | 2 | 19 |

## Test: modulo_and_shift.ctl

```
@ 11. Modulo and shift
x % 4 : x << 2:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `x` | 2 | 2 |
| T_PERCENT | `%` | 2 | 4 |
| T_NUMBER | `4` | 2 | 6 |
| T_COLON | `:` | 2 | 8 |
| T_LETTER | `x` | 2 | 10 |
| T_LSH | `<<` | 2 | 13 |
| T_NUMBER | `2` | 2 | 15 |
| T_COLON | `:` | 2 | 16 |

## Test: nested_parentheses.ctl

```
@ 10. Nested parentheses
((x + 1) * (x - 1)) / (x ^ 2):
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LPAREN | `(` | 2 | 2 |
| T_LPAREN | `(` | 2 | 3 |
| T_LETTER | `x` | 2 | 4 |
| T_PLUS | `+` | 2 | 6 |
| T_NUMBER | `1` | 2 | 8 |
| T_RPAREN | `)` | 2 | 9 |
| T_STAR | `*` | 2 | 11 |
| T_LPAREN | `(` | 2 | 13 |
| T_LETTER | `x` | 2 | 14 |
| T_MINUS | `-` | 2 | 16 |
| T_NUMBER | `1` | 2 | 18 |
| T_RPAREN | `)` | 2 | 19 |
| T_RPAREN | `)` | 2 | 20 |
| T_SLASH | `/` | 2 | 22 |
| T_LPAREN | `(` | 2 | 24 |
| T_LETTER | `x` | 2 | 25 |
| T_EXP | `^` | 2 | 27 |
| T_NUMBER | `2` | 2 | 29 |
| T_RPAREN | `)` | 2 | 30 |
| T_COLON | `:` | 2 | 31 |

## Test: simple_arithmetic.ctl

```
@ 3. Simple arithmetic
x + 5:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `x` | 2 | 2 |
| T_PLUS | `+` | 2 | 4 |
| T_NUMBER | `5` | 2 | 6 |
| T_COLON | `:` | 2 | 7 |

## Test: simple_comparison.ctl

```
@ 4. Simple comparison
y >= 10:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `y` | 2 | 2 |
| T_GTE | `>=` | 2 | 5 |
| T_NUMBER | `10` | 2 | 8 |
| T_COLON | `:` | 2 | 9 |

## Test: simple_vector.ctl

```
[10,20]:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 1 | 2 |
| T_NUMBER | `10` | 1 | 4 |
| T_COMMA | `,` | 1 | 5 |
| T_NUMBER | `20` | 1 | 7 |
| T_RBRACK | `]` | 1 | 8 |
| T_COLON | `:` | 1 | 9 |

## Test: single_numeric_literal.ctl

```
@ 1. Single numeric literal
42:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_NUMBER | `42` | 2 | 3 |
| T_COLON | `:` | 2 | 4 |

## Test: single_symbol.ctl

```
@ 2. Single symbol
x:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LETTER | `x` | 2 | 2 |
| T_COLON | `:` | 2 | 3 |

## Test: vector_plus_comparison.ctl

```
@ 12. Vector plus comparison
[0,1,2] : z != 0:
```

| Token Type | Lexeme | Line | Column |
|------------|--------|------|--------|
| T_LBRACK | `[` | 2 | 2 |
| T_NUMBER | `0` | 2 | 3 |
| T_COMMA | `,` | 2 | 4 |
| T_NUMBER | `1` | 2 | 5 |
| T_COMMA | `,` | 2 | 6 |
| T_NUMBER | `2` | 2 | 7 |
| T_RBRACK | `]` | 2 | 8 |
| T_COLON | `:` | 2 | 10 |
| T_LETTER | `z` | 2 | 12 |
| T_NEQ | `!=` | 2 | 15 |
| T_NUMBER | `0` | 2 | 17 |
| T_COLON | `:` | 2 | 18 |

