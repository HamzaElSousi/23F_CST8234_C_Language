# Makefile

# Compiler and compiler flags
CC = gcc
CFLAGS = -Wall -std=c99 -pedantic

# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Source files and object files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(SOURCES:$(SRC_DIR)/%.c=%.o)

# Executable name
EXECUTABLE = arraym

# Dependency header files
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

all: $(EXECUTABLE)	

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) $(OBJECTS) -o $(EXECUTABLE)

%.o: $(SRC_DIR)/%.c $(DEPS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
