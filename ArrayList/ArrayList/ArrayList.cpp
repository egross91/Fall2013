#include "ArrayList.h"

ArrayList::ArrayList() : size(0), alloced(16), o_alloc(16), arr(new int[alloced]) { }
ArrayList::ArrayList(int capacity) : size(0), alloced(capacity), o_alloc(capacity), arr(new int[alloced]) 
{
	arr = new int[alloced];
}
ArrayList::~ArrayList()
{
	delete[] arr;
}
void ArrayList::append(int data)
{
	if (empty())
	{
		arr[0] = data;
		++size;
		return;
	}
	if (size == alloced) // If we are trying to add to a full list.
		addCapacity();

	*(arr + size) = data; // Add element to the end, and increase size by 1.
	++size;
}
void ArrayList::prepend(int data)
{
	if (empty())
		arr[0] = data;

	else if (size == 1) // If there's only one element, just do a simple swap.
	{
		int tmp = arr[0];
		arr[0] = data;
		arr[1] = tmp;
	}
	else
	{
		if (size == alloced) // The ArrayList is full, and we're trying to add more space elements.
			addCapacity();
		
		int tmp = arr[0]; // Save our old first element.
		arr[0] = data;	// Prepend()
		for (unsigned i = size; i != 1; --i) // Perform swaps to move items down the list.
			arr[i] = arr[i-1];
		arr[1] = tmp;
	}
	++size; // Increment the size for each case.
}
void ArrayList::insertAt(int data, unsigned int const position)
{
	if (empty() || position == 0)
		prepend(data);
	else if (position >= size)
		append(data); // Could throw exception.
	else
	{
		if (size == alloced) // TEST CASE
			addCapacity();
		int tmp = *(arr + position); // Save the current value in said position.
		*(arr + position) = data; // Insert the value at said position.
		for (unsigned i = size; i != position; --i) // Move everyting down.
			arr[i] = arr[i-1];
		arr[position+1] = tmp; // Make sure our list has all the elements that were there before the insertion.
		++size; // Increment the size for each case.
	}
}
int ArrayList::decaudate()
{
	if (empty())
		throw ("The ArrayList is empty!\n");
	else 
	{
		int* pval = arr + (size - 1); // Point to index in ArrayList.
		int value = *pval; // Store value we want to return.
		pval = nullptr; // Get rid of value in that index.
		--size; // Reduce the size by one.
		return value; // Return desired value.
	}
}
int ArrayList::decapitate()
{
	if (empty())
		throw ("The ArrayList is empty!\n");

	else if (size-- == 1)
	{
		int value = arr[0];
		delete[] arr;
		arr = new int[o_alloc];
		return value;
	}
	
	// otherwise
	int value = arr[0];
	for (unsigned i = 0; i != size-1; ++i) // Move everything down the list.
		arr[i] = arr[i+1];

	if (((alloced - size) > 24) && ((alloced-16) >= o_alloc))
		reduceCapacity();

	return value;
}
int ArrayList::removeAt(unsigned int const position)
{
	if (empty())
		throw ("The list is already empty!\n");
	else if (position > size) // If the index position is > where we have elements.
		throw ("That index does not exist!\n");
	
	// otherwise
	int value = *(arr + position);
	for (unsigned i = position; i != size-1; ++i)
		arr[i] = arr[i+1];

	if (((alloced - size--) > 24) && ((alloced-16) >= o_alloc))
		reduceCapacity();

	return value;
}
void ArrayList::clear()
{
	if (empty())
		throw ("The list is already empty!\n");

	delete[] arr; // Get rid of everything.
	arr = new int[o_alloc]; // Re-allocate the ArrayList with the original allocation.
	size = 0; // We have no more elements.
	alloced = o_alloc; // We only have the allocated space of the original allocation.
}
int ArrayList::itemAtHead()
{
	if (empty())
		throw ("The list is empty!\n");

	return arr[0];
}
int ArrayList::itemAtTail()
{
	if (empty())
		throw ("The list is empty!\n");

	return *(arr + (size-1));
}
int ArrayList::itemAt(unsigned int const position)
{
	if (empty())
		throw ("The list is already empty!\n");
	else if (position >= size) // The user is looking too far.
		throw ("There is nothing in that index!\n");

	return *(arr + position);
}
bool ArrayList::contains(const int value)
{
	for (unsigned i = 0; i != size; ++i)
		if (*(arr + i) == value)
			return true;

	return false;
}
// Returns the number of elements in it, not the capacity of the ArrayList.
unsigned int ArrayList::length()
{
	return size;
}
// Returns the number of allocated blocks in memory for the dynamic array.
unsigned int ArrayList::capacity()
{
	return alloced;
}
unsigned int const ArrayList::alloc_capacity()
{
	return o_alloc;
}
void ArrayList::removeDuplicates()
{
	if (empty())
		throw ("The list is empty!\n");
	else if (size == 1)
		throw ("The list only has one element!\n");
	
	// otherwise
	int* pbegin = arr;
	int* pend = arr + size; // One past the end.
	unsigned pos = 0;
	while (pbegin != pend)
	{
		int toDelete = *pbegin;
		int* phere = pbegin+1;
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
void ArrayList::print()
{
	if (empty())
		throw ("The ArrayList is empty!\n");

	for (unsigned i = 0; i != size; ++i)
		std::cout << *(arr + i) << " ";
	std::cout << "\n\n\n\n" << std::endl;
}
void ArrayList::addCapacity()
{
	alloced += 16; // We now have 16 more slots allocated than we did before.
	int* tmp = new int[alloced];  // To store our values temporarily.

	for (unsigned i = 0; i != size; ++i) // Copy what we have so far.
		*(tmp + i) = *(arr + i);

	delete[] arr; // Delete backing array.
	arr = new int[alloced]; // Re-create the ArrayList with more space.
	for (unsigned i = 0; i != size; ++i) // Fill the ArrayList again.
		*(arr + i) = *(tmp + i);

	delete[] tmp; // Get rid of what we needed to copy everything over.
}
void ArrayList::reduceCapacity()
{
	alloced -= 16;
	int* tmp = new int[alloced];

	for (unsigned i = 0; i != size; ++i)
		*(tmp + i) = *(arr + i);

	delete[] arr;
	arr = new int[alloced];
	for (unsigned i = 0; i != size; ++i)
		*(arr + i) = *(tmp + i);

	delete tmp;
}
bool ArrayList::empty()
{
	return (size == 0);
}