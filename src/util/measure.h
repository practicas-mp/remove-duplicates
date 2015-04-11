#ifndef __MEASURE_H__
#define __MEASURE_H__

#include <vector>
#include <chrono>
#include <ctime>
#include <climits>


using namespace std;
using namespace std::chrono;

namespace measure {
	
	vector<int> getInput(int input_size) {
		srand(time(0));
		vector<int> result;

		for(int i = 0; i < input_size; i++){
 			result.push_back(rand() % (input_size - 1));	// Make sure there is at least one duplicate
		}

		return result;
	}


	typedef vector<int> (*RemoveDuplicatesFunction)(vector<int>);

	int measure(RemoveDuplicatesFunction function, int input_size){

		vector<int> input = getInput(input_size);

		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		function(input);
		high_resolution_clock::time_point t2 = high_resolution_clock::now();

		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();

		return duration;
	}

}

#endif