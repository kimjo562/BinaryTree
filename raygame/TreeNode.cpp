#include "TreeNode.h"
#include <stdio.h>

TreeNode::TreeNode(int value)
{
	m_value = value;
}

TreeNode::~TreeNode()
{
}

void TreeNode::draw(int x, int y, bool selected)
{
	static char buffer[10];
	Color color;

	DrawCircle(x, y, 30, BLUE);
	sprintf_s(buffer, "%d", m_value);

	if (selected)
	{
		DrawCircle(x, y, 28, ORANGE);
	}
	else
	{
		DrawCircle(x, y, 28, BLACK);
	}

	DrawText(buffer, (x - 12), (y - 10), 20, WHITE);
}
