#include <iostream>
#include "avl.h"
using namespace std;

#define int ERROR -50000;


AVL() : weight{ERROR},left{nullptr}, right{nullptr} {}

AVL(int key) : key{key}, weight{0}, left{nullptr}, right{nullptr} {}

//TODO
AVL(vector<int> list) {}
