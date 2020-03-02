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


void BinaryTree::insert(int a_nValue)
{
	// Set the current node to root
	TreeNode* currentNode = m_pRoot;
	TreeNode* previousNode;

	// If the tree is empty, the value inserted at the root
	if (isEmpty)
	{
		currentNode->getData() = a_nValue;
	}

	// While the current node is not null
	while (currentNode != nullptr)
	{
		// If the value to be inserted is less than the value in the current node
			if (a_nValue < currentNode)
			{
				// Set the current node to the left child and continue
				currentNode->setLeft(currentNode);

			}
			// If the value to be inserted is greater than the current node
			else if (a_nValue > currentNode)
			{
				// Set the current node to the right child and continue

			}
			// If the value to be inserted is the same as the value in the current node
			else if (a_nValue == currentNode)
			{
				// The value is already in the tree, so exit
			}
	}																																						// end While


	// Get the parent of the current node (before it was set to null)
	// If the value to be inserted is less than parent
		// Insert value as left child node
	// Otherwise 
		// Insert value as right child node
}

void BinaryTree::remove(int a_nValue)
{
	// find the value in the tree, obtaining a pointer to the node and its parent
	// If the current node has a right branch, then
	//	find the minimum value in the right branch by iterating down the left branch of the
	//		current node’s right child until there are no more left branch nodes
	//	copy the value from this minimum node to the current node
	//	find the minimum node’s parent node(the parent of the node you are deleting)
	//		if you are deleting the parent’s left node
	//			set this left child of the parent to the right child of the minimum node
	//		if you are deleting the parent’s right node
	//			set the right child of the parent to the minimum node’s right child

	//		If the current node has no right branch
	//			if we are deleting the parent’s left child, set the left child of the parent to the left child of the current node
	//			If we are deleting the parent’s right child, set the right child of the parent to the left child of the current node
	//			If we are deleting the root, the root becomes the left child of the current node
}

TreeNode * BinaryTree::find(int a_nValue)
{
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
