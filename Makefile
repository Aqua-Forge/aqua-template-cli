# Aqua Template project makefile

# Compiler / Linker configs
CC        := g++
CC_FLAGS  := -c         \
             -W         \
						 -std=c++17 \
            #  -Wall     \
            #  -ansi     \
            #  -pedantic \

# Directories
SRC_DIR      := src
INCLUDE_DIR  := include
LIB_DIR      := lib
BIN_DIR      := bin
OBJ_DIR      := build

# Filenames
TARGET       := main
SRC          := $(wildcard $(SRC_DIR)/*.cpp)
H_SRC        := $(wildcard $(INCLUDE_DIR)/*.hpp)
OBJ          := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

#
# Compilation and linking
#
all: binFolder objFolder $(TARGET)

$(TARGET): $(OBJ)
	@echo "🚀 Building binary \"$@\" using G++ linker..."
	@$(CC) $^ -o $(BIN_DIR)/$@
	@echo "🎇 Build complete!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "🪛  Compiling object file: $@..."
	@$(CC) $(CC_FLAGS) $< -I $(INCLUDE_DIR)/ -o $@

objFolder:
	@mkdir -p $(OBJ_DIR)

binFolder:
	@mkdir -p $(BIN_DIR)

clean:
	@echo "🧹 Cleaning..."
	@rm -r $(OBJ_DIR)
	@rm -r $(BIN_DIR)
	@echo "🧹 Done!"

# Running the project
run:
	@./$(BIN_DIR)/$(TARGET)

.PHONY: all clean run