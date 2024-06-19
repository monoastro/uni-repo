CXX		:= g++
CXX_FLAGS 	:= -Wall -Wextra -Wpedantic -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


run: $(BIN)/$(EXECUTABLE)
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp 
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/algorithms -L$(LIB) $^ -o $@ $(LIBRARIES)
