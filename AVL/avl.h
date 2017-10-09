#ifndef __AVL_TREE_H
#define __AVL_TREE_H

#include <vector>

	class AVL {
		int key;
		int weight;
		AVL *left;
		AVL *right;
	public:
		//empty constructor
		AVL();
		//one key
		AVL(int key);
		//list
		AVL(std::vector<int> list);
	};


#endif