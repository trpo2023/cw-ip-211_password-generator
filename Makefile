CPP = g++
CFLAGS = -Wall -Werror
CPPFLAGS = -I src -MP -MMD

APP_NAME = Main_Code
LIB_NAME = Static_Libs
GRAPH_NAME = Password_Generator
DYNAMIC = Libs-for-ip211-password-generator
TEST_NAME = test

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

SRC_EXT = cpp

APP_SOURCES = $(shell find $(SRC_DIR)/$(APP_NAME) -name '*.$(SRC_EXT)')
APP_OBJECTS = $(APP_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

LIB_SOURCES = $(shell find $(SRC_DIR)/$(LIB_NAME) -name '*.$(SRC_EXT)')
LIB_OBJECTS = $(LIB_SOURCES:$(SRC_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(SRC_DIR)/%.o)

TEST_SOURCE = $(shell find $(TEST_DIR) -name '*.$(SRC_EXT)')
TEST_OBJECTS = $(TEST_SOURCE:$(TEST_DIR)/%.$(SRC_EXT)=$(OBJ_DIR)/$(TEST_DIR)/%.o)

DEPS = $(APP_OBJECTS:.o=.h) $(LIB_OBJECTS:.o=.h)


all: $(APP_PATH)

-include $(DEPS)

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CPP) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CPP) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

run:
	./bin/Main_Code

download:
	cd $(GRAPH_NAME)
	git submodule init
	git submodule update
	cp -r $(GRAPH_NAME)/$(DYNAMIC)/*  $(GRAPH_NAME)/

graph:
	./$(GRAPH_NAME)/$(GRAPH_NAME).exe

clean:
	$(RM) $(APP_PATH) $(OBJ_DIR)/*/*/*.[aod]
	$(RM) $(OBJ_DIR)/$(TEST_DIR)/*.[aod]
	$(RM) $(BIN_DIR)/*.[exed]
	$(RM) $(GRAPH_NAME)/*.dll
	$(RM) -rf $(GRAPH_NAME)/plugins
	$(RM) $(GRAPH_NAME)/README.md

test: $(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CPP) $(CFLAGS) $(CPPFLAGS) $^ -o $@ -lm
	$(BIN_DIR)/$(TEST_NAME)

.PHONY: all run download graph test clean