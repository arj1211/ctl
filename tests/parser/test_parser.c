#include "../../src/parser.h"
#include <assert.h>
#include <stdio.h>

static void test_vector_literal(void) {
  const char *source = "nums: [1, 2, 3]";
  Lexer lexer;
  lexer_init(&lexer, source);

  Parser parser;
  parser_init(&parser, &lexer);

  AstNode *program = parse_program(&parser);
  assert(!parser_had_error(&parser));
  assert(program->type == AST_PROGRAM);
  assert(program->as.statements.len == 1);

  AstNode *vector = program->as.statements.items[0];
  assert(vector->type == AST_VECTOR);
  assert(vector->as.vector.len == 3);
  assert(vector->as.vector.items[0] == 1.0);
  assert(vector->as.vector.items[1] == 2.0);
  assert(vector->as.vector.items[2] == 3.0);

  ast_free(program);
  printf("Vector literal test passed\n");
}

static void test_map_expression(void) {
  const char *source = "doubled: { x : x * 2 }";
  Lexer lexer;
  lexer_init(&lexer, source);

  Parser parser;
  parser_init(&parser, &lexer);

  AstNode *program = parse_program(&parser);
  assert(!parser_had_error(&parser));

  AstNode *map = program->as.statements.items[0];
  assert(map->type == AST_MAP);
  assert(strcmp(map->as.transform.binding, "x") == 0);

  AstNode *expr = map->as.transform.expr;
  assert(expr->type == AST_BINOP);
  assert(expr->as.operation.op == T_STAR);

  ast_free(program);
  printf("Map expression test passed\n");
}

int main(void) {
  test_vector_literal();
  test_map_expression();
  // Add more tests...
  return 0;
}