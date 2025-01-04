# Compiler
CXX = g++

# Target executable
TARGET = bank_account

# Source files
SRCS = main.cpp BankAccount.cpp
HDRS = BankAccount.hpp
# Default target
all: $(TARGET)

# Rule to link the object files to create the executable
$(TARGET): $(SRCS) $(HDRS)
	$(CXX) -o $(TARGET) $(SRCS)

# Clean up the build
clean:
	rm -f $(TARGET)
