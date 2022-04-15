// Sierra Sprungl
// CS 3100-01
// Dr.Raymer
// This file will declare the functions, classes, and variables to be used in the program
// This project will will be done using an Alphabet Trie
// FILE: Trie.h
// CLASS PROVIDED: Trie

#include <string>
#include <vector>

using namespace std;
const int ALPHA_SIZE = 26;

// Function struct TrieNode: purpose is to create a trie node that will store the letters of the aplhabet and pointers to these letters
// when the node is created, will contain int prefixAmount, this is usesd to track the number of letters in a word, struct TrieNode *child[ALPHA_SIZE]
// this is the part of the node that will be the node that stroes pointers to all of the different letters in the trie. It can store up to 26,
// this becasue there are 26 letters in the alphabet. Also the new node that is cretaed will also contain bool wordEnd which will be used
// to detretmine when a word as endeded. 
// Inputs: none
// Returns: nothing
// Side Effects: none
// Asympotic Run Time: 
// Space Requirements: 
struct TrieNode
{
	int prefixAmount;
	struct TrieNode *child[ALPHA_SIZE];
	bool wordEnd;
	
};

// The purpose of this class is to create a trie object that will be used to write an autocomplete program using the English dictionary. 
// this will be done by implelmenting functions that allow for the inserting of a word into the trie, getting the number of words and
// nodes in the trie, seeing if a word is in the trie, and returning the number of and words that match a given prefix. 
// The public functions for this class are delcaired below along with the private varibles. 
class Trie
{

public:
		Trie();
		bool insert(string word);
		int count();
		int getSize();
		bool find(string word);
		int completeCount(string word);
		vector<string> complete(string word);

private: 
		TrieNode *root; 
		int wordCount = 0;
		int NodeCount = 0; 
		vector<string> words; 
		char arr[];
};
