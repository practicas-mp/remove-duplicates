CC = g++
CPPFLAGS = -Wall -std=c++0x -g -I$(INCLUDE) -I$(SRC)
SRC = ./src
INCLUDE = ./include
OBJ = ./obj
BIN = ./bin
DOC = ./doc



install: 
	mkdir -p bin
	mkdir -p data/images 

bin/genera-duplicados: src/util/genera-duplicados.cpp
	$(CC) $(CPPFLAGS) src/util/genera-duplicados.cpp -o $@

bin/naive: src/naive.cpp src/util/measure.h src/algorithms/naive.cpp
	$(CC) $(CPPFLAGS) src/naive.cpp -o $@

bin/linear: src/linear.cpp src/util/measure.h src/algorithms/linear.cpp
	$(CC) $(CPPFLAGS) src/linear.cpp -o $@

bin/divide-and-conquer: src/divide_and_conquer.cpp src/util/measure.h src/algorithms/divide_and_conquer.cpp
	$(CC) $(CPPFLAGS) src/divide_and_conquer.cpp -o $@


bin/see-measure-input: src/see-measure-input.cpp src/util/measure.h
	$(CC) $(CPPFLAGS) src/see-measure-input.cpp -o $@


measure: measure-naive measure-linear measure-divide-and-conquer


measure-naive: bin/naive
	python scripts/executer.py bin/naive > data/naive.txt
	scripts/graph.sh data/naive.txt data/images/naive.png "Naive algorithm"

measure-linear: bin/linear
	python scripts/executer.py bin/linear > data/linear.txt
	scripts/graph.sh data/linear.txt data/images/linear.png "Linear algorithm"

measure-divide-and-conquer: bin/divide-and-conquer
	python scripts/executer.py bin/divide-and-conquer > data/divide-and-conquer.txt
	scripts/graph.sh data/divide-and-conquer.txt data/images/divide-and-conquer.png "Divide y vencerás"

bin/test: src/tests/test.cpp bin/naive bin/linear 
	$(CC) $(CPPFLAGS) src/tests/test.cpp -o $@	

clean:
	rm -f $(OBJ)/*

mrproper: clean
	rm -fR $(BIN)/* $(DOC)/doxygen

.PHONY: all clean mrproper doc