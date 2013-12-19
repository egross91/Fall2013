#include "Node.h"

Node::Node() : data(), count(0), leftChild(nullptr), rightChild(nullptr) {  }
Node::Node(int dat) : data(dat), count(1), leftChild(nullptr), rightChild(nullptr) {  }
Node::Node(int dat, Node* lc, Node* rc) : data(dat), count(1), leftChild(lc), rightChild(rc) {  }
Node::Node(int dat, int co) : data(dat), count(co), leftChild(nullptr), rightChild(nullptr) {  }
Node::Node(int dat, int co, bool vis) : data(dat), count(co), leftChild(nullptr), rightChild(nullptr) {  }
Node::Node(int dat, int co, bool vis, Node* lc, Node* rc) : data(dat), count(co), leftChild(lc), rightChild(rc) {  }
Node::~Node() 
{
	
}
void Node::insert(int value)
{
	if (value > data && !isRC()) // rightChild
		this->rightChild = new Node(value);
	else if (value > data && isRC()) //rightChild
		this->rightChild->insert(value);
	else if (value < data && !isLC()) // leftChild
		this->leftChild = new Node(value);
	else if (value < data && isLC()) // leftChild
		this->leftChild->insert(value);
	else // value == data
		++count;
}
bool Node::contains(int value)
{
	if (value > data && isRC())
		return rightChild->contains(value);
	else if (value > data && !isRC())
		return false;
	else if (value < data && isLC())
		return leftChild->contains(value);
	else if (value < data && !isLC())
		return false;
	else // value == data
		return true;
}
void Node::clear()
{
	if (isLC())
		leftChild->clear();
	if (isRC())
		rightChild->clear();
	delete this;
}
bool Node::isRC()
{
	return (rightChild != nullptr);
}
bool Node::isLC()
{
	return (leftChild != nullptr);
}
void Node::inOrder()
{
	if (isLC())
		leftChild->inOrder();
	std::cout << data << " ";
	if (isRC())
		rightChild->inOrder();
}
void Node::preOrder()
{
	std::cout << data << " ";
	if (isLC())
		leftChild->preOrder();
	if (isRC())
		rightChild->preOrder();
}
void Node::postOrder()
{
	if (isLC())
		leftChild->postOrder();
	if (isRC())
		rightChild->postOrder();
	std::cout << data << " ";
}