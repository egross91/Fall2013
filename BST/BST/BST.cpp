#include "BST.h"

BST::BST() : root(nullptr), num_nodes(0) {  }
BST::~BST()
{
	if (empty())
		return;
	else
	{
		if (root->isLC())
			root->leftChild->clear();
		if (root->isRC())
			root->rightChild->clear();
		delete root;
	}
}
void BST::insert(int value)
{
	if (empty()) 
		root = new Node(value);
	else // num_nodes >= 1
		root->insert(value);
	++num_nodes;
}
void BST::remove(int value)
{
	if (empty())
		throw ("The Tree is empty.\n");
	
	// Know where we're at, and where we're going.
	Node* cur = root;
	Node* prnt = nullptr;
	bool is_val = false;

	// First, find the value.
	while (cur != nullptr)
	{
		if (value == cur->data) // Value is in tree.
		{
			is_val = true;
			break;
		}
		else // Keep moving.
		{
			prnt = cur;
			if (value < cur->data) // Move left.
				cur = cur->leftChild;
			else // Move right.
				cur = cur->rightChild;
		}
	}
	if (!is_val) // Value is not in the Tree.
		throw ("The value is not in the Tree.\n");
	
	num_nodes -= cur->count; // We found the value and will be deleted.
	// Now, decide how to delete.
	if (root == cur) // Root Case.
	{
		prnt = cur;
		if (root->isLC()) // Inorder predecessor.
		{
			cur = root->leftChild;
			while (cur->isRC()) // Rightmost in left subtree.
			{
				prnt = cur;
				cur = cur->rightChild;
			}
			root->data = cur->data;
		}
		else if (root->isRC()) // Inorder successor.
		{
			cur = root->rightChild;
			while (cur->isLC()) // Leftmost in right subtree.
			{
				prnt = cur;
				cur = cur->leftChild;
			}
			root->data = cur->data;
		}
		else // Root is the only Node. **Special case.**
		{
			delete root;
			root = nullptr;
			return; // There's no more work to be done.
		}
	}
	// How are we going to delete where we're at?
	if (!cur->isLC() && !cur->isRC()) // The current Node is a leaf.
	{
		if (prnt->leftChild == cur) // We're in the parent's leftChild.
			prnt->leftChild = nullptr; 
		else // (prnt->rightChild == cur)  We're in the parent's rightChild.
			prnt->rightChild = nullptr; 
		delete cur; // Delete the node.
		return;  // We're done.
	}
	else if (cur->isLC() && !cur->isRC()) // If there's only a leftChild in the current Node.
	{
		if (prnt->leftChild == cur) // We're in the parent's leftChild.
			prnt->leftChild = cur->leftChild; // Re-link.
		else // (prnt->rightChild == cur) We're in the parent's rightChild.
			prnt->rightChild = cur->rightChild; // Re-link.
		delete cur; // Delete the Node.
		return; // We're done.
	}
	else if (!cur->isLC() && cur->isRC()) // If there's only a rightChild in the current Node.
	{
		if (prnt->leftChild == cur) // We're in the parent's leftChild.
			prnt->leftChild = cur->rightChild; // Re-link.
		else // (prnt->rightChild == cur) We're in the parent's rightChild.
			prnt->rightChild = cur->rightChild; // Re-link.
		delete cur; // Delete the Node.
		return; // We're done.
	}
	else // (cur->isLC() && cur->isRC()) There are two children in the current Node.
	{
		Node* mole = nullptr;
		if (cur->leftChild->isRC()) // Find rightmost Node in left subtree. Inorder predecessor.
		{
			mole = cur->leftChild;
			while (mole->isRC()) 
			{
				prnt = mole;
				mole = mole->rightChild;
			}
			cur->data = mole->data; // Copy over the data.
			prnt->rightChild = nullptr; // Hand our deletion.
			delete mole; // Delete the Node that replaced the original deleted Node.
		}
		else if (cur->rightChild->isLC()) // Find leftmost Node in right subtree. Inorder successor.
		{
			mole = cur->rightChild;
			while (mole->isLC())
			{
				prnt = mole;
				mole = mole->leftChild;
			}
			cur->data = mole->data; // Copy over the data.
			prnt->leftChild = nullptr; // Handle our deletion.
			delete mole; // Delete the Node that replaced the deleted Node.
		}
		else // Neither side has a successor or predecessor.
		{
			mole = cur->leftChild; // We're going to use just the leftChild of the Node being deleted.
			cur->data = mole->data; // Copy over the data.
			cur->leftChild = mole->leftChild; // Keep the link.
			delete mole; // Remove the pseudo-predecessor.
		}
		return; // We're done.
	}
}
bool BST::contains(int value)
{
	if (empty())
		throw ("The Tree is empty.\n");
	else if (num_nodes == 1 && value != root->data)
		return false;
	else if (num_nodes == 1 && value == root->data)
		return true;
	return root->contains(value);
}
size_t BST::size()
{
	return num_nodes;
}
void BST::printContents()
{
	if (empty())
		throw ("The Tree is empty.\n");
	std::cout << "In Order:  ";
	inOrder();
	std::cout << "\nPre Order: ";
	preOrder();
	std::cout << "\nPost Order: ";
	postOrder();
	std::cout << std::endl;
}
size_t BST::height()
{
	if (empty())
		throw ("The Tree is empty.\n");
	return findHeight(root);
}
size_t BST::findHeight(Node* here)
{
	if (here == nullptr)
		return 0;

	size_t left = findHeight(here->leftChild);
	size_t right = findHeight(here->rightChild);

	if (left > right)
		return left + 1;
	else 
		return right + 1;
}
bool BST::empty()
{
	return (num_nodes == 0);
}
void BST::inOrder()
{
	if (root->isLC()) // leftChild
		root->leftChild->inOrder();
	std::cout << root->data << " "; // This Node
	if (root->isRC()) // rightChild
		root->rightChild->inOrder();
}
void BST::preOrder()
{
	std::cout << root->data << " "; // This Node
	if (root->isLC()) // leftChild
		root->leftChild->preOrder();
	if (root->isRC()) // rightChild
		root->rightChild->preOrder();
}
void BST::postOrder()
{
	if (root->isLC()) // leftChild
		root->leftChild->postOrder();
	if (root->isRC()) // rightChild
		root->rightChild->postOrder();
	std::cout << root->data << " "; // This Node
}