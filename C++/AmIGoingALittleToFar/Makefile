OUT_DIR := ./out
$(shell mkdir -p $(OUT_DIR))

# compilers:
# g++					 : GNU C++ compiler
# x86_64-w64-mingw32-g++ : MinGW-w64 C++ compiler for 64-bit Windows
# i686-w64-mingw32-g++	 : MinGW-w64 C++ compiler for 32-bit Windows

# Compiler and flags
CXX := x86_64-w64-mingw32-g++ # Compiler
CXXFLAGS := \
	-Wall -Wextra \
	-O2 -frename-registers -flto -funroll-loops \
	-std=c++17 \
	-static-libgcc -static-libstdc++
TARGET := $(OUT_DIR)/main.exe

# source files
SRCS := \
	main.cpp \
	binarySearch.cpp \
	readFromFile.cpp \
	writeToFile.cpp


OBJS := $(SRCS:%.cpp=$(OUT_DIR)/%.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OUT_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean