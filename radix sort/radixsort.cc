#include <vector>
#include <iostream>
#include "radixsort.h"
using namespace std;

const int NUM_BITS = 32;
const int RADIX = 2;


void countingsort(vector<int> &list, int size, int bitIndex) {

 	// set all the buckets to 0 in this case it's a binary number with radix of 2
 	int count[RADIX] = {0};
 	// save all the bits in this vector so you don't have to do it again
 	vector<int> bitValues;
 	// set occurence of each number [0,1] to the corresponding bucket
 	// if bitindex is 31, it represents whether the integer is negative (1) or positive (0).
 	// Since negative number has to come before positive number, simply negate the Most Significant Bit
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

	//Run countingsort starting from least siginificant bit all the way upto most siginificant bit.
	//Since countingsort is in-place, it will sort all the elements.
	for (int i=0; i<NUM_BITS; i++) {
		countingsort(list,size,i);
	}
}