#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>

struct Node {
	int data;
	Node* next;
public:
	Node();
	Node(int data);
	Node(int data, Node* next);
	~Node();
	/* void append(int data);
	void insertAt(int data, unsigned int const position);
	int decaudate();
	int removeAt(unsigned int const position);
	int itemAtTail();
	int itemAt(unsigned int const position);
	bool contains(int const value);
	int length(); */
};

class LinkedList : Node {
	Node* head;
public:
	LinkedList();
	~LinkedList();
	void append(int data);
	void prepend(int data);
	void insertAt(int data, unsigned int position);
	int decaudate();
	int decapitate();
	int removeAt(unsigned int position);
	void clear();
	int itemAtHead();
	int itemAtTail();
	int itemAt(unsigned int position);
	bool contains(int const value);
	unsigned int length();
	void removeDuplicates();
	void print();
};

#endif _LINKED_LIST_H_