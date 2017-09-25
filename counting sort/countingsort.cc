#include <vector>
#include "countingsort.h"
#include <iostream>
using namespace std;

void Countingsort::countingsort(vector<int> &list) {
	int size = list.size();
	if(size <= 1) return;

	int max = list[0];
	int min = list[0];

	// finding out maximum and minimum value in the list.
	// takes O(n) time.
	for(int i=1; i<size; i++) {
		max = (list[i] > max) ? list[i] : max;
		min = (list[i] < min) ? list[i] : min;
 	}

 	// k is number of buckets that needs to be created.
 	int k = max - min + 1;
 	// set all the buckets to 0
 	int count[k] = {0};

 	// set occurence of each number [min,max] where count[0] is occurence of min
 	// and count[max-min] is occurence of max.
 	for(int i=0; i<size; i++) {
 		int countIndex = list[i] - min;
 		count[countIndex]++;
 	}

 	// set the left boundary of each number.
 	int temp = count[0];
 	count[0] = 0;
 	for(int i=0; i<k-1; i++) {
 		int temp2 = count[i+1];
 		count[i+1] = count[i] + temp;
 		temp = temp2;
 	}

 	//modify list such that all elements are sorted.
 	vector<int> copyList = list;
 	for(int i=0; i<size; i++) {
 		int value = copyList[i] - min;
 		list[count[value]] = copyList[i];
 		count[value]++;
 	}
}