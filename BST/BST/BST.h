#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "Node.h"

class BST : Node { 
	Node* root;
	size_t num_nodes;
public:
	BST();
	~BST();
	void insert(int value);
	void remove(int value);
	bool contains(int value);
	size_t size();
	void printContents();
	size_t height();
private:
	size_t findHeight(Node* here);
	bool empty();
	void inOrder();
	void preOrder();
	void postOrder();
};

#endif