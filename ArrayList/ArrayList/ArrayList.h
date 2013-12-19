#ifndef _ARRAY_LIST_H_
#define _ARRAY_LIST_H_

#include <iostream>

class ArrayList {
	unsigned int size; // How many elements are in the ArrayList and the last_index.
	unsigned int alloced; // How many spaces are allocated for the ArrayList.
	const unsigned int o_alloc; // To keep track what was originally allocated.
	int* arr; // The actual dynamic array.
public:
	ArrayList();
	ArrayList(int data);
	~ArrayList();
	void append(int data);
	void prepend(int data);
	void insertAt(int data, unsigned int const position);
	int decaudate();
	int decapitate();
	int removeAt(unsigned int const position);
	void clear();
	int itemAtHead();
	int itemAtTail();
	int itemAt(unsigned int const position);
	bool contains(const int value);
	unsigned int length();
	unsigned int capacity();
	unsigned int const alloc_capacity();
	void removeDuplicates();
	void print();
	void addCapacity();
	void reduceCapacity();
	bool empty();
};

#endif