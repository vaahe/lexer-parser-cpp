# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Include directories
INCLUDES := -I.

# Source files
LEX_SRC := lex.yy.cc
YACC_SRC := parser.tab.cpp

# Object files
OBJ_FILES := lex.yy.o parser.tab.o

# Target executable
TARGET := my_parser.exe

# Phony target to build all
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(TARGET)

# Compile lex.yy.cc (Flex output)
lex.yy.o: $(LEX_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Compile parser.tab.cpp (Bison output)
parser.tab.o: $(YACC_SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJ_FILES) $(TARGET)

# Phony targets
.PHONY: all clean
