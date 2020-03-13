| Joseph Kim|
| :---          	|
| s198022       	|
| A1US - AOS - Code Design and Data Structures  |
| Binary Tree Documentation |

## I. Requirements

1. Description of Problem

	- **Name**: BinaryTree

	- **Problem Statement**:
	Create a program that visually shows node in a tree chart and be able to insert, remove and selected specific nodes.

	- **Problem Specifications**:  Create a node that can insert, remove, and find selected nodes without any errors or bugs

2.  Output Information
    -The program displays a window various nodes with different values in a tree root like formation.
    - **Nodes**: A circle with a value, depending which if the first node is, goes left or right based on value's greater than or less than

|
3. ### Object Information

   **File**: Main.cpp

     Description: The main body where raylib loops and loads textures/draw nodes

    **Attributes**

         Name: InitWindow
             Description: Raylib's intialize window function
             Visiblity: public

        Name: SetTargetFPS
             Description: Run the game loop
             Visibility: public

        Name: WindowShouldClose
             Description: Detect window close button or ESC key
             Visiblity: public

        Name: BeginDrawing
             Description: Raylib's Drawing Function
             Visiblity: public

        Name: ClearBackGround
             Description: Raylib's Clear Background into designated color
             Visiblity: public

        Name: EndDrawing
             Description: Raylib's End Draw Function
             Visiblity: public

        Name: CloseWindow
             Description: Closes the window and OpenGL context
             Visiblity: public

     **Operations**:

        Name: screenWidth
             Description: The width of the window application
             Type: int
             Visibility: public

        Name: screenHeight
             Description: The height of the window application
             Type: int
             Visibility: public

        Name: _tree
             Description: Call function from BinaryTree class
             Type: class
             Visibility: public

        Name: _selected
             Description: The node being selected from BinaryTree Class
             Type: class
             Visibility: public

     **File**: BinaryTree.cpp

     Description: Handles the creation of and removal of nodes, and to draw them to the screen
    **Attributes**

         Name: isEmpty
             Description: Check if root is empty or not
             Type: bool

         Name: insert
             Description: Inesert the node from the Binary Tree
             Type: bool
             Arguments: int

         Name: remove
             Description: Removes the node from the Binary Tree
             Type: void
             Arguements: int

         Name: find
             Description: If the the root node exists first
             Type: class
             Arguements: int

         Name: draw
             Description: Draws the root node
             Type: void
             Arguements: class

         Name: findnode
             Description: Check if root is empty or not
             Type: void
             Arguements: int, class**, class**

         Name: draw
             Description: Check if root is empty or not
             Type: void
             Arguements: class*, int, int, int, class*

     **Operations**:

        Name: newNode
             Description: Creates a new node equal to value
             Type: class*

        Name: node
             Description: Create a new node with a pointer
             Type: class*

        Name: currentNode
             Description: Create a node equal the tree (used for checks)
             Type: class*

        Name: parentNode Create a node equal the tree (used for checks) parent of currentNode
             Description: 
             Type: class*

        Name: iterNode
             Description: Iterator Node going down the left branch
             Type: class

        Name: iterParent
             Description: Parent iterator node going down the left branch parent of iterNode
             Type: class


   **File**: TreeNode.cpp

     Description: Draws the node tree

    **Attributes**

         Name: TreeNode
             Description: Constructor for TreeNode
             Type: class constructor
             Arguments: int

         Name: draw
             Description: The Draw function to draw the tree with nodes onto the screen.
             Type: class constructor

     **Operations**:

        Name: Color
             Description: Creates color for the tree draw
             Type: class


   **File**: BinaryTree.h

     Description: The header class for BinaryTree holds function names

    **Attributes**

         Name: BinaryTree
             Description: Constructor of BinaryTree
             Visibility: public

         Name: ~BinaryTree
             Description: Deconstructor of BinaryTree
             Visibility: public

         Name: isEmpty
             Description:  Checks if root is empty
             Visibility: public
             Type: bool
             Arguements: const

         Name: insert
             Description: insert node function 
             Visibility: public
             Type: void
             Arguements: int

         Name: remove
             Description: remove node function 
             Visibility: public
             Type: void
             Arguements: int

         Name: find
             Description: find node function 
             Visibility: public
             Type: class*
             Arguements: int

         Name: draw
             Description: The ability to draw the node 
             Visibility: public
             Type: void
             Arguements: class*

         Name: findNode
             Description: the to ability to find a specific node
             Visibility: private
             Type: bool
             Arguements: int, class**, class**

         Name: draw
             Description: The ability to draw the node and tree
             Visibility: private
             Type: void
             Arguements: class*, int, int, int, class*

     **Operations**:

        Name: m_pRoot
             Description: Root of the node tree
             Type: class

        Name: parentNode
             Description: parentNode ponter creater
             Type: class

    **File**: TreeNode.h

     Description: 

    **Attributes**

         Name: BinaryTree
             Description: Constructor of BinaryTree
             Visibility: public

         Name: ~BinaryTree
             Description: Deconstructor of BinaryTree
             Visibility: public

         Name: isEmpty
             Description:  Checks if root is empty
             Visibility: public
             Type: bool
             Arguements: const

         Name: insert
             Description: insert node function 
             Visibility: public
             Type: void
             Arguements: int

         Name: remove
             Description: remove node function 
             Visibility: public
             Type: void
             Arguements: int

         Name: find
             Description: find node function 
             Visibility: public
             Type: class*
             Arguements: int

         Name: draw
             Description: The ability to draw the node 
             Visibility: public
             Type: void
             Arguements: class*

         Name: findNode
             Description: the to ability to find a specific node
             Visibility: private
             Type: bool
             Arguements: int, class**, class**

         Name: draw
             Description: The ability to draw the node and tree
             Visibility: private
             Type: void
             Arguements: class*, int, int, int, class*

     **Operations**:

        Name: m_pRoot
             Description: Root of the node tree
             Type: class

        Name: parentNode
             Description: parentNode pointer creater
             Type: class

