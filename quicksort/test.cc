#include "quicksort.h"
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <vector>
using namespace std;

//modify this to change number of tests.
const int NUM_TESTS = 100;
const int MAX_ELEMENTS = 100;

vector<int> testNumbers;

//checks every single element with elements ahead of them.
//complexity:O(n^2) precisely O(n!)
void assertQS(vector<int> &list) {
	Quicksort::quickSort(list);
	int size = list.size();
	
	for(int i=0; i<size; i++) {
		for(int j=i+1; j<size; j++) {
			assert(list[i] <= list[j]);
		}
	}
	cout << "test passed."  << endl;
	
}

//Creates 100 tests with random elements and ensures that all the lists are in ascending order
int main() {
	srand(time(NULL));
	int numTests = 0;
	while(numTests < NUM_TESTS) {
		int numElements = rand() % MAX_ELEMENTS; 	// puts 0 - 99 elements randomly
		while(numElements > 0) {
			int numToAdd = rand() % MAX_ELEMENTS - 30;
			testNumbers.emplace_back(numToAdd);
			numElements--;
		}
		assertQS(testNumbers);
		numTests++;
	}
	cout << "All tests passed." << endl;
}
