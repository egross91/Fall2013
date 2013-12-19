#include "LinkedList.h"

/** 
 ** NODE FUNCTIONS 
 **/
Node::Node() // Default.
{ 
	this->next = nullptr; 
}
Node::Node(int data) // Initializer.
{
	this->data = data;
	this->next = nullptr;
}
Node::Node(int data, Node* next) // Initializer.
{
	this->data = data;
	this->next = next;
}
Node::~Node() { };


/* void Node::append(int data)
{
	if (next != nullptr) // We're not at the end.
		next->append(data);
	else // BASE CASE
		next = new Node(data);
}
void Node::insertAt(int data, unsigned int const position)
{
	if (position == 1 || next == nullptr) // BASE CASE - Don't like how this is setup, but the notes had it this way.
		next = new Node(data, next);
	else // RECURSIVE STEP
		next->insertAt(data, position-1);
}
int Node::decaudate()
{
	if (next->next != nullptr) // RECURSIVE STEP
		return next->decaudate();
	else // BASE CASE
	{
		int value = next->data;
		delete next;
		next = nullptr;
		return value;
	}
}
int Node::removeAt(unsigned int const position)
{
	if (position != 1 && next == nullptr) // Test Case
		throw ("That position does not exist!\n");
	else if (position != 1) // RECURSIVE STEP
		return next->removeAt(position-1);
	else // BASE CASE
	{
		Node* doomed = next;
		int value = doomed->data;
		next = doomed->next;
		delete doomed;
		return value;
	}
}
int Node::itemAtTail()
{
	if (next->next != nullptr) // If more than one element in the list.
		return next->itemAtTail();
	else // otherwise
		return next->data;
}
int Node::itemAt(unsigned int const position)
{
	if (position != 0 && next == nullptr) // BASE CASES
		throw ("The list is not long enough!\n");
	else if (position == 0) // Other Case
		return data;
	else // RECURSIVE STEP
		return next->itemAt(position-1);
}
bool Node::contains(int const value)
{
	if (data == value) // BASE CASE
		return true;
	else if (next == nullptr) // Other Case
		return false;
	else // RECURSIVE STEP
		return next->contains(value);
}
int Node::length() // Recursively count the length.
{
	if (next != nullptr)
		return 1 + next->length();
	else
		return 1;
} */

/**
 ** LINKEDLIST FUNCTIONS 
 **/
