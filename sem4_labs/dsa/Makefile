CXX		:= g++
CXX_FLAGS 	:= -Wall -std=c++17 -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:=
EXECUTABLE	:= main


run: $(BIN)/$(EXECUTABLE)
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/data_structures -L$(LIB) $^ -o $@ $(LIBRARIES)
