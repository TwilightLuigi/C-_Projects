// Sierra Sprungl
// Dr. Raymer
// CS 3100-01
// This is the hashtable class, this class will be used to implement the functions of the hashtable. The hashtable will be implemnted using
// an array of MAXHASH. The hashtable will be able to insert, search for, delete, return the loading fctor, overload the << operator so
// the  slot number and key values can be printed, and be able to hash and probe. 
// For grading purposes I returned the collsions in the insert function and interperted your instructions to return and deal with them in the
// insert function.

#include <string>
#include <iostream>
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono> 
#include "Record.h"
#include "Slot.h"
#include "HashTable.h"
#include "hashfunction.h"


using namespace std;


// Constuctor HashTable(): creates a hashtable object that contains an int count value, this helps to keep track of how many spots are left in
// the hashtable. We also declair the size of the hashtable in arraySize, we create a array to hold the values and an array to do our probing 
// on. We also do our random probing in this constuctor. 
// Inputs: none
// Returns: nothing 
// Side Effects: none 
HashTable::HashTable()
{
	float count = 0;
  
	for (int i = 0; i < arraySize; i++)
	{
		probingArray[i] = i;
	}

	random_shuffle(&probingArray[0], &probingArray[MAXHASH]);
}

// Function insert(int key, int value, int& collsions): inserts a new key/value pair into the hash table, however dupliate keys are not allowed
// the function should return true when a key/value pair is successfully inserted into the hashtable, and false if the pair could not be inserted 
// if the insertion is successfull=, the number if collisions during the insert operation are also returned in collisions.
// Input: int key - the key that will be used for hashing, int value to be inserted into the hastable, int& collisions the number of 
// collisions that have occured. 
// Returns: bool true, then the key/value pair could be inserted, bool false when the value could not be insetred due to it being a dupliate
// key/value pair. 
// Side Effects: if the hashtable is full or a dupliate key/value is found in the table than insertion can't take place
bool HashTable::insert(int key, int value, int& collisions)
{
	int hashedArrayIndex = ::hash(key) % MAXHASH;
	int homeArrayIndex = hashedArrayIndex;
	int takenIndex = 0; 
	int tmepIndex = 0;

	// While the value has not been inserted into tha table we loop and search the hashtable for an empty spot or a tombstone spot, if either is 
	// found then the value is inserted into the hashtable and the function returns true with the number of collsions that occured and we
	// break from the loop we increase the number  of spots taken in the table. If the value to be insetred is already in the hashtable 
	// then we return flase and break from the loop. 
	while (!takenIndex)
	{
		if (array[hashedArrayIndex].isEmpty() || array[hashedArrayIndex].isTombstone())
		{
			array[hashedArrayIndex] = Slot(key, value);
			count++;
			
			return true;
			return collisions;
			
		}
		else if (array[hashedArrayIndex].isNormal())
		{
			if (array[hashedArrayIndex].getKey() == key)
			{
				return false;
			}
			else
			{
				collisions++;
				hashedArrayIndex = (homeArrayIndex + probingArray[tmepIndex]) % MAXHASH;
				tmepIndex++;
			}
		}
	}
	return false;
	return collisions;
}

// Function remove(int key): if given a record with the given key in the hash table, it is deleted and the function returns true, if not 
// it returns false.
// Inputs: int key, the UID of the student to be deleted from the record.
// Returns: bool true when the value is deleted successfully, bool false when the value can't be deleted
// Side Effects: will not allow for deletions when the table is empty, the function will return false.
bool HashTable::remove(int key)
{
	int hashedArrayIndex = ::hash(key) % MAXHASH;
	int homeArrayIndex = hashedArrayIndex % MAXHASH;
	int removedIndex = 0;
	int tmepIndex = 0;

	// while the value to be deteled has not been deleted, we search the hashtable for this value, if it found we remove it from the table, and
	// decease the number of taken spots in the table, and return true. Uf the value is not in the hash table thne we reutnr false becauase 
	// the value to be found is not in the hash table. We incrment out temporary index and update the hashed values in ower hashatable. 
	while (!removedIndex)
	{
		if (array[hashedArrayIndex].getKey() == key)
		{
			array[hashedArrayIndex] = Slot();
			array[hashedArrayIndex].kill();
			count--;
			return true;
		}
		if (array[hashedArrayIndex].isTombstone() || array[hashedArrayIndex].isEmpty())
		{
			return false;
		}
		if (array[hashedArrayIndex].isNormal())
		{
			hashedArrayIndex = (homeArrayIndex + probingArray[tmepIndex]) % MAXHASH;
			tmepIndex++;
		}
	}
	return false;
}

// Function find(int key, int& value): searches the hashtable/ record for a student UID, if one is found in the hash table, the function returns
// true, if not it returns false.
// Inputs: int key, the UID to be searched for, int&value, the value to be retruned from the hashtable when it is found.
// Returns: bool true when a student is found with the given UID, bool false when a student with the give UID can't be found. int& value,
// the value found in the hastable that corroponses to the given UID. 
// Side Effects: if the hashtable is empty then no values can be found and the function returns false. 
bool HashTable::find(int key, int& value)
{
	int hashedArrayIndex = ::hash(key) % MAXHASH;
	int homeArrayIndex = hashedArrayIndex % MAXHASH;
	int fIndex = 0;
	int tmepIndex = 0;

	// while the  value we are searching for has not been found we counitine to go throguht the hashtable, if the values is found we return true
	// and the value found and bteak from the loop. If the value we are trying to find is not in the hashtable then we return false. 
	while (!fIndex)
	{
		if (array[hashedArrayIndex].getKey() == key)
		{
			value = array[hashedArrayIndex].getValue();
			return true;
			return value;
		}
		if (array[hashedArrayIndex].isTombstone() || array[hashedArrayIndex].isEmpty())
		{
			return false;
		}
		if (array[hashedArrayIndex].isNormal())
		{
			hashedArrayIndex = (homeArrayIndex + probingArray[tmepIndex]) % MAXHASH;
			tmepIndex++;
		}
	}
	return false;
	return value;
}

// Function alpha(): returns the current loading factor of the hashtable. 
// Inputs: none
// Returns: float loadingFactor, the alpha or loadinf factor for the hashtable
// Side Effects: none
float HashTable::alpha()
{
	float loadingFactor = count / MAXHASH;
	return loadingFactor;

}

// Function ostream& operator << (ostream& os, HashTable& h): overloads the operator << such that cout << theHashTable prints all the key/value
// pairs in the table, alomg with their hash table slot number, to cout. This function however does not print out any empty or tombdtone slots.
// Inputs: ostream& os - the os operator that will be used to print out the hashtable. HashTable& h - the hashtable to be printed out.
// Returns: ostream& os, this is going to the be key/value pairs in the table, along with thier hash table slot number to cout. 
// Side Effects: if the hashtable is empty then nothing can be printed. 
 ostream& operator <<(ostream& os, const HashTable& h)
{
	 // while we have not reached the end of the hashtable we go through the hashtable and when we come across a normal slot or a slot that 
	 // contains a value to print we print it out along with its key and slot number, we do this until all the slots have been visted or until
	 // the end of the hashtable is reached. 
	 for (int i = 0; i < MAXHASH; i++)
	 {
		 if (h.array[i].isNormal())
		 {
			 os << "The Slot number is: " << i << " The key that goes along with this slot is: " << h.array[i].getKey() << " This is the value: " << h.array[i].getValue() << endl;
		 }
		 
	 }
	 return os;
}


