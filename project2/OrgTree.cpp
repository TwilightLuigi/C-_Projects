// Sierra Sprungl
// CS 3100-01
// Dr. Raymer
// The purpose of this class is create a binary search tree that will the manage the emplolles in a company. This mangement will 
// be done by implelmenting functions that allow for the getting of the root, leftchild, and rightsibling of the tree, the allowing of 
// hiring and firing an empolyee, the reading and writng if thr tree to a file, and it allows for sreaching and the telling of the
// size of the tree. 

#include "Orgtree.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

// Constructor OrgTree(): creates a orgtree object and initalizes the root of the tree to null.
// Inputs: No input is required for this constructor
// Returns: does not return anything
// Side Effects: none
// Asympotic Run Time: Theta 1
// Space Requirements: O(1)
OrgTree::OrgTree() 
{
	root = TREENULLPTR;
}

// Function createNode(string title, string name): creates a node object of type TreeNode*, this will be used for creating nodes with our
// other member functions.
// Inputs: string title, one of the data values that will be stored in the Node object, it is the name of the postion that a person has
// string name, the other data values that will be stored in the Node object, it is a name of a person in the company
// Returns: TreeNode*, this is the node created by the function. 
// Side Effects: none
// Asympotic Run Time: Theta 1
// Space Requirements: O(1)
TreeNode* OrgTree::createNode(string title, string name) 
{
	// creates a node object by setting its left and right sides/pointers to null, and setting its title and name pointers to the 
	// title or name that the user passes in. After this happens the node is returned.
	TreeNode *temp = new TreeNode();
	temp->left = temp->right = TREENULLPTR;
	temp->title = title;
	temp->name = name;
	return temp;
}

//Function addRoot(string title, string name): This function creates a root node for the tree. If there is already a root in the tree
// the entire tree then becomes a subtree of the new root. 
// Inputs: string title, the first peice of data that will be added to the root node for the node to hold. String name, the secound peice of 
// data that wull be added to the root node for the node to hold. 
// Returns: void, there is nothing to return
// Side Effects: if there is a root already in the tree, the entire tree must be moved to become a subtree of the new root node.
// Asympotic Run Time: Theta (n)
// Space Requirements: O(1)
void OrgTree::addRoot(string title, string name) 
{
	// calls the hire function to check and see if the tree is empty, if so it adds a root to the tree. It also checks to see
	// if the tree already as a root, if so, this function takes approate action to add the node as the new root. 
	hire(root, title, name);
}

// Function returngetSize(TREENODEPTR temp): a recursve function that traverses the tree counting each node as it goes to return the 
// number of empoloyees in the tree, if the tree is empty, then it returns a pointer to null which tells the user that the tree contains
// zero employees
// Inputs: TREENODEPTR temp, this is a temporaty node that will travervrse the tree, counting each node as it goes to determine how many
// employees are in the tree. 
// Returns: an unsigned int, that stands for the number of employees in the tree. 
// Side Effects: if the tree is empty a null pointer is returned 
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
unsigned int OrgTree::returngetSize(TREENODEPTR temp) 
{
	if (temp == TREENULLPTR) 
	{
		return TREENULLPTR;
	}
	else 
	{
		// The function rescruvely calls itself, this allows for the function to count and add the number of nodes as it traverses the tree on 
		// the left and right to find all of the employees in the tree. The plus 1 is there is account for the root node. 
		return (returngetSize(temp->left) + 1 + returngetSize(temp->right));
	}
}

// Function getSize(): returns the number of employees in the tree 
// Inputs: none
// Returns: unsigned int, the number of employees in the tree
// Side Effects: none
// Asympotic Run Time : O(n)
// Space Requirements: O(n)
unsigned int OrgTree::getSize() 
{
	// passes the root node into the returngetsize function so the function can traverse the tree from the root of tree to the bottom of the
	// tree to get the number of employees in the tree. 
	return returngetSize(root);
}

// Function getRoot(): returns the root node of the tree, 
// Inputs: none
// Returns: TREENODEPTR, a pointer to the root node of the tree
// Side Effects: if the is tree empty, no root pointer can be returned so we return null.
// Asympotic Run Time:Theta 1
// Space Requirements: O(1)
TREENODEPTR OrgTree::getRoot() 
{
	return root;
}

// Function leftmostChild(TREENODEPTR node): returns a pointer to the leftmost child of the node passed to the function. 
// if the node has no childern it returns a TREENULLPTR. 
// Inputs: TREENODEPTR node, the node we want to see the leftmost child of
// Returns: TREENODEPTR, the pointer to the leftmost child of the node passed in 
// Side Effects: if the leftmost child is passed in, then we must return a TREENULLPTR.
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
TREENODEPTR OrgTree::leftmostChild(TREENODEPTR node) 
{
	if (node->left == TREENULLPTR) 
	{
		return TREENULLPTR;
	}
	// Will traverse the tree until the leftmost child is found, once found the node pointer for the leftmost child is returned. If the node
	// pointer is not equal to the leftmost child, then we break out of the loop and try again.  
	for (; node; node = node->left) 
	{
		if (!node->left) 
		{
			break;
		}
		return node;
	}
	
}

