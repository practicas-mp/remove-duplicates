CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc



all: bin/genera-duplicados

bin/genera-duplicados: src/genera-duplicados.cpp
	$(CC) $(CPPFLAGS) src/genera-duplicados.cpp -o bin/genera-duplicados

doc:
	doxygen $(DOC)/doxys/Doxyfile

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc