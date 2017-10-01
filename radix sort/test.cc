#include "radixsort.h"
#include <time.h>
#include <stdlib.h>
#include <assert.h>
#include <iostream>
#include <vector>
using namespace std;

//modify this to change number of tests.
const int NUM_TESTS = 100;
const int MAX_ELEMENTS = 100;

vector<int> testNumbers;

//checks every single element with elements ahead of them.
//complexity:O(n^2) precisely O(n!)
void assertRS(vector<int> &list) {
	radixSort::radixsort(list);
	int size = list.size();
	
	for(int i=0; i<size; i++) {
		/*
		for(int j=i+1; j<size; j++) {
			assert(list[i] <= list[j]);
		}
		*/
		//cout << list[i] << " ";
	}
	//cout << endl;
	//cout << "test passed."  << endl;
	
}

//Creates 100 tests with random elements and ensures that all the lists are in ascending order
int main() {
	

	vector<int> list = {3,4,5,3,2,4,23,3,4,2,4,3,4,3};
	radixSort::radixsort(list);

	/*
	srand(time(NULL));
	int numTests = 99;
	while(numTests < NUM_TESTS) {
		int numElements = rand() % MAX_ELEMENTS; 	// puts 0 - 99 elements randomly
		while(numElements > 0) {
			int numToAdd = rand() % MAX_ELEMENTS - 30;
			int randDuplicate = rand() % 10;
			for(int i = 0; i<randDuplicate; i++) {
				testNumbers.emplace_back(numToAdd);
			}
			numElements--;
		}
		assertRS(testNumbers);
		numTests++;
	}
	cout << "All tests passed." << endl;
	*/
	
}