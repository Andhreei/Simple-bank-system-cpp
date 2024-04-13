# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall -Wextra

# Source directories
SRC_DIRS = Account Bank System

# Source files
SRCS := $(shell find $(SRC_DIRS) -name '*.cpp')

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET = system

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile source files
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	$(RM) $(TARGET) $(OBJS)

