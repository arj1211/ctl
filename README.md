# Collection Transformation Language (CTL)

This document captures the definition, syntax, architecture, and future extensions for CTL—a minimal DSL for transforming collections of numbers through a pipeline of steps.

---

## Overview

CTL (Collection Transformation Language) is a small, lowercase-only domain-specific language designed to apply a sequence of transformations to collections (vectors) of numbers. It emphasizes an implicit chaining model: each operation applies to the result of the previous statement, culminating in an `output` step that prints the final vector.

**Primary Concepts:**

- **Program**: a series of statements, executed top-to-bottom
- **Statement**: `name : expr` binds the result of `expr` to `name`
- **Vector Literal**: `[n1, n2, ...]`
- **Map**: `{ x : <arith-expr> }`
- **Filter**: `{ x : <boolean-expr> }`
- **Expand**: `{ [binding-list] | binding }`
- **Output**: `output:` prints the last bound vector

---

## Syntax Concepts

| Concept            | Surface Syntax                      | Semantics                                                         |
|--------------------|-------------------------------------|-------------------------------------------------------------------|
| Program            | sequence of `Stmt` lines            | executed in order, binding vectors to names                       |
| Statement          | `name : expr`                       | evaluate `expr`, store under `name`                              |
| Output Statement   | `output:`                           | print the current vector                                          |
| Vector Literal     | `[1, 2, 3]`                         | fixed array of numbers                                           |
| Map                | `{ x : x * 2 }`                     | for each element of the last vector, bind to `x`, eval body      |
| Filter             | `{ x : x % 3 != 0 }`                | keep only elements where body is true                            |
| Expand             | `{ [x, x+1] \| x }`                  | for each `x`, produce a sub-vector `[x, x+1]`                     |

## Grammar (BNF)

```ebnf
Program       ::= StmtList EOF

StmtList      ::= Stmt ('\n')*

Stmt          ::= IDENT ':' Expr
                | 'output:'

Expr          ::= VectorLiteral
                | MapExpr
                | FilterExpr
                | ExpandExpr

MapExpr       ::= '{' IDENT ':' ArithExpr '}'

FilterExpr    ::= '{' IDENT ':' BoolExpr '}'

ExpandExpr    ::= '{' '[' ArithExprList ']' '|' IDENT '}'

BoolExpr      ::= ArithExpr (('==' | '!=' | '<' | '>' | '<=' | '>=') ArithExpr)?

VectorLiteral ::= '[' NumberList ']'

NumberList    ::= NUMBER (',' NUMBER)*

ArithExprList ::= ArithExpr (',' ArithExpr)*

BindingList   ::= IDENT (',' IDENT)*

ArithExpr     ::= ArithExpr ('+' | '-' | '*' | '/' | '%') ArithExpr
                | NUMBER
                | IDENT
                | '(' ArithExpr ')'

```

### (section needs revision) MapExpr, FilterExpr vs ExpandExpr

`map` and `filter` each take exactly **one input element** and produce exactly **one output element** (a number or a boolean). So their syntax is a simple binding and body:

`{ x : <expr(x)> }`

The colon (`:`) says “for each input bound to `x`, compute this one result.”

`expand` on the other hand, can produce **multiple** outputs per input (zero, one, or many). You need to say both “here’s how I bind the input” and “here’s the **list** of outputs to splice back into the pipeline.” The pipe (`|`) visually separates those two concerns:

`{ [out1, out2, ...] | x }`

meaning “for each input bound to `x`, emit this entire sub‑vector `[out1, out2, ...]`.”

---

## Interpreter Architecture

CTL’s interpreter follows a classic three-stage pipeline:

1. **Lexer**: reads input characters, skips whitespace/comments, and emits a stream of `Token`s:

   - `T_IDENT`, `T_NUMBER`, punctuation (`[`, `]`, `{`, `}`, `:`, `,`, `|`), operators (`+`, `-`, `*`, `/`, `%`, `==`, `!=`, `<`, `>`), and `T_EOF`.

