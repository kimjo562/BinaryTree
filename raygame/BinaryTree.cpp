#include "BinaryTree.h"
#include "TreeNode.h"

BinaryTree::BinaryTree()
{
}


BinaryTree::~BinaryTree()
{
}

bool BinaryTree::isEmpty() const
{
	if (m_pRoot == nullptr)
	{
		return true;
	}
	// return true if root is null
	return false;
}

// Set the current node to root
void BinaryTree::insert(int a_nValue)
{

	// If the tree is empty, the value inserted at the root
	if (isEmpty())
	{
		TreeNode * newNode = new TreeNode(0);
		m_pRoot = newNode;
		m_pRoot->setData(a_nValue);
	}

	bool inserting = true;

	//Create a pointer.
	TreeNode* node;
	node = m_pRoot;

	// While the current node is not null
	while (inserting)
	{
		// If the value to be inserted is less than the value in the current node
		if (node->getData() > a_nValue)
		{
			// Set the current node to the left child and continue
			if (node->getLeft() != nullptr)
			{
				node = node->getLeft();
			}
			else
			{
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setLeft(newNode);
				inserting = false;
			}
		}

		// If the value to be inserted is greater than the current node
		else if (node->getData() <= a_nValue)
		{
			// Set the current node to the right child and continue
			if (node->getRight() != nullptr)
			{
				node = node->getRight();
			}
			// If the value to be inserted is the same as the value in the current node
			else
			{
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setRight(newNode);
				inserting = false;
			}
		}
	}
}

void BinaryTree::remove(int a_nValue)
{
	TreeNode * node = find(a_nValue);
	// If the current node has a right branch, then
	if (node->hasLeft() && node->hasRight())
	{
		//Swap with equal value to the right
		TreeNode * tempNode = node->getRight();

		bool searching = true;
		while (searching)
		{
			// Find the minimum value in the right branch by iterating down the left branch of the
			if (tempNode->getLeft() != nullptr)
			{
				tempNode = tempNode->getLeft();
			}
			// If you are deleting the parent’s left node 
			else if (tempNode->getLeft() == nullptr)
			{
				node->setData(tempNode->getData());
				tempNode = nullptr;
				delete tempNode;
			}
		}
	}
	else if (node->hasLeft() || node->hasRight())
	{
		if (node->hasLeft())    // Set this left child of the parent to the right child of the minimum node
		{

		}
		if (node->hasRight()) 	// Set the right child of the parent to the minimum node’s right child
		{

		}

		//delete node
		node = nullptr;
		delete node;
	}

	//Delete the node and ptr.
	else {
		node = nullptr;
		delete node;
	}
}

TreeNode * BinaryTree::find(int a_nValue)
{
	bool found = false;

	if (m_pRoot->getData() == a_nValue)
	{
		found = true;
		return m_pRoot;
	}

	//Create a pointer.
	TreeNode* node;
	node = m_pRoot;
	while (!found) {

		if (node->getData() == a_nValue)
		{
			found = true;
			return node;
		}
		// If its greater go right
		else if (node->getData() > a_nValue)
		{
			node = node->getRight();
		}
		// Otherwise go left
		else
		{
			node = node->getLeft();
		}

		// No infinite
		if (node->getLeft() == nullptr && node->getRight() == nullptr)
		{
			return nullptr;
		}
	}
	return nullptr;
}

void BinaryTree::draw(TreeNode * selected)
{
	// Draw the root node
	draw(m_pRoot, 640, 680, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	// Set the current node to the root
	//	While the current node is not null
	//	if the search value equals the current node value,
	//		return the current node and its parent
	//	otherwise
	//		If the search value is less than the current node
	//		set the current node to the left child
	//	otherwise set the current node to the right child
	// end While
	// If the loop exits, then a match was not found, so return false
	return false;
}

void BinaryTree::draw(TreeNode * pNode, int x, int y, int horizontalSpacing, TreeNode * selected)
{
	// Cuts the horizontal spacing in half
	horizontalSpacing /= 2;
	
	if (pNode)
	{
		// Check for a left node
		if (pNode->hasLeft())
		{
			// Draw a line to the left node
			DrawLine(x, y, x - horizontalSpacing, y - 80, RED);
			// Draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		// Check for a right node
		if (pNode->hasRight())
		{
			// Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y - 80, RED);
			// Draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y - 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}
