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
		// return true if root is null
		return true;
	}
	return false;
}

// Set the current node to root
void BinaryTree::insert(int a_nValue)
{

	// If the tree is empty, the value inserted at the root
	if (isEmpty())
	{
		TreeNode * newNode = new TreeNode(a_nValue);
		m_pRoot = newNode;
		return;
	}

	//Create a pointer.
	TreeNode* node;
	node = m_pRoot;

	bool insert = true;

	// While the current node is not null
	while (insert)
	{
		// If the value to be inserted is less than the value in the current node
		if (a_nValue < node->getData())
		{
			if (node->getLeft() != nullptr)
			{
				node = node->getLeft();
			}
			else
			{
				// Set the current node to the left child and continue
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setLeft(newNode);
				insert = false;
			}
		}
		// If the value to be inserted is greater than the current node
		else if (a_nValue > node->getData())
		{
			if (node->getRight() != nullptr)
			{
				node = node->getRight();
			}
			else
			{
				// Set the current node to the right child and continue
				TreeNode* newNode = new TreeNode(a_nValue);
				node->setRight(newNode);
				insert = false;
			}

		}
		// If the value to be inserted is the same as the value in the current node
		else if (node->getData() == a_nValue)
		{
			// do nothing
			insert = false;
		}

	}
	
}

void BinaryTree::remove(int a_nValue)
{
	TreeNode* currentNode = find(a_nValue);

	// If the current node has a right branch, then
	if (currentNode->hasLeft() && currentNode->hasRight())
	{
		//Swap with equal value to the right
		TreeNode* tempNode = currentNode->getRight();

		bool searching = true;
		while (searching)
		{
			// Find the minimum value in the right branch by iterating down the left branch of the 
			// current node’s right child until there are no more left branch nodes 
			if (tempNode->getLeft() != nullptr)
			{
				parentNode = tempNode;
				tempNode = tempNode->getLeft();
			}
			// If you are deleting the parent’s left node 
			else if (tempNode->getLeft() == nullptr)
			{
				currentNode->setData(tempNode->getData());
				tempNode = nullptr;
				parentNode = nullptr;
				delete tempNode;
				delete parentNode;
			}

		}
	}
	else if (currentNode->hasLeft() || currentNode->hasRight()) 
	{
		// 5, 

		if (currentNode->hasLeft())   
		{		
			parentNode->setLeft(currentNode->getLeft());
		}
		if (currentNode->hasRight()) 	
		{
			 parentNode->setLeft(currentNode->getRight());
		}

		// ----------------------------------------------------
		// 12,17,
		
		//if (node->hasLeft())
		//{
		//	parentNode->setLeft(node->getRight());
		//}
		//if (node->hasRight()) 	
		//{
		//	parentNode->setRight(node->getRight());
		//}

		delete currentNode;
		currentNode = nullptr;
		delete currentNode;
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
	while (node != nullptr) {

		if (node->getData() == a_nValue)
		{
			found = true;
			return node;
		}
		// If its greater go right
		else if (a_nValue > node->getData())
		{
			parentNode = node;
			node = node->getRight();
		}
		// Otherwise go left
		else if (a_nValue < node->getData())
		{
			parentNode = node;
			node = node->getLeft();
		}

	}
	return nullptr;
}

void BinaryTree::draw(TreeNode * selected)
{
	// Draw the root node
	draw(m_pRoot, 640, 200, 640, selected);
}

bool BinaryTree::findNode(int a_nSearchValue, TreeNode ** ppOutNode, TreeNode ** ppOutParent)
{
	// Set the current node to the root
	TreeNode * currentNode = new TreeNode(0);
	m_pRoot = currentNode; // This now Parent Node

	//	While the current node is not null
	while (currentNode != nullptr)
	{
		//	if the search value equals the current node value,
		if (a_nSearchValue == currentNode->getData())
		{
			//	return the current node and its parent
			return currentNode;
		}
		//	Otherwise, If the search value is less than the current node
		else if (a_nSearchValue < currentNode->getData())
		{
			//	set the current node to the left child
			currentNode = currentNode->getLeft();
		}
		else
		{
			//	otherwise set the current node to the right child
			currentNode = currentNode->getRight();
		}

	}	// end While

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
			DrawLine(x, y, x - horizontalSpacing, y + 80, RED);
			// Draw the left node
			draw(pNode->getLeft(), x - horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		// Check for a right node
		if (pNode->hasRight())
		{
			// Draw a line to the right node
			DrawLine(x, y, x + horizontalSpacing, y + 80, RED);
			// Draw the right node
			draw(pNode->getRight(), x + horizontalSpacing, y + 80, horizontalSpacing, selected);
		}
		pNode->draw(x, y, (selected == pNode));
	}
}
