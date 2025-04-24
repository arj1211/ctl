## Syntax Examples

### Minimal Valid Program

```
0 :
```
or
```
[10,20,30] :
```

Which prints the latest result to stdout (the specified input vector). Input vector can be a comma-delimited list of decimal numbers *or* just a single decimal number.

### Transformations

#### `map`
```
x : x + 1
Y : Y ^ 3
_ : _ << 4
```
Always of the form `S : ArithExpr<S>`, where `S` is any symbol following `[a-zA-Z_][a-zA-Z0-9_]*`, and `ArithExpr<S>` is any arithmetic operation referring only to `S`.

> so something like `d : d & v` would be invalid because the arithmetic expression makes reference to an unknown symbol `v`.

The specific choice of the lexeme of `S` is irrelevant.

#### `filter`
```
x : x < 4
Y : Y % 2 == 0
```
Similar to `map` statements. Is always of the form `S : BoolExpr<S>`, where `S` is any valid symbol and `BoolExpr<S>` is any boolean expression referring only to `S`; that is, an expression that always evaluates to a True or False value.

### Simple Program
```
1,2,3,4
x : (x + 1) * (x + 2)
c : c % 3 == 0
:
```
Should produce the output
```
$> 6,12,30
```

## Syntactic Elements

### Numeric and Vector Literals

A `NumericLiteral` is any integer.

```
NumericLiteral ::= -?[0-9]+
```

A `VectorLiteral` is `NumericLiteral (,NumericLiteral)*`, i.e. a comma-delimited list of `NumericLiteral`.

```
VectorLiteral ::= NumericLiteral (','NumericLiteral)*
```

### Expr
```
Expr ::= NumericLiteral
       | VectorLiteral
       | ArithExpr
       | BoolExpr   
```

### Statement
```
S   : ArithExpr<S>
    | BoolExpr<S>
```

### 