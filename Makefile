# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra
LDFLAGS = 

# Source files
SRCS = main.c pacient.c machine.c exam.c

# Object files
OBJS = $(SRCS:.c=.o)

# Executable name
TARGET = test_main

# Phony targets
.PHONY: all compile run clean

# Default target (compile and run)
all: compile run

# Explicit compile target (produces the target program)
compile: $(TARGET)

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)
