CXX      := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iinclude
SRC      := $(wildcard src/*.cpp)
OBJ      := $(SRC:.cpp=.o)
EXEC     := tamagotchi.exe

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del /Q src\*.o 2>nul & del /Q $(EXEC) 2>nul

.PHONY: all clean