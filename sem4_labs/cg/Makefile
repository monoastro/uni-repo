CXX		:= g++
CXX_FLAGS 	:= -ggdb

BIN		:= bin
SRC		:= src
INCLUDE	:= include
LIB		:= lib

LIBRARIES	:= -lm -lgraph -lX11 -lSDL
EXECUTABLE	:= main


run: $(BIN)/$(EXECUTABLE)
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -I$(INCLUDE)/algorithms -L$(LIB) $^ -o $@ $(LIBRARIES)
