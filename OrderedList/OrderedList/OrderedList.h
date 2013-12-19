#ifndef _ORDERED_LIST_H_
#define _ORDERED_LIST_H_

#include <iostream>

class OrderedList {
	unsigned int size;
	unsigned int alloced;
	const unsigned int o_alloc;
	int* arr;
public:
	OrderedList();
	OrderedList(int capacity);
	~OrderedList();
	void put(int data);
	int decapitate();
	int decaudate();
	int removeAt(unsigned int const position);
	void freeUpASlot(unsigned int const position);
	void print();
	bool empty();
	void addCapacity();
	int& operator[](std::size_t index);
	int& operator=(int num);
};

#endif