#include <iostream>
#include "util/measure.h"
#include <cassert>

using namespace std;


vector<int> seeMeasureInput(vector<int> original) {
	for (auto value : original){
		cout << value << " ";
	}

	cout << endl;

	return original;
}

int main(int argc, char **argv){

	if (argc != 2){
		cerr << "Input size needed" << endl;
		return -1;
	}

	int input_size = atoi(argv[1]);

	int duration = measure::measure(seeMeasureInput, input_size);

	cout << input_size << "\t" << duration << endl;
}