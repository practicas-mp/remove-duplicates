#include <vector>
#include "../util/measure.h"
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