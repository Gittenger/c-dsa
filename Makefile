# -- config --
CC 				:= gcc
CSTD			:= c17
WARN			:= -Wall -Wextra -Wpedantic
OPT				:= -O2
INCLUDE			:= -Iinclude
CFLAGS			:= -std=$(CSTD) $(WARN) $(OPT) $(INCLUDE)
DBFLAGS 		:= -O0 -g -DDEBUG

BUILD_DIR 		:= build
OBJ_DIR			:= $(BUILD_DIR)/obj
APP_BIN			:= $(BUILD_DIR)/app
TEST_BIN		:= $(BUILD_DIR)/tests

# Discover sources
SRC 			:= $(shell find src -name '*.c')
SRC_OBJ   := $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRC))
TEST_SRC  := $(wildcard tests/*.c)
TEST_OBJ  := $(patsubst tests/%.c,$(OBJ_DIR)/tests/%.o,$(TEST_SRC))

# Default target: run tests
.PHONY: default
default: test

# ---- build rules ----
$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/tests/%.o: tests/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# App (optional)
$(APP_BIN): $(SRC_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

# All source objs except main.o
SRC_OBJ_NO_MAIN := $(filter-out $(OBJ_DIR)/main.o,$(SRC_OBJ))

$(TEST_BIN): $(SRC_OBJ_NO_MAIN) $(TEST_OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $^ -o $@

# ---- convenience targets ----
.PHONY: build run test testrun debug debug-tests clean veryclean

build: $(APP_BIN)

run: $(APP_BIN)
	$(APP_BIN)

test: $(TEST_BIN)
	@echo "[run tests]"
	@$(TEST_BIN)

testrun: test

debug: CFLAGS := $(filter-out -O2,$(CFLAGS)) $(DBGFLAGS)
debug: clean $(APP_BIN)
	$(APP_BIN)

debug-tests: CFLAGS := $(filter-out -O2,$(CFLAGS)) $(DBGFLAGS)
debug-tests: clean $(TEST_BIN)
	$(TEST_BIN)

clean:
	@rm -rf $(OBJ_DIR)

veryclean: clean
	@rm -rf $(BUILD_DIR)
