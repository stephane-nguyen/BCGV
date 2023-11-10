CC = gcc
CFLAGS =-W -Wall -pedantic
LDFLAGS = -L. -ldrapi
TARGET = app

################### directories ###################

# Current working directory
CWD:=$(shell pwd)
# directory of .cpp and .hpp source files
SRC_DIR := $(CWD)/src
# build directory
BUILD_DIR := $(CWD)/target
# project objects directory (contains .o files)
OBJ_DIR := $(BUILD_DIR)/obj
# libraries objects directory (contains .so, .a, .o, etc...)
LIBS_OBJ_DIR := $(CWD)/libs
# project dependencies directory (contains .d files)
DEPS_DIR := $(OBJ_DIR)
# Exectuable file
EXEC := $(CWD)/app.out

# Get all cpp files inside src directory with wildcard
SRC := $(call GET_FILES,$(SRC_DIR),*.cpp)
SRC := $(wildcard $(SRC_DIR)/*.c)

all: $(TARGET)

info:
    echo "SRC: $(SRC)"

$(TARGET): app.o
    $(CC) $(CFLAGS) -o $(TARGET) app.o $(LDFLAGS)

app.o: app.c data.h
    $(CC) $(CFLAGS) -c app.c

clean:
    rm -f *.o $(TARGET)

