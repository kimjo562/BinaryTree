/*******************************************************************************************
*
*   raylib [core] example - basic window
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2013-2016 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "TreeNode.h"
#include "BinaryTree.h"

int main()
{
	// Initialization
	//--------------------------------------------------------------------------------------
	int screenWidth = 1600;
	int screenHeight = 900;

	InitWindow(screenWidth, screenHeight, "Zatamari");

	SetTargetFPS(60);

	//--------------------------------------------------------------------------------------
	BinaryTree tree;
	TreeNode* selected;

	tree.insert(15);
	tree.insert(5);
	tree.insert(10);
	tree.insert(17);
	tree.insert(21);
	tree.insert(7);
	tree.insert(12);
	tree.insert(14);
	//selected = tree.find(17);

	tree.remove(7);

	// Main game loop
	while (!WindowShouldClose())    // Detect window close button or ESC key
	{
		// Update
		//----------------------------------------------------------------------------------
		// TODO: Update your variables here
		//----------------------------------------------------------------------------------

		// Draw
		//----------------------------------------------------------------------------------
		BeginDrawing();

		ClearBackground(BLACK);

		//DrawText("Skadi, Wheres Kaldr?", 440, 480, 35, WHITE);
		//DrawText("          (-.-)", 440, 580, 35, WHITE);

		tree.draw();

		EndDrawing();
		//----------------------------------------------------------------------------------
	}

	// De-Initialization
	//--------------------------------------------------------------------------------------   
	CloseWindow();        // Close window and OpenGL context
	//--------------------------------------------------------------------------------------

	return 0;
}