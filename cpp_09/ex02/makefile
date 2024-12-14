# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Object files
OBJ = main.o

# Executable name
TARGET = PmergeMe

# Default target: Build the program
all: $(TARGET)

# Link the object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

# Compile the object files
main.o: main.cpp PmergeMe.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Clean up object files and executable
clean:
	rm -f $(OBJ) $(TARGET)

# Remove only the object files
fclean:
	rm -f $(OBJ)

# Remove the executable and object files
re: clean all

# Ensure the Makefile works properly in case of no action
.PHONY: all clean fclean re
