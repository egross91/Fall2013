#include "OrderedList.h"

OrderedList::OrderedList() : size(0), alloced(16), o_alloc(16), arr(new int[alloced]) {  }
OrderedList::OrderedList(int capacity) : size(0), alloced(capacity), o_alloc(capacity), arr(new int[alloced]) {  }
OrderedList::~OrderedList()
{
	delete[] arr;
}
void OrderedList::put(int data)
{
	if (empty()) // Empty Case
		arr[0] = data;
	else if (data <= arr[0]) // Prepend Case
	{
		freeUpASlot(0);
		arr[0] = data;
	}
	else if (data >= arr[size-1]) // Append Case.
		arr[size] = data;
	else
	{
		for (unsigned i = 1; i != size; ++i)
		{
			if (arr[i-1] <= data && arr[i] >= data) // If we find where the element needs to go.
			{
				freeUpASlot(i);
				arr[i] = data;
				break;
			}
		}
	}
	++size; // Increment how many elements are in the ArrayList.
}
int OrderedList::removeAt(unsigned int const position)
{
	if (empty())
		throw ("The List is empty!\n");
	else if (position >= size)
		throw ("That position does not exist!\n");
	// otherwise
	int value = arr[position];
	for (unsigned i = position; i != size-1; ++i)
		arr[i] = arr[i+1];
	--size;
	return value;
}
void OrderedList::freeUpASlot(unsigned int const position)
{
	for (unsigned i = size; i != position; --i)
		arr[i] = arr[i-1];
}
void OrderedList::print()
{
	if (empty())
		throw ("The ArrayList is empty!\n");

	for (unsigned i = 0; i != size; ++i)
		std::cout << arr[i] << " ";
}
bool OrderedList::empty()
{
	return (size == 0);
}
void OrderedList::addCapacity()
{
	alloced +=16;
	int* tmp = new int[alloced];
	for (unsigned i = 0; i != size; ++i)
		tmp[i] = arr[i];

	delete[] arr;
	arr = new int[alloced];
	arr = tmp;
	delete[] tmp;
}
int& OrderedList::operator[](std::size_t index)
{
	return arr[index];
}
int& OrderedList::operator=(int num)
{
	throw ("This operator is not meant for this List.\n");
}