2. **Parser**: a recursive-descent parser consumes `Token`s and constructs an Abstract Syntax Tree (AST) according to the BNF above. Key entrypoints:

   - `parse_program()`, `parse_stmt()`, `parse_expr()`, `parse_arith()`

3. **Evaluator**: walks the AST, maintaining an environment that maps `name -> Vec*`. For each `Stmt`:

   - **VectorLiteral**: allocates a `Vec`, populates items.
   - **Map/Filter**: iterates over previous `Vec`, binds each element, evaluates body expression, and collects results.
   - **Expand**: similar, but body yields a sub-Vec for each element, which are concatenated.
   - **Output**: retrieves the last `Vec` and prints its contents.

Error conditions (syntax/runtime) immediately abort with descriptive messages.

---

## Key Data Structures (C)

```c
// Token representation
typedef enum {
    T_IDENT, T_NUMBER,
    T_LBRACK, T_RBRACK, T_LBRACE, T_RBRACE,
    T_COLON, T_COMMA, T_PIPE,
    T_PLUS, T_MINUS, T_STAR, T_SLASH, T_PERCENT,
    T_EQ, T_NEQ, T_LT, T_GT,
    T_EOF,
} TokenType;

typedef struct {
    TokenType type;
    char *lexeme;   // for IDENT and NUMBER
} Token;

// AST node kinds
typedef enum {
    AST_PROGRAM,
    AST_STMT,
    AST_VECTOR_LITERAL,
    AST_MAP_EXPR,     // also used for filter
    AST_EXPAND_EXPR,
    AST_BINOP,
    AST_VAR,
    AST_NUM,
} AstKind;

typedef struct AstNode AstNode;
typedef struct Vec Vec;

struct AstNode {
    AstKind kind;
    union {
        // AST_STMT
        struct { char *name; AstNode *expr; } stmt;
        // AST_VECTOR_LITERAL
        Vec *vector;
        // AST_MAP_EXPR / AST_EXPAND_EXPR
        struct {
            char **bindings;   // array of binding names
            int n_bindings;
            AstNode *body;     // arithmetic or sub-vector expr
        } transform;
        // AST_BINOP
        struct {
            TokenType op;
            AstNode *left, *right;
        } binop;
        // AST_VAR
        char *varname;
        // AST_NUM
        double num;
    } as;
};

// Dynamic array of doubles
struct Vec {
    double *items;
    size_t len;
    size_t cap;
};
```

---

## Example Program

```
input: [1,2,3,4,5]

map:    { x : x * 2 }
filter: { x : x % 3 != 0 }
expand: { [x, x+1] | x }

output:
```

This produces: `[2,3,4,5,8,9,10,11]`.

---

## Future Extensions (v2)

In later versions of CTL, we may add these operations:

### 1. Reduce

**Syntax**:

```
reduce: { acc, x : <acc_expr> }
```

- `acc`: running accumulator, `x`: current element.
- Folds vector to a single value (left-to-right).

**Example**:

```
input: [1,2,3,4]
reduce: { acc, x : acc + x }
output:
```

Yields `10`.

### 2. Zip

**Syntax**:

```
zip: { a, b : <expr(a,b)> }
```

- `a`, `b` bind to elements of the two most recent vectors.
- Stops at the shorter vector’s length.

**Example**:

```
input1: [1,2,3]
input2: [4,5,6]
zip: { a, b : a * b }
output:
```

Yields `[4,10,18]`.

### 3. Matrix Operations

#### a) Transpose

**Syntax**:

```
transpose:
```

Swaps rows and columns of the current matrix.

#### b) Dot Product

**Syntax**:

```
dot: { A, B }
```

- For 1-D vectors: inner product.
- For 2-D matrices: matrix multiplication.

**Example**:

```
A: [[1,2],[3,4]]
B: [[5,6],[7,8]]
dot: { A, B }
output:
```

Yields `[[19,22],[43,50]]`.
