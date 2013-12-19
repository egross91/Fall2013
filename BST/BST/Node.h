#ifndef _NODE_H_
#define _NODE_H_
	
#include <iostream>

struct Node {
	int data;
	int count;
	Node* leftChild;
	Node* rightChild;
public:
	Node();
	Node(int dat);
	Node(int dat, Node* lc, Node* rc);
	Node(int dat, int co);
	Node(int dat, int co, bool vis);
	Node(int dat, int co, bool vis, Node* lc, Node* rc);
	~Node();
	void insert(int value);
	bool contains(int value);
	Node* search(); // In the works.
	void clear();
	bool isRC();
	bool isLC();
	void inOrder();
	void preOrder();
	void postOrder();
};

#endif