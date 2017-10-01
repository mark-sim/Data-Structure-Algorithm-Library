#include <vector>
#include <iostream>
#include "radixsort.h"
using namespace std;

const int NUM_BITS = 32;
const int RADIX = 2;


void countingsort(vector<int> &list, int size, int bitIndex) {

 	// set all the buckets to 0
 	int count[RADIX] = {0};
 	vector<int> bitValues;
 	// set occurence of each number [min,max] where count[0] is occurence of min
 	// and count[max-min] is occurence of max.
 	for(int i=0; i<size; i++) {
 		int bitValue = (list[i] >> bitIndex) & 1;
 		if(bitIndex == 31) bitValue = (bitValue ^ 1) & 1;
 		bitValues.emplace_back(bitValue);
 		count[bitValue]++;
 	}

 	// set the left boundary of each number.
 	count[1] = count[0];
 	count[0] = 0;

 	//modify list such that all elements are sorted.
 	vector<int> copyList = list;

 	for(int i=0; i<size; i++) {
 		int bitValue = bitValues[i];
 		list[count[bitValue]] = copyList[i];
 		count[bitValue]++;
 	}

}

void radixSort::radixsort(vector<int> &list) {

	int size = list.size();
	if(size <=1) return;

	for (int i=0; i<NUM_BITS; i++) {
		countingsort(list,size,i);
	}
}