#ifndef _TARRAYLIST_H_
#define _TARRAYLIST_H_

#include <iostream>
#include "List.h"

template<typename T>
class ArrayList : public List<T> {
	unsigned int size; // How many elements are in the ArrayList and the last_index.
	unsigned int alloced; // How many spaces are allocated for the ArrayList.
	const unsigned int o_alloc; // To keep track what was originally allocated.
	T* arr; // The actual dynamic array.
public:
	ArrayList() : size(0), alloced(16), o_alloc(16), arr(new T[alloced]) { } // size(0), alloced(16), o_alloc(16), arr(new T[alloced]) { }
	ArrayList(unsigned int const capacity) : size(0), alloced(capacity), o_alloc(capacity), arr(new T[alloced]) { } // size(0), alloced(capacity), o_alloc(capacity), arr(new T[alloced]) 
	~ArrayList()
	{
		delete[] arr;
	}
	void append(T data)
	{
		if (empty())
		{
			arr[0] = data;
			++size;
			return;
		}
		if (size == alloced) // If we are trying to add to a full list.
			addCapacity();

		arr[size] = data; // Add element to the end, and increase size by 1.
		++size;
	}
	void prepend(T data)
	{
		if (empty())
			arr[0] = data;

		else if (size == 1) // If there's only one element, just do a simple swap.
		{
			T tmp = arr[0];
			arr[0] = data;
			arr[1] = tmp;
		}
		else
		{
			if (size == alloced) // The ArrayList is full, and we're trying to add more space elements.
				addCapacity();
		
			T tmp = arr[0]; // Save our old first element.
			arr[0] = data;	// Prepend()
			for (unsigned i = size; i != 1; --i) // Perform swaps to move items down the list.
				arr[i] = arr[i-1];
			arr[1] = tmp;
		}
		++size; // Increment the size for each case.
	}
	void insertAt(T data, unsigned int const position)
	{
		if (empty() || position == 0)
			prepend(data);
		else if (position >= size)
			append(data); // Could throw exception.
		else
		{
			if (size == alloced) // TEST CASE
				addCapacity();
			T tmp = *(arr + position); // Save the current value in said position.
			*(arr + position) = data; // Insert the value at said position.
			for (unsigned i = size; i != position; --i) // Move everyting down.
				arr[i] = arr[i-1];
			arr[position+1] = tmp; // Make sure our list has all the elements that were there before the insertion.
			++size; // Increment the size for each case.
		}
	}
	T decaudate()
	{
		if (empty())
			throw ("The ArrayList is empty!\n");

		// otherwise
		T* pval = arr + (size - 1); // PoT to index in ArrayList.
		T value = *pval; // Store value we want to return.
		pval = nullptr; // Get rid of value in that index.
		--size; // Reduce the size by one.
		return value; // Return desired value.
	}
	T decapitate()
	{
		if (empty())
			throw ("The ArrayList is empty!\n");
	
		else if (size == 1)
		{
			--size;
			T value = arr[0];
			delete[] arr;
			arr = new T[o_alloc];
			return value;
		}
		
		// otherwise
		--size;
		T value = arr[0];
		for (unsigned i = 0; i != size; ++i) // Move everything down the list.
			arr[i] = arr[i+1];

		if (((alloced - size) > 24) && ((alloced-16) >= o_alloc))
			reduceCapacity();

		return value;
	}
	T removeAt(unsigned int const position)
	{
		if (empty())
			throw ("The list is already empty!\n");
		else if (position > size) // If the index position is > where we have elements.
			throw ("That index does not exist!\n");
		
		// otherwise
		--size;
		T value = arr[position];
		for (unsigned i = position; i != size; ++i)
			arr[i] = arr[i+1];

		if (((alloced - size) > 24) && ((alloced-16) >= o_alloc))
			reduceCapacity();
		
		return value;
	}
	void clear()
	{
		if (empty())
			throw ("The list is already empty!\n");

		delete[] arr; // Get rid of everything.
		arr = new T[o_alloc]; // Re-allocate the ArrayList with the original allocation.
		size = 0; // We have no more elements.
		alloced = o_alloc; // We only have the allocated space of the original allocation.
	}
	T itemAtHead()
	{
		if (empty())
			throw ("The list is empty!\n");

		return arr[0];
	}
	T itemAtTail()
	{
		if (empty())
			throw ("The list is empty!\n");

		return arr[size-1];
	}
	T itemAt(unsigned int const position)
	{
		if (empty())
			throw ("The list is already empty!\n");
		else if (position >= size) // The user is looking too far.
			throw ("There is nothing in that index!\n");

		return arr[position];
	}
	bool contains(const T value)
	{
		for (unsigned i = 0; i != size; ++i)
			if (arr[i] == value)
				return true;

		return false;
	}
	// Returns the number of elements in it, not the capacity of the ArrayList.
	unsigned int length()
	{
		return size;
	}
	// Returns the number of allocated blocks in memory for the dynamic array.
	unsigned int capacity()
	{
		return alloced;
	}
	unsigned int const alloc_capacity()
	{
		return o_alloc;
	}
	void removeDuplicates()
	{
		if (empty())
			throw ("The list is empty!\n");
		else if (size == 1)
			throw ("The list only has one element!\n");
	
		// otherwise
		T* pbegin = arr;
		T* pend = arr + size; // One past the end.
		unsigned pos = 0;
		while (pbegin != pend)
		{
			T toDelete = *pbegin;
			T* phere = pbegin+1;
			++pos;
			unsigned index = pos;
			while (phere != pend)
			{
				if (*phere++ == toDelete)
				{
					for (unsigned i = index; i != size-1; ++i)
						*(arr + i) = *(arr + (i+1));
					--size;
				}
				++index;
			}
			++pbegin;
		}
	
		if (((alloced - size) > 24) && ((alloced-16) >= o_alloc))
			reduceCapacity();	
	}
	void print()
	{
		if (empty())
			throw ("The ArrayList is empty!\n");

		for (unsigned i = 0; i != size; ++i)
			std::cout << arr[i] << " ";
		std::cout << "\n\n\n\n" << std::endl;
	}
	void addCapacity()
	{
		alloced += 16; // We now have 16 more slots allocated than we did before.
		T* tmp = new T[alloced];  // To store our values temporarily.

		for (unsigned i = 0; i != size; ++i) // Copy what we have so far.
			*(tmp + i) = *(arr + i);

		delete[] arr; // Delete backing array.
		arr = new T[alloced]; // Re-create the ArrayList with more space.
		for (unsigned i = 0; i != size; ++i) // Fill the ArrayList again.
			*(arr + i) = *(tmp + i);

		delete[] tmp; // Get rid of what we needed to copy everything over.
	}
	void reduceCapacity()
	{
		alloced -= 16;
		T* tmp = new T[alloced];

		for (unsigned i = 0; i != size; ++i)
			*(tmp + i) = *(arr + i);

		delete[] arr;
		arr = new T[alloced];
		for (unsigned i = 0; i != size; ++i)
			*(arr + i) = *(tmp + i);

		delete tmp;
	}
	bool empty()
	{
		return (size == 0);
	}
};
#endif