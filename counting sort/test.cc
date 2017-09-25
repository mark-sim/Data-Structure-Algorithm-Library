#include <vector>
#include <iostream>
#include <assert.h>
#include "countingsort.h"
using namespace std;

void print(vector<int> &list) {
	int size = list.size();
	for(int i=0; i<size; i++) {
		cout << list[i] << " ";
	}
	cout << endl;
}


int main() {
	
	vector<int> test1 = {-10,5,2,4,3,5,-3,6,2,4,2,3,2};
	Countingsort::countingsort(test1);
	print(test1);
	

	vector<int> test2 = {0,6,6,2,4,2,2,3,4,1,1,1,2,3};
	Countingsort::countingsort(test2);
	print(test2);
	

	vector<int> test3 = {30,31,31,32,32,33,34,34,34,35,35,37,40};
	Countingsort::countingsort(test3);
	print(test3);

	vector<int> test4 = {30,33,50,34,35,38,37,37,38,38,40,45,50,10000};
	Countingsort::countingsort(test4);
	print(test4);

}