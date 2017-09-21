#include <time.h>
#include <stdlib.h>
#include <stdexcept>
#include <algorithm>
#include "quickselect.h"
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

// returns the element that should be in index (ranges from [0,size-1]) when sorted.
// Complexity: O(n)
int quickSelectEncap(vector<int> &list, int index, int begin, int end) {
	int size = end - begin + 1;
	int pivot = choosePivot(size) + begin;
	pivot = partition(list,begin,end,pivot);

	if(pivot == index) return list[pivot];
	if(index < pivot) return quickSelectEncap(list,index,begin,pivot-1);
	else return quickSelectEncap(list,index,pivot+1,end);
}

// for client purposes.
// the actual implementation is in quickSelecttEncap (see above)
int Quickselect::quickSelect(vector<int> &list, int index) {
	int size = list.size();

	if(index < 0 || index > size-1) throw invalid_argument("index must be in range");

	return quickSelectEncap(list,index,0,size-1);
}