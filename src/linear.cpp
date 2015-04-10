#include <iostream>
#include "util/measure.h"
#include <cassert>
#include <unordered_set>

using namespace std;


vector<int> removeDuplicates(vector<int> original) {
	vector<int> result;
	unordered_set<int> already_found;

	for(int number : original){

		if (already_found.find(number) == already_found.end()){
			already_found.insert(number);
			result.push_back(number);
		}

	}

	return result;
}

int main(int argc, char **argv){

	if (argc != 2){
		cerr << "Input size needed" << endl;
		return -1;
	}

	int input_size = atoi(argv[1]);

	int duration = measure::measure(removeDuplicates, input_size);

	cout << input_size << "\t" << duration << endl;
}