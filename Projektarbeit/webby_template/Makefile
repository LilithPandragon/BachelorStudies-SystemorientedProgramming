# tool macros

# path macros
PROJECT_ROOT := .
BIN_DIR := ./bin
TEST_DIR := ./test
BUILD_DIR := ./build
SRC_DIR := ./src
INC_DIR := ./include

RUN_ARGUMENTS := 
VALGRIND_OUTPUT := $(PROJECT_ROOT)/valgrind.txt

CC ?= cc
CFLAGS := -I$(INC_DIR) -Wall -c
LDFLAGS := -lconfig
LINT := splint
#LINTFLAGS := -I$(INC_DIR) -quiet -weak -posix-lib
LINTFLAGS := -I$(INC_DIR) -posix-lib 

# compile macros
TARGET_NAME := webby
TARGET := $(BIN_DIR)/$(TARGET_NAME)
TARGET_DEBUG := $(DBG_PATH)/$(TARGET_NAME)

# src files & obj files
SRC := $(wildcard src/*.c)
INC := $(wildcard include/*.h)
OBJ := $(addprefix $(BUILD_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))

# clean files list
CLEAN_LIST := $(TARGET) $(OBJ)

# default rule
default: makedir all

# non-phony targets
$(TARGET): $(OBJ)
	$(CC) -o $@ $(OBJ) $(LDFLAGS)

#$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c* 
#$(BUILD_DIR)/%.o: $(SRC) $(INC)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c* $(INC_DIR)/%.h*
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	export WEBBY_ROOT=$(PROJECT_ROOT); $(TARGET) $(RUN_ARGUMENTS)

lint: $(SRC)
	$(foreach source, $(SRC), echo "Checking file $(source) ..."; $(LINT) $(LINTFLAGS) $(source);)

valgrind: $(TARGET)
	export WEBBY_ROOT=$(PROJECT_ROOT);valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=$(VALGRIND_OUTPUT) $(TARGET)
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
