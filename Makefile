CC = gcc
CFLAGS = -Wall -Iheaders
LDFLAGS = -Llibs
LIBS = -l:drv_api.a -lgenerated

SRC_DIR = src
OBJ_DIR = target/obj
TARGET_DIR = target

# List all the .c files in the src directory
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)

# Create a list of corresponding .o files in the obj directory
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

TARGET = $(TARGET_DIR)/app

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	@mkdir -p $(TARGET_DIR)
	$(CC) $^ -o $@ $(LDFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET_DIR)

.PHONY: all clean