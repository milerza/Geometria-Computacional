# Makefile

# Compiler options
CXX = g++
CXXFLAGS = -std=c++11 -Wall -c -Iinclude 

# Source files
INCLUDE_FOLDER := ./include/
SRCS := $(wildcard src/*.cpp)

# Object files
OBJS := $(SRCS:.cpp=.o)

# Target executable
TARGET := tp01

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_FOLDER)

clean:
	rm -f $(OBJS) $(TARGET)

