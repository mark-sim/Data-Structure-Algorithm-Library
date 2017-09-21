#include <assert.h>
#include <vector>
#include <iostream>
#include "quickselect.h"
using namespace std;

int main() {
	vector<int> test1 = {10,-3,7,24,58,1262,65,0,-2353};
	assert(Quickselect::quickSelect(test1,2) == 0);
	cout << "Test1 passed." << endl;

	vector<int> test2 = {};
	try {
		Quickselect::quickSelect(test2,0);
		cout << "Test2 failed." << endl;
	} catch(...) {
		cout << "Test2 passed." << endl;
	}

	vector<int> test3 = {3};
	assert(Quickselect::quickSelect(test3,0) == 3);
	cout << "Test3 passed." << endl;

	vector<int> test4 = {2,4,3,4,2,1,4,5,3,4,2,4};
	assert(Quickselect::quickSelect(test4,4) == 3);
	cout << "Test4 passed." << endl;
}