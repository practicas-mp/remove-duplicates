#include <iostream>
#include "util/measure.h"
#include "algorithms/naive.cpp"

using namespace std;

int main(int argc, char **argv){

	if (argc != 2){
		cerr << "Input size needed" << endl;
		return -1;
	}

	int input_size = atoi(argv[1]);

	int duration = measure::measure(removeDuplicates, input_size);

	cout << input_size << "\t" << duration << endl;
}