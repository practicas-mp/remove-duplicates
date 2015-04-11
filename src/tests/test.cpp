#include <iostream>
#include <vector>
#include "algorithms/naive.cpp"

using namespace std;

void printVector(vector<int> numbers){
	cout << "{ ";
	for (auto number: numbers){
		cout << number << " ";
	}

	cout << "}" << endl;
} 

int main(int argc, char **argv){

	int prueba1[] = {1,2,3,4,5,5,2,6,4};
	int prueba2[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,6};
	vector<int> numeros(prueba1, prueba1 + 8);
	vector<int> numeros2(prueba2, prueba2 + 16);

	printVector(numeros);
	printVector(removeDuplicates(numeros));

	cout << endl;
	printVector(numeros2);
	printVector(removeDuplicates(numeros2));

	
}