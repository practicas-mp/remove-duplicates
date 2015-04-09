#include <iostream>
#include "util/measure.h"
#include <cassert>

using namespace std;


vector<int> removeDuplicates(vector<int> original) {
	assert(!original.empty());

	vector<int> result;

	result.push_back(original.front());

	for(int i = 1; i < original.size(); i++){
		bool should_be_added = true;

		for(int j = 0; j < result.size(); j++){
			if (result[j] == original[i]){
				should_be_added = false;
				break;
			}
		}

		if (should_be_added) result.push_back(original[i]);
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