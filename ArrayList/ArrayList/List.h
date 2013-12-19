#ifndef _MY_LIST_H_
#define _MY_LIST_H_

template<typename T>
class List {
public:
	virtual ~List() = 0;
	virtual void append(T data) = 0;
	virtual void prepend(T data) = 0;
	virtual void insertAt(T data, unsigned int const position) = 0;
	virtual T decaudate() = 0;
	virtual T decapitate() = 0;
	virtual T removeAt(unsigned int const position) = 0;
	virtual void clear() = 0;
	virtual T itemAtHead() = 0;
	virtual T itemAtTail() = 0;
	virtual T itemAt(unsigned int const position) = 0;
	virtual bool contains(const T value) = 0;
	virtual unsigned int length() = 0;
	virtual unsigned int capacity() = 0;
	virtual unsigned int const alloc_capacity() = 0;
	virtual void removeDuplicates() = 0;
	virtual void print() = 0;
	virtual void addCapacity() = 0;
	virtual void reduceCapacity() = 0;
	virtual bool empty() = 0;
};

#endif