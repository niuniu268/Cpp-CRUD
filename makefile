# Makefile

# Compiler
CXX := g++

# Compiler flags
CXXFLAGS := -std=c++11 -Wall

# Source files
SRCS := main.cpp manage.cpp accountsCredit.cpp

# Object files
OBJS := $(SRCS:.cpp=.o)

# Executable
TARGET := crud

# Build rule for the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Build rule for object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
