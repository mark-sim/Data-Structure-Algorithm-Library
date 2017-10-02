#include <vector>
#include <iostream>
#include "bst.h"
using namespace std;

BST::BST(int key) : key{key}, left{nullptr}, right{nullptr} {}

BST::BST(vector<int> &list) : key{list[0]}, left{nullptr}, right{nullptr} {
	for(auto it = list.begin() + 1; it != list.end(); ++it) {
		int keyToBeInserted = *it;
		BST::insert(keyToBeInserted);
	}

}

void BST::swap(BST *r) {
	int tempKey = this->key;
	this->key = r->key;
	r->key = tempKey;
}

void BST::insert(int keyToBeInserted) {
	if(key < keyToBeInserted && right) {
			right->insert(keyToBeInserted);
		} else if (key > keyToBeInserted && left) {
			left->insert(keyToBeInserted);
		} else if (key < keyToBeInserted && !right) {
			BST *insertion = new BST{keyToBeInserted};
			right = insertion;
		} else if (key > keyToBeInserted && !left) {
			BST *insertion = new BST{keyToBeInserted};
			left = insertion;
		}
}

void BST::print(BST *node) {
	if(node == nullptr) return;
	print(node->left);
	cout << node->key << " ";
	print(node->right);
}

void BST::freeBST(BST *node) {
	if(node == nullptr) return;
	freeBST(node->left);
	BST *tmp = node->right;
	free(node);
	freeBST(tmp);
}


BST *BST::deleteKey(int keyToBeDeleted, BST *root) {
	if(root == nullptr) return root;

	if(root->key != keyToBeDeleted) {
		if(root->key < keyToBeDeleted) {
			root->right = deleteKey(keyToBeDeleted,root->right);
			return root;
		} else {
			root->left = deleteKey(keyToBeDeleted,root->left);
			return root;
		}
	}

	// if keyToBeDeleted is a leaf, free the node and return nullptr
	if(root->left == nullptr && root->right == nullptr) {
		free(root);
		return nullptr;
	}

	// if keyToBeDeleted has one child, delete the node and move the child up.
	if(root->left == nullptr) {
		BST *temp = root->right;
		free(root);
		return temp;
	} else if(root->right == nullptr) {
		BST *temp = root->left;
		free(root);
		return temp;
	}

	// if keyToBeDeleted has two children, swap with the successor then delete
	BST *temp = root;
	root = root->right;
	while(root->left) {
		root = root->left;
	}
	temp->swap(root);
	temp->right = deleteKey(keyToBeDeleted, temp->right);
	return temp;

}

bool BST::search(int key) {
	if(this->key == key) return true;
	else if (this->key > key && left) return left->search(key);
	else if (this->key < key && right) return right->search(key);
	else return false;
}

