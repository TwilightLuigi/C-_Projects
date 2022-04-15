// Sierra Sprungl
// CS 3100-01
// Dr. Raymer 
// The purpose of this class is to create a trie object that will be used to write an autocomplete program using the English dictionary. 
// this will be done by implelmenting functions that allow for the inserting of a word into the trie, getting the number of words and
// nodes in the trie, seeing if a word is in the trie, and returning the number of and words that match a given prefix. 

#include "Trie.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

// Constructor Trie(): creates a trie object, with a root node that points to a boolan value that is set to false, meaning that when a letter
// is entered into the trie that it is not the end of a word until the boolan value is changed to true in another function. This root node
// also points to the prefixAmount variable and sets it equal to 0.  
Trie::Trie()
{
	root = new TrieNode();
	root->wordEnd = false;
	root->prefixAmount = 0;

}

// Function insert(string word): Inserts a new word into the trie. This function returns true if the word is successfuly inserted into 
// the trie and false if the word could not be inserted. The only way that a word will not be insersed is if the word to be inserted
// is already in the trie. For the duplicate words are not allowed. 
// Inputs: string word, this is the word to be inserted into the trie. 
// Returns: bool, returns true if the word is successfully inserted into the trie. Returns false, if the word could not be added into the
// trie, due the word already being in the trie. 
// Side Effects: if a word is already in the trie and duplicate word is trying to be inserted, it won't be. 
// Asympotic Run Time: 
// Space Requirements: 
bool Trie::insert(string word)
{
	TrieNode *temp = root;
	temp->prefixAmount++;

	// Loop is used to determine when the end of a word has been reached, if the end of word as not been reached the loop countines
	// during the excacution of the loop the child node is checked to see if the first letter of the word to be insested as a node
	// corasponsed with that letter in the child node. If not a new node is created to hold this letter and then the same is done for
	//  the other letters in the word. If the letter already has a node then the letter is not added and the next letter is looked at.
	// When the end of the word is reached, then we break out of the loop and set the wordEnd boolen to true and return true. 
	for (int i = 0; i < word.length(); ++i)
	{
		int currentLetter = (int)word[i] - (int)'a';
		if (temp->child[currentLetter] == NULL)
		{
			temp->child[currentLetter] = new TrieNode();
			NodeCount++;
		}
		temp->child[currentLetter]->prefixAmount++;
		temp = temp->child[currentLetter];
	}
	temp->wordEnd = true;
	wordCount++;
	return true; 
}

// Function count(): returns the number of words in the trie.  
// Inputs: none
// Returns: int wordCount. This is the number of words in the trie
// Side Effects: none
// Asympotic Run Time: 
// Space Requirements: 
int Trie::count() 
{
	return wordCount;
}

// Function getsize(): returns the number of nodes in the trie.
// Inputs: none
// Returns: int NodeCount, this is the number of nodes in the trie
// Side Effects: if no words or nodes are added to the trie, then this function will return 1, this is due to there always being a 
// child/root node in the trie. This is becuase we need a place to store the pointers for any in comming letters that get added to the
// trie
// Asympotic Run Time: 
// Space Requirements: 
int Trie::getSize()
{
	return NodeCount +1;
}

// Function find(string word): Searches the trie for a word given by the user. If the given word is found in the trie, then the function
// should return true and if the word is not in the trie or not found, then the function is to return false.
// Inputs: string word, this is the word given to the function by the user that user wants to know if it is in the trie or not. 
// Side Effects: if the trie is empty then no words can be found
// Asympotic Run Time: 
// Space Requirements: 
bool Trie::find(string word) 
{
	TrieNode *temp = root; 
	for (int i = 0; i < word.length(); ++i)
	{
		int currentLetter = (int)word[i] - (int)'a';

		// if while searching for the given word in the trie if we come across a letter in the word that is not in the trie then we stop reading
		// the user given word and we stop traversing the trie. And we return false, for it one of the letter in the given word is not in
		// the trie then that word is not in the trie. Howvever, if all of the letters were in the trie then the word is in in trie and
		// we return true. 
		if (temp->child[currentLetter] == NULL)
		{
			return false;
		}
		temp = temp->child[currentLetter];

	}
	return true;
}

// Function completeCount(string word): This function will return the number of words in the trie that begin with the given input string.
// If no matching words are found, the function returns zero.
// Inputs: string word, this is the word or prefix that function is to use to figure out how many words begin with that given prefix or word
// Returns: int temp->prefixAmount if there are words in the trie that start with the given prefix or word, int temp->prefixAmount returns
// the number of words in the trie that match the give prefix or word. returns 0 if there are no words in the trie that match the given 
// prefix or word. 
// Side Effects: if there are no words in the trie then no words can be found that match the input string. 
// Asympotic Run Time: 
// Space Requirements: 
int Trie::completeCount(string word) 
{
	TrieNode *temp = root;
	for (int i = 0; i < word.length(); ++i) 
	{
		int currentLetter = (int)word[i] - (int)'a';

		// if while searching for the given words in the trie that are part of the given input string if we come across a letter in the 
		// word that is not in the trie then we stop reading the user given input string and we stop traversing the trie. And we return 0, 
		// for if one of the letter in the given word is not in the trie then that word is not in the trie. 
		// Howvever, if all of the letters were in the trie then the word is in in trie and we return temp->prefixAmount with will contain
		// the number of words that begain with or coatain the given input string. 
		if (temp->child[currentLetter] == NULL)
		{
			return 0;
		}
		else 
		{
			temp = temp->child[currentLetter];
		}
	}
	return temp->prefixAmount;
}

// Function vector<string> complete(string): This function returns a vector of strings contianing all the words in the dictionary that 
// begin with the given input string. For each word found in the trie, there will be one value in the vector. If no matching words are
// found, the function will return an empty vector
// Inputs: string word, this is the word or prefix that function is to use to figure out how many words begin with that given prefix or word
// Returns: vector<string> if there words that match the given input string, this words are in the form of a string. Returns an empty 
// string when there are no words that match the given input string.
// Side Effects: if there are no words in the trie then no words can be found that match the input string so only an empty vector can
// be returned. 
// Asympotic Run Time: 
// Space Requirements: 
vector<string> Trie::complete(string word)
{
	
	TrieNode *temp = root;
	ostringstream str1;
	for (int i = 0; i < word.length(); ++i)
	{
		int currentLetter = (int)word[i] - (int)'a';
		if (temp->child[currentLetter] == NULL)
		{
			return words;
		}
		
		else
		{
			temp = temp->child[currentLetter];
			
			 arr[word[i] - 'a'];
			str1 << arr;
			string wordForVector = str1.str();
			words.push_back(wordForVector);
			
			
		}
		
	}
	
	for (int i = 0; i < words.size(); i++) {

		cout << words[i] << endl;
	}
	return words;
	

	
}