LinkedList::LinkedList() // Default Constructor, and only Constructor.
{ 
	this->head = nullptr; 
}
LinkedList::~LinkedList() // DESTRUCTOR
{
	Node* phead = head;
	while (phead != nullptr)
	{
		Node* pnext = phead->next; // If we did not have this, then our program would crash.
		delete phead;
		phead = pnext;
	}
}
void LinkedList::append(int data)
{
	if (head == nullptr) // If the list is empty.
		head = new Node(data); // Concstructor handles nullptr.
	else if (head->next == nullptr) // If there's one item in the list.
		head->next = new Node(data);
	else
	{
		Node* here = head->next;
		while (here->next != nullptr) // Iterate through the list until we're one from the end.
			here = here->next;

		here->next = new Node(data); // Constructor handles nullptr end.
	}
}
void LinkedList::prepend(int data)
{
	Node* tmp = new Node(data, head); // Constructor handles all cases.
	head = tmp;
}
void LinkedList::insertAt(int data, unsigned int position)
{
	if (position == 0 || head == nullptr) // Don't like how this is constructed, but it's in the notes.
		prepend(data);
	else
	{
		Node* here = head;
		while (position-- != 1)
		{
			if (here->next == nullptr) // If we reach the end of the list first.
			{
				here->next = new Node(data, here->next);
				return;
			}
			here = here->next;
		}
		Node* tmp = here->next;
		here->next = new Node(data, tmp);
	}
	
	// head->insertAt(data, position);
}
int LinkedList::decaudate()
{
	if (head == nullptr) // If empty().
		throw ("The list is empty!\n");
	else if (head->next == nullptr) // If only one item in the list.
		return decapitate();
	else // If there are several items in the list.
	{
		Node* here = head;
		while (here->next->next != nullptr) // Iterate through the LL until we're one before the end.
			here = here->next;

		int value = here->next->data;
		delete here->next;
		here->next = nullptr;
		return value;
	}
	// return head->decaudate();
}
int LinkedList::decapitate()
{
	if (head == nullptr) // If the list is empty().
		throw ("The list is empty!");
	else if (head->next == nullptr) // If there is only one item in the list.
	{
		int value = head->data;
		Node* killme = head;
		head = nullptr;
		delete killme;
		return value;
	}
	else // If there are several elements in the list.
	{
		int value = head->data;
		Node* killme = head;
		head = head->next;
		delete killme;
		return value;
	}
}
int LinkedList::removeAt(unsigned int position)
{
	if (head == nullptr) // If it's empty().
		throw ("The list is empty!\n");
	else if (position == 0) // If we want to get rid of the first element.
		return decapitate();
	else
	{
		Node* here = head;
		while (position-- != 1) // Keeping going through the list until we're one from the end.
		{
			if (here->next->next == nullptr) // If we reach the end of the list before we reach the desired position.
				throw ("The position does not exist!\n");
			here = here->next;
		}
		Node* doomed = here->next;
		int value = doomed->data;
		here->next = doomed->next;
		delete doomed;
		return value;
	}
	// return head->removeAt(position);
}
void LinkedList::clear()
{
	if (head == nullptr) // If empty().
		throw ("The list is empty!\n");
	else
	{
		Node* here = head->next; // Delete everything after the head.
		head = nullptr; // Still need to keep the head of the list.
		while (here != nullptr) // Iterate through as long as we have something to point at.
		{
			Node* pnext = here->next; 
			delete here;
			here = pnext;
		}
	}
}
int LinkedList::itemAtHead()
{
	if (head != nullptr) // If it's not empty().
		return head->data;
	else
		throw ("The list is empty!\n");
}
int LinkedList::itemAtTail()
{
	if (head == nullptr) // If the list is empty().
		throw ("The list is empty!\n");
	else if (head->next == nullptr) // If there's only one item in the list.
		return head->data;
	else// If there are several items in the list.
	{
		Node* here = head;
		while (here->next != nullptr) // Keep going until we're at the end of the list.
			here = here->next;

		return here->data;
	}
	// return head->itemAtTail();
}
int LinkedList::itemAt(unsigned int position)
{
	if (head == nullptr)
		throw ("The list is empty!\n");
	else if (position == 0 && head != nullptr) // If we're only getting the first element.
		return head->data;
	else
	{
		Node* here = head;
		while (position--)
		{
			if (here->next == nullptr)
				throw ("The list is not that long!\n");
			here = here->next;
		}
		return here->data;
	}
	// return head->itemAt(position-1);
}
bool LinkedList::contains(int const value)
{
	if (head == nullptr) // If the list is empty().
		return false;
	else if (head->data == value) // If the head happens to have the value we are looking for.
		return true;
	else
	{
		Node* here = head;
		while (here != nullptr)
		{
			if (here->data == value)
				return true;
			here = here->next;
		}
		return false;
	}
	// return head->contains(value);
}
unsigned int LinkedList::length()
{
	if (head == nullptr) // If empty()
		return 0;
	else if (head->next != nullptr) // If several items.
	{
		unsigned int length = 0;
		Node* here = head;
		while (here != nullptr)
		{
			++length;
			here = here->next;
		}
		return length;
	}
	else // If only one item.
		return 1;
}
void LinkedList::removeDuplicates()
{
	if (head == nullptr) // If the list is empty().
		throw ("The list is empty!\n");
	else if (head->next == nullptr) // If the list only contains one element.
		throw ("There is only one element in the list!\n");
	
	// otherwise
	Node* phead = head;
	while (phead != nullptr && phead->next != nullptr) // Handles some cases while iterating through list.
	{
		int toDelete = phead->data; // Know what value to delete.
		Node* pnext = phead;  // What we're going to use to iterate in our next loop. Help us find what to delete.
		while (pnext->next != nullptr) // We'll handle one past where we are in the next check.
		{ // This is so we do not go off the end of the list by accident. Same as decaudate.
			if (toDelete == pnext->next->data) // One past check, and do is this what we need to delete.
			{
				Node* doomed = pnext->next;		 // What we're going to delete.
				pnext->next = pnext->next->next; // Handles end cases for us.
				delete doomed;					 // Get rid of duplicate.
			}
			else
				pnext = pnext->next;
		}
		phead = phead->next; // Keep iterating through the list of possible values to delete.
	}
}
// Created this function to show us what's in the list. 
// Makes testing a lot easier.
void LinkedList::print()
{
	Node* here = head;
	while (here != nullptr)
	{
		std::cout << here->data << " ";
		here = here->next;
	}
	std::cout << std::endl;
}