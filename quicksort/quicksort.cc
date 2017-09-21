#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include "quicksort.h"
using namespace std;

//chooses random index between 0 to vector size - 1 
int choosePivot(int size) {
	srand(time(NULL));
	int random = rand() % size;
	return random;	
}

// partitions the vector.
// all elements before index pivot is less than or equal to the pivot value and 
// all elements after index pivot is greater than pivot value
// this is only true for index between [begin,end]
int partition(vector<int> &list, int begin, int end, int pivot) {
	int pivotValue = list[pivot];
	swap(list[begin],list[pivot]);

	int i = begin;
	int j = end;

	while(true) {
		while(list[i] <= pivotValue) i++;
		while(list[j] > pivotValue) j--;

		if(i > j) break;
		else swap(list[i],list[j]);
	}
	swap(list[begin],list[j]);
	return j;
}

// sorts the vector such that all elements are in ascending order.
// Complexity: O(nlogn)
void quickSortEncap(vector<int> &list, int begin, int end) {
	int size = end - begin + 1;
	if(size <= 1) return;
	int pivot = choosePivot(size) + begin;
	pivot = partition(list,begin,end,pivot);

	quickSortEncap(list,begin,pivot-1);
	quickSortEncap(list,pivot+1,end);
}

// for client purposes.
// the actual implementation is in quickSortEncap (see above)
void Quicksort::quickSort(vector<int> &list) {
	int size = list.size();

	if(size <= 1) return;

	quickSortEncap(list,0,size-1);
}	

