# 
# Generic Makefile
#
# To customize the name of your executable 
# change the variable TARGET_NAME 
#
# -----------------------------------------
# variables
# -----------------------------------------
PROJECT_ROOT := .
BIN_DIR := ./bin
TEST_DIR := ./test
BUILD_DIR := ./build
SRC_DIR := ./src
INC_DIR := ./include

RUN_ARGUMENTS := $(TEST_DIR)/verwandlung.txt
VALGRIND_OUTPUT := $(PROJECT_ROOT)/valgrind.txt

CC ?= cc
CFLAGS := -I$(INC_DIR) -Wall -c
LDFLAGS := -lconfig
LINT := splint
LINTFLAGS := -I$(INC_DIR) -posix-lib

# target to build - CHANGE
TARGET_NAME := myfile
TARGET := $(BIN_DIR)/$(TARGET_NAME)

# src files & obj files
SRC := $(wildcard src/*.c)
OBJ := $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# which files will be deleted by clean target
CLEAN_LIST := $(TARGET) $(OBJ)

# -----------------------------------------
# rules
# -----------------------------------------
# default rule
default: makedir all

# build target (linker)
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

# compile .c files
$(BUILD_DIR)/%.o: $(SRC)
	$(CC) $(CFLAGS) -o $@ $<

# run target
run: $(TARGET)
	export CONFIG_FILE=$(PROJECT_ROOT)/template.cfg; $(TARGET) $(RUN_ARGUMENTS)

# run linter
lint: $(SRC)
	$(foreach source, $(SRC), echo "Checking file $(source) ..."; $(LINT) $(LINTFLAGS) $(source);)

# run with valgrind
valgrind: $(TARGET)
	export APP_ROOT=$(PROJECT_ROOT);valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(VALGRIND_OUTPUT) $(TARGET)
	cat $(VALGRIND_OUTPUT)

# phony rules
.PHONY: makedir
makedir:
	@mkdir -p $(BIN_DIR) $(BUILD_DIR)

.PHONY: all
all: $(TARGET)

.PHONY: test
test:
	@cd $(TEST_DIR); ./runTests.sh

.PHONY: clean
clean:
	@echo CLEAN $(CLEAN_LIST)
	@rm -f $(CLEAN_LIST)
