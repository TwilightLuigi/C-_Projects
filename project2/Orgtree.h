// Sierra Sprungl
// CS 3100-01
// Dr. Raymer
// this file will declare the functions, classes, and variables to be used in the program. 
// this project was done using a binary search tree with a linked list
// FILE:Orgtree.h
// CLASS PROVIDED: Orgtree

#define TREENODEPTR TreeNode*
#define TREENULLPTR NULL

#include <exception>
#include <string>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Struct TrreNode: creates a TreeNode object that will be used as the main tree and will be used when making new nodes
// Inputs: none
// Return: nothing, this is a struct function
// Side Effects: none
// Asympotic Run Time: Theta 1
// Space Requirements: O(1)
struct TreeNode 
{
	string title;
	string name;
	struct TreeNode *left;
	struct TreeNode *right;
};

// The purpose of this class is create a binary search tree that will the manage the emplolles in a company. This mangement will 
// be done by implelmenting functions that allow for the getting of the root, leftchild, and rightsibling of the tree, the allowing of 
// hiring and firing an empolyee, the reading and writng if thr tree to a file, and it allows for sreaching and the telling of the
// size of the tree. The public functions for this class are delaired below and along with the private varavbles
class OrgTree 
{
public:
	OrgTree();
	TreeNode* createNode(string title, string name);
	void addRoot(string title, string name);
	unsigned int getSize();
	unsigned int returngetSize(TREENODEPTR ptr);
	TREENODEPTR getRoot();
	TREENODEPTR leftmostChild(TREENODEPTR node);
	TREENODEPTR rightSibling(TREENODEPTR node);
	void printSubTreeInOrder();
	void printSubTree(TREENODEPTR subTreeRoot);
	TREENODEPTR find(string title);
	TREENODEPTR returnFindNode(string title, TREENODEPTR ptr);
	bool read(string filename);
	void write(string filename);
	void hire(TREENODEPTR, string newTitle, string newName);
	bool fire(string formerTitle);
	void fire(string formerTitle, TREENODEPTR ptr);
	
private:
	struct TreeNode* root;
	
};