// Function rightSibling(TREENODEPTR node): returns a pointer to the right sibling of the node passed to the function. If the node
// has no right sibling it returns TREENULLPTR 
// Inputs: TREENODEPTR node, the node that you want to find the rightsibling of 
// Returns: TREENODE PTR, the pointer to the right sibling of the node passed in. 
// Side Effects: If the tree is empty, then TREENULLPTR will be returned. 
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
TREENODEPTR OrgTree::rightSibling(TREENODEPTR node) 
{
	if (node != TREENULLPTR) 
	{
		// if the pointer to the left is not null, then the left pointers right child is set equal to the right pointer, and this is the 
		// node that is returned. 
		if (node->left != TREENULLPTR) 
		{
				node->left->right = node->right;
				return node;
		}
	}

	// if the pointer to the right is not null and the pointer to the right pointers left child is not null, the set the right pointer to its 
	// left child and set this equal to the left pointers right sibling, this is the node that is returned. 
	if (node->right != TREENULLPTR) 
	{
		if (node->right->left != TREENULLPTR) 
		{
				node->right->left = node->left->right;
				return node;
		}
	}
	if(node->right== TREENULLPTR) 
	{
		return TREENULLPTR;
	}

	// if none of the above are statisfied then we must traverse through the tree again and return the node.  
	else 
	{
		rightSibling(node->right);
		rightSibling(node->left);
		return node;
	}

}

// Function printSubTree(TREENODEPTR subTreeRoot): this function prints out the the subtree starting at the node pointed to by subTreeRoot
// This function prints out the tree with indentaion to show all the different levels of employees. 
// Inputs: TREENODEPTR subTreeRoot, the node at which to start printing the tree from.
// Return: void, no return value
// Side Effects: if the tree is empty, then we dont print anyting and an error message is displayed to the screen
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
void OrgTree::printSubTree(TREENODEPTR subTreeRoot) 
{
	if (root != TREENULLPTR) 
	{
		// if the node that was passed's left child is not equal to null, then we traverse the tree until we find a node with no left child
		// at that point, we print out the nodes on the left side of the tree. 
		if (subTreeRoot->left != TREENULLPTR) 
		{
			printSubTree(subTreeRoot->left);
			cout << endl << "    ";
		}

		cout << subTreeRoot->title << subTreeRoot->name << endl;

		// if the node that was passes's right sibling is not equal to null, then we traverse the tree until we find a node with no right
		// sibling, at that point, we print out nodes on the right side of the tree.
		if (subTreeRoot->right != TREENULLPTR) 
		{
			printSubTree(subTreeRoot->right);
			cout << endl << "   ";
		}
		cout << subTreeRoot->title << subTreeRoot->name << endl;
	}
	
	// if the tree is empty we don't print any nodes and we tell the user the tree is empty.
	else 
	{
		cout << "The Tree is empty, can't print out an empty tree";
	}

}

//Function printSubTreeInOrder(): sets the subtreeroot pointer of the printSubTree function to root. 
// Inputs: none
// Return: void, nothing to return
// Side Effects: if root is null then nothing happens
// Asympotic Run Time: Theta 1
// Space Requirements: O(1)
void OrgTree::printSubTreeInOrder() 
{
	printSubTree(root);
}

// Function find(string title): returns a TREENODEPTR to the node listing the given title. If the title is not found, the function 
// should return TREENULLPTR. 
// Inputs: string title, the title the user is trying to find in the tree.
// Return: TREENODEPTR, the pointer to the title the user is trying to find,
// Side Effects: if the title is not in the tree then TREENULLPTR is returned 
// Asympotic Run Time: Theta 1
// Space Requirements: O(1)
TREENODEPTR OrgTree::find(string title) 
{
	// sets the node pointer for the return find function to root and passes the title to find.  
	return returnFindNode(title,root);
}

// Function returnFindNode(string title, TREENODEPTR ptr): This function returns a TREENODEPTR to the node listing the given title.
// if the title is not found, the function should return TREENULLPTR
// Inputs: string title, the title we want to find in the tree TREENODEPTR, the pointer will use to traverse the tree
// Return: TREENODEPTR, the pointer to the title the user is trying to find 
// Side Effects: if the title is not in the tree then TREENULL is returned
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
TREENODEPTR OrgTree::returnFindNode(string title, TREENODEPTR ptr) 
{
	if (ptr != TREENULLPTR) 
	{
		// if the pointer is currently on the title to be found, we return the pointer
		if (ptr->title == title) 
		{
			return ptr;
		}
		else 
		{
			// If the title we are looking for is less than or on the left side of the tree we then contuine to travsre the tree until 
			// the title we are looking for is found. 
			if (title < ptr->title) 
			{
				return returnFindNode(title, ptr->left);
			}
			// If the title we are looking for is more than or on the right side of the tree we then contuine to travsre the tree until 
			// the title we are looking for is found. 
			else
			{
				return returnFindNode(title, ptr->right);
			}
		}
	}
	// if the title we are looking for is not in the tree, we return a TREENULLPTR.
	else 
	{
		return TREENULLPTR;
	}
}

