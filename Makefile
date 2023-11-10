CC = gcc
CFLAGS = -Wall -Iheaders
LDFLAGS = -Llibs
# LIBS = -lYourLibraryName

SRC_DIR = src
OBJ_DIR = target/obj
HEADER_DIR = headers
LIB_DIR = libs
TARGET_DIR = target

# List all the .c files in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Create a list of corresponding .o files in the obj directory
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = $(TARGET_DIR)/app

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(TARGET_DIR)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

.PHONY: all clean
