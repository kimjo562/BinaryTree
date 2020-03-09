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
	// Create a pointer
	TreeNode* parentNode;
	TreeNode* currentNode;

	if (findNode(a_nValue, &currentNode, &parentNode) == true)
	{
		// If the current node has a right branch
		if (currentNode->hasRight())
		{
			TreeNode* iterNode = currentNode->getRight();
			TreeNode* iterParent = currentNode;

			// Check if Iter's Left isn't null
			while (iterNode->getLeft() != nullptr)
			{
				iterParent = iterNode;
				iterNode = iterNode->getLeft();
			}

			// Copy the iter's data to the current node;
			currentNode->setData(iterNode->getData());

			// If you are deleting the parent’s left node
			if (iterNode == iterParent->getLeft())
			{
				// Set this left child of the parent to the right child of the minimum node
				if (iterNode->hasRight())
				{
					iterParent->setRight(iterNode->getRight());
					delete iterNode;
				}
				else
				{
					delete iterNode;
					iterParent->setLeft(nullptr);
				}
			}
			else if (iterNode == iterParent->getRight())
			{
				// Set the right child of the parent to the minimum node’s right child
				if (iterNode->hasRight())
				{
					iterParent->setRight(iterNode->getRight());
					delete iterNode;
				}
				else
				{
					delete iterNode;
					iterParent->setRight(nullptr);
				}
			}
		}
	}
	// If the current node has no right branch  
	else
	{
		// If we are deleting the parent node's left
		if (currentNode == parentNode->getLeft())
		{
			// Set the left child of the parent to the left child of the current node
			if (currentNode->hasLeft())
			{
				parentNode->setLeft(currentNode->getLeft());
				delete currentNode;
			}
			else
			{
				delete currentNode;
				parentNode->setLeft(nullptr);
			}
		}
		// If we are deleting the parent node's right
		else if (currentNode == parentNode->getRight())
		{
			// Set the right child of the parent to the left child of the current node
			if (currentNode->hasLeft())
			{
				parentNode->setRight(currentNode->getLeft());
				delete currentNode;
			}
			else
			{
				delete currentNode;
				parentNode->setRight(nullptr);
			}
		}
		// If we are deleting the root
		else if (currentNode == m_pRoot)
		{
			// The root becomes the left child of the current node 
			m_pRoot = currentNode->getLeft();
			m_pRoot->setLeft(currentNode->getLeft()->getLeft());
			delete currentNode->getLeft();
		}
	}

	if (!currentNode->hasLeft() && !currentNode->hasRight())
	{
		if (parentNode->getRight() == currentNode)
		{
			parentNode->setRight(nullptr);
		}
		else if (parentNode->getLeft() == currentNode)
		{
			parentNode->setLeft(nullptr);
		}
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
	TreeNode* currentNode = m_pRoot;
	TreeNode* parentNode = currentNode;

	// While the current node is not null
	while (currentNode != nullptr)
	{
		// If the search value equals the current node
		if (a_nSearchValue == currentNode->getData())
		{
			// Set the current node to the parent node
			*ppOutNode = currentNode;
			*ppOutParent = parentNode;
			return true;
		}
		else if (a_nSearchValue < currentNode->getData())
		{
			// Set the parent node to current node
			parentNode = currentNode;
			// Set the current node to the left
			currentNode = currentNode->getLeft();
		}
		else if (a_nSearchValue > currentNode->getData())
		{
			// Set the parent node to current node
			parentNode = currentNode;
			// Set the current node to the right
			currentNode = currentNode->getRight();
		}
	}

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
