#include <vector>
#include <iostream>
#include "bst.h"
using namespace std;





int main() {

	//test1 checks deletion of a node when the node has no children.
	vector<int> test1 = {0,3,4,5,6,7,8,9,2,-5,-7,1};
	BST *bst = new BST{test1};
	cout << "original list: ";
	bst->print(bst);
	cout << endl;
	bst->deleteKey(1,bst);
	cout << "1 is deleted" << endl;
	bst->print(bst);
	cout << endl;
	//test2 checks deletion of a node when the node has a left child
	bst->deleteKey(-5,bst);
	cout << "-5 is deleted" << endl;
	bst->print(bst);
	cout << endl;
	//test3 checks deletion of a node when the node has a right child
	bst->deleteKey(5,bst);
	cout << "5 is deleted" << endl;
	bst->print(bst);
	cout << endl;
	//test4 checks deletion of a node when the node has two children and 
	//the successor is the right child.
	bst->deleteKey(3,bst);
	cout << "3 is deleted" << endl;
	bst->print(bst);
	cout << endl;
	//test5 checks deletion of a node when the node has two children and
	//the successor isn't the right child.
	vector<int> test2 = {0,10,20,-10,-20,30,40,15,14,13,16,17,18};
	BST *bst2 = new BST{test2};
	cout << "original list: ";
	bst2->print(bst2);
	cout << endl;
	bst2->deleteKey(10,bst2);
	cout << "10 is deleted" << endl;
	bst2->print(bst2);
	cout << endl;	

	bst->freeBST(bst);
	bst2->freeBST(bst2);


}