# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Executable name
TARGET = university_system

# Source files
SOURCES = main.cpp University.cpp Department.cpp Course.cpp Student.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default target
all: $(TARGET)
	./$(TARGET)

# Rule to link the object files into the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS)

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	rm -f $(TARGET) $(OBJECTS)
