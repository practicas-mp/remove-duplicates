#include <unordered_set>
#include <vector>

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