// Function read(string filename): reads the tree from a file. If the file is found and read successfully, this function will return
// true. If the file is not found or the file is improperly formatted the function will return false. 
// Input: string filename, the name of file to read the tree from. 
// Return: bool, true if file is found and read successfully. False if the file is improperly formatted
// Side Effects: if the file is not formated properly then the file is read
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
bool OrgTree::read(string filename) 
{
	ifstream inFile;
	string title;
	string name;
	inFile.open(filename);

	// if the file is not opened, meaning that it wasn't open properly or not found we return false. 
	if (!inFile.is_open()) 
	{
		return false;
	}

	// while the file is not closed and its not the end of the file read the contents from the file, when the end is reached close the file
	// and return true
	while (!inFile.eof()) 
	{
		inFile >> title, name, ")";
	}
	inFile.close();
	return true;
}

// Function write(string filename): writes the tree out to a file, using the same fromat as the read function
// Inputs: string filename, the file we want to write to. 
// Return: void, no return value
// Side Effects: none
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
void OrgTree::write(string filename) 
{
	ofstream outFile;
	outFile.open(filename);
	
	// calls the getRoot, leftmostChild, and rightSibling functions to traverse the tree and collect all the nodes, so they can be 
	// written into the file after this is done, we close the file.  
	outFile << getRoot(), leftmostChild(root), rightSibling(root);
	outFile << ")";
	outFile.close();
}

// Function hire(TREENODEPTR ptr, string newTitle, string newName): this function is used to add employees to the tree. The employee
// is added as the last child of the node pointed to by TREENODEPTR
// Inputs: TREENODEPTR, the temporay node that will traverse the tree to find the approate spot to add the employee into the tree,
// string newtitle, the title of the employee to be hired in, string newName, the name of the employee to be hired
// Return: void, no value  to return
// Side Effects: none
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
void OrgTree::hire(TREENODEPTR ptr, string newTitle, string newName) 
{
	// If root is equal to null then the employee is added to the root and a new tree is created
	if (root == TREENULLPTR) 
	{
		root = createNode(newTitle, newName);
		return;
	}
	
	// if the left most child of the pointer passed in is equal to null then we add the employee into this spot
	if (ptr->left == TREENULLPTR) 
	{
		TREENODEPTR newNode = createNode(newTitle, newName);
		ptr->left = newNode;
	}

	// if the right sibling of the pointer passed in is not eqaul to null then we traverse the tree until it is null  and then we
	// add the employee into that spot. 
	TREENODEPTR temp = ptr->left;
	TREENODEPTR newNode2 = createNode(newTitle, newName);

	while (ptr->right != TREENULLPTR) 
	{
		temp = temp->right;
	}

	temp->right = newNode2;

}

// Function fire(string formerTitle, TREENODEPTE ptr): if the employee to fire is found, the node in the tree that contants this employee
// is deleted. 
// Input: string formerTitle, the title of the employee to fire, TREENODEPTR ptr, the temp node to traverse to tree to find the employee
// to delete
// Return: void, no value to return.
// Side Effects: none
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
void  OrgTree::fire(string formerTitle, TREENODEPTR ptr) 
{
	// if the pointer to the left of the pointer passed is not null and  if it equals the title of the employee to fire, then the node
	// is deleted
	if (ptr->left != TREENULLPTR && ptr->left->title == formerTitle) 
	{
		delete ptr->left;
	}

	// if the pointer to the right of the pointer passed is not null and if it equals the title of the employee to fire, then the node
	// is deleted.
	if(ptr->right != TREENULLPTR && ptr->right->title == formerTitle)
	{
		delete ptr->right;
	}
	
}

// Function fire(string formerTitle): fires an employee who's title matches the title passed into this function. If the title is found
// in the tree the employee's node in the tree is deleted and the function returns true. If not match is found then it returns false,
// it also returns false if the node of the tree is attempted to be deteled
// Inputs: string formerTitle, the title of the employee to fire
// Return: bool, true is node is deleted, false is the title is not found or if root is attempted to be deleted
// Side Effects: none
// Asympotic Run Time: O(n)
// Space Requirements: O(n)
bool OrgTree::fire(string formerTitle) 
{
	if (root->title == formerTitle) 
	{
		return false;
	}
	if (root->left->title != formerTitle || root->right->title != formerTitle) 
	{
		return false;
	}
	else 
	{
		fire(formerTitle, root);
		return true;
	}
	

}


