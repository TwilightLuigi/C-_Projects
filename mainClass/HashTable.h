// Sierra Sprungl
// Dr. Raymer
// CS 3100 -01
// This file will declair the functions, classes, and variables to be used in the 
// hashtable class and .cpp file. this project was done using a closed hashtable with
// pseudo-random probing.
// FILE: HashTable.h
// CLASS PROVIDED: HashTable

#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>    
#include <array>       
#include <random>       
#include <chrono> 
#include "Record.h"
#include "Slot.h"

#define MAXHASH 1000

using namespace std;

// Class HashTable: This class will implelment a hashTable that can implement the functions of the hashtable. The hashtable will be 
// impleemnted using an array of MAXHASH. The hashtable will be able to insert, search for, delete, return the loading fctor, 
// overload the << operator so the  slot number and key values can be printed, and be able to hash and probe. In this file we are delcaring
// the public functions and the private variables to be used in the cpp file. 
class HashTable
{

public:
	HashTable();
	bool insert(int key, int value, int& collisions);
	bool remove(int key);
	bool find(int key, int& value);
	float alpha();
	friend ostream& operator <<(ostream& os, const HashTable& h);
	

private:
	int arraySize = MAXHASH;
	float count = 0;
    int probingArray[MAXHASH-1];
	Slot array[MAXHASH];
};