#ifndef __BST_H__
#define __BST_H__

#include <vector>

class BST {
	private:
		int key;
		BST *left;
		BST *right;
	public:
		// user input a list. This data will change. If needed in the future, keep a copy of it.
		// cannot be an empty list.
		BST(std::vector<int> &list);
		// one key at construction
		BST(int key);
		// copy assignment operator
		void swap(BST *r);
		// inserting a key to a BST
		void insert(int keyToBeInserted);
		// deleting a key to a BST
		// Assumption: keyToBeDeleted is in the BST
		BST *deleteKey(int keyToBeDeleted, BST *root);
		// search for a key on a BST. returns true if found otherwise false.
		bool search(int key);
		//prints the BST in-order; Always called on the root.
		void print(BST *node);
};


#endif