# ┌───────────────────────────────────────────────────────────────────────────┐
# │                            Project Settings                               │
# └───────────────────────────────────────────────────────────────────────────┘

# Compiler and flags
CC        				:= gcc
CFLAGS    				:= -Wall -Wextra -std=c99 -g

# Directories
SRC_DIR   				:= src
TEST_DIR  				:= tests

LEXER_TEST_DIR			:= $(TEST_DIR)/lexer

# Sources
LEXER_SRC     			:= $(SRC_DIR)/lexer.c
TEST_LEXER_SRC			:= $(LEXER_TEST_DIR)/test_lexer.c
TEST_LEXER_PY_SCRIPT    := $(LEXER_TEST_DIR)/run_lexer_tests.py

# Binaries & outputs
TEST_LEXER_BIN     		:= test_lexer

LEXER_CSV     			:= $(LEXER_TEST_DIR)/test_lexer_results.csv
LEXER_DSYM	  			:= $(TEST_LEXER_BIN).dSYM

# ┌───────────────────────────────────────────────────────────────────────────┐
# │                              Build Targets                                │
# └───────────────────────────────────────────────────────────────────────────┘

.PHONY: all build test-lexer run-lexer-tests test clean

all: build

# Build the lexer test harness
build: $(TEST_LEXER_BIN)

$(TEST_LEXER_BIN): $(LEXER_SRC) $(TEST_LEXER_SRC)
	$(CC) $(CFLAGS) $^ -o $@

# ┌───────────────────────────────────────────────────────────────────────────┐
# │                             Test Targets                                  │
# └───────────────────────────────────────────────────────────────────────────┘

# Run the single‐file lexer test (prints tokens to stdout)
test-lexer: $(TEST_LEXER_BIN)
	./$(TEST_LEXER_BIN)

# Execute your Python runner to generate a CSV of all lexer tests
run-lexer-tests: $(TEST_LEXER_BIN) $(TEST_LEXER_PY_SCRIPT)
	$(TEST_LEXER_PY_SCRIPT) -p ./$(TEST_LEXER_BIN) -t $(LEXER_TEST_DIR) -o $(LEXER_CSV)

# Aggregate test target
test: run-lexer-tests

# ┌───────────────────────────────────────────────────────────────────────────┐
# │                                Clean Up                                   │
# └───────────────────────────────────────────────────────────────────────────┘

clean:
	rm -f $(TEST_LEXER_BIN) $(TEST_LEXER_BIN) # $(LEXER_CSV)
	rm -rf ${LEXER_DSYM}
