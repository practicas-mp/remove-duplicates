CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc



all: bin/genera-duplicados

bin/genera-duplicados: src/util/genera-duplicados.cpp
	$(CC) $(CPPFLAGS) src/util/genera-duplicados.cpp -o $@

bin/naive: src/naive.cpp src/util/measure.h
	$(CC) $(CPPFLAGS) src/naive.cpp -o $@

bin/linear: src/linear.cpp src/util/measure.h
	$(CC) $(CPPFLAGS) src/linear.cpp -o $@

bin/see-measure-input: src/see-measure-input.cpp src/util/measure.h
	$(CC) $(CPPFLAGS) src/see-measure-input.cpp -o $@





measure-naive: bin/naive
	python scripts/executer.py bin/naive > data/naive.txt
	scripts/graph.sh data/naive.txt data/images/naive.png "Naive algorithm"

measure-linear: bin/linear
	python scripts/executer.py bin/linear > data/linear.txt
	scripts/graph.sh data/linear.txt data/images/linear.png "Linear algorithm"

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc