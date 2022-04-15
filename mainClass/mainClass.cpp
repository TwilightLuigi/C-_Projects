// Sierra Sprungl
// Dr.Raymer
// CS 3100-01
// This is the main class for the project. This class will serve the purpose of testing the functions in all the cpp and h files. It does this
// by allowing the user to insert, search, and delete from the database. This functions will be tested on a hashtable that is not linked 
// with the record.h file and it conatins no students just random values, this is done to insure that the hashtable works before adding
// objects of record.h. After that the user is provided with a meun screen that allows for the insertion, search, and deletion of record objects
// in the hashtable. This is used to test that everything functions probelry with student objects. 

#include <string>
#include <iostream>
#include <algorithm>    
#include <array>        
#include <random>       
#include <chrono> 
#include <vector>
#include "Record.h"
#include "HashTable.h"

using namespace std; 

int main()
{
	// Testing the hashtable class starts, without the database class, this is done is ensure that I have a fully working hashtable.
	HashTable h1 = HashTable();
	HashTable h2 = HashTable();
	HashTable h3 = HashTable();
	cout << "Testing the HashTable class, without a student database" << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << endl;

	// Here the testing of the insert function starts, we create keys and values to put into the table along with a deflaut number of collsions
	// To test this function we have three tests set up, the first one makes sure somthing can be inserted when the table is empty. The second
	// one tests to make sure that a value can be inserted when there is a value in the hashtable and that the probing will work to reslove
	// a collsion. The thrid test, tests to make sure that duplicate values can not be inserted into the table.
	cout << "Testing The insert function" << endl;
	cout << "---------------------------" << endl; 
	int newKey = 12;
	int newValue = 3;
	int collsions = 0;
	int newKey2 = 34;
	int newValue2 = 7;
	cout << "Test 1: Tests to see if new key/value pair is inserted into the hashtable, should return 1, the number of collsions should also return: " << h1.insert(newKey, newValue, collsions) << endl;
	cout << "Test 2: Another test to see if when a new key/value pair is inserted the function returns 1 and the number of collsions: " << h1.insert(newKey2, newValue2, collsions) << endl;
	cout << "Test 3: Function should return 0 when we can't insert a key/avlue pair into the hashtable: " << h1.insert(newKey, newValue, collsions) << endl;
	cout << endl;

	// Testing of the remove function starts, here we use the keys/value varibles made in the insert tests and new key value that is not in the
	// table to test the remove function. There four tests that we do on the remove function. The first one tests to see if a value that is
	// in the hashtable can be removed from the table. The secound test makes sure that a key that is a tombstone can't be deteled. The
	// thrid test makes sure that a value that is not in the table can't be deleted. The last test tests to make sure that we the hashtable is
	// empty that we can't detele a value in it. 
	cout << "Testing the remove function" << endl;
	cout << "---------------------------" << endl;
	int keyNotInHT = 2345;
	cout << "Test 1: Tests to see if a key/value pair can be deteled from the hastable, should return 1: " << h1.remove(newKey) << endl;
	cout << "Test 2: Tests to see if a a key is a tombstone that it can't be deteled, should return 0: " << h1.remove(newKey) << endl;
	cout << "Test 3: Tests to see if a when a key is not in the hastable that it can't be deteled, should return 0: " << h1.remove(keyNotInHT) << endl;
	cout << "Test 4: Tests to see if a key values can't be deleted when the hashtable is empty should return 0: " << h2.remove(keyNotInHT);
	cout << endl;

	// Here the testing of the find function starts, here we declair a value to use for the value to return, a value that is in the hashtable
	// to search for and a value to searh=ch for that is not in the hashtable. There are three tests that will be used on these varibales
	// to test the hashtable find function. The first test, tests to see if a record that is in the hashtable can be found and that the value
	// in the table can be returend. The secound tests to see if that if a record can;t be found when the record is tombstone. The last test
	// is to make sure that a value that not in the hashtable can;t be found. 
	cout << "Testing Find function" << endl;
	cout << "---------------------" << endl;
	int value = 1;
	int keyToSearchFor = 34;
	int keyToSearchForThatIsNotInHT = 91;
	cout << "Test 1: Tests to see if a a record with the given key is found in the hashtable, if it is found we should return 1 and the value found: " << h1.find(keyToSearchFor, value) << endl;
	cout << "Test 2: Tests to see if a record when it is a thombstone can't be found in the hashtable, should return 0:  " << h1.find(newKey, value) << endl;
	cout << "Test 3: Tests to see if a record when it is not in the hashtable can't be found, should return 0: " << h1.find(keyToSearchForThatIsNotInHT, value) << endl;
	cout << endl;

	// Here we are testing the aplha function. There is only one test and it makes sure that the aplha value is returned correctly. 
	cout << "Testing alpha function" << endl;
	cout << "----------------------" << endl;
	cout << "Test 1: Tests to see if function returns the correct loading factor: " << h1.alpha() << endl;
	cout << endl;

	// Here we are testing the overload function. There is only one test and it makes sure that the overlaod operator prints out the hashtable.
	cout << "Testing the overload operator << function" << endl;
	cout << "-----------------------------------------" << endl;
	cout << "Test 1: Tests to see that the overload operator properly prints out all the key/value pairs in the table along with slot number: " << endl;
	cout << h1 << endl;
	cout << endl; 
	cout << endl;
	
	// Testing of the hashtable class with a student database starts
	cout << "Testing The HashTable class with the Student database" << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << endl;

	// Here we set up a value to be our loop control and we create a vector of student objects. We use these to create a main menu for the
	// user to interact with, the user can choose to insert a value into the vector and the hashtable, search them, or delete from it. 
	// This is how we test the insert, search, and delete functions for this hashtable with a student database. 
	bool quit = 0;
	vector<Record> students;
	while (quit != 1) 
	{
		cout << "Would you like to (I)nsert or (D)elete a record, or (S)earch for a record, or (Q)uit?" << endl;
		cout << "Enter action: " << endl;
		char action;
		cin >> action;

		// If the user types I, then they want to insert a value, they are then prompted to enter in infotmation about the student
		// After this is done an obeject of type reord is made and put into the vector. After this we the insert the UID of the student 
		// and its postion in the vector into the hashtable. After this is done, if the insertion was successful, then a message saying
		// that it was successful is printed to the user along with the collsions that occured. If the insertion failed, then the user
		// is issused an error message. 
		if (action == 'I')
		{
			cout << "Inserting a new record" << endl;
			cout << "Last name: " << endl;
			string lastname;
			cin >> lastname;
			cout << "First name: " << endl;
			string firstname;
			cin >> firstname;
			cout << "UID: " << endl;
			int UID;
			cin >> UID;
			cout << "Year: " << endl;
			string year;
			cin >> year;
			Record newStudent = Record(lastname, firstname, UID, year);
			students.push_back(newStudent);
		    int valueToGoWithUID = 0;

			if (h3.insert(UID, valueToGoWithUID, collsions) == true)
			{
				cout << "Record Inserted and there were " << collsions << " collsions during insertion " << endl;
			}
			else {
				cout << "ERROR: Record could not be inserted, this record is already in the table." << endl;
			}
		}

		// If the user types an S then they want to search for a studnet in the hashtable. So they are then prompted to enter a UID to search for
		// if the UID is found in the hashtable, then a message saying that the UID was found is displayed to user along with the spot in the
		// vector where the value is. If the UID is not found in the hash table, then we display an error message saying that the UID was
		// not found.
		else if (action == 'S')
		{
			cout << "Enter UID to search for: " << endl;
			int UID;
			int value =0;
			cin >> UID;
			if (h3.find(UID, value) == true)
			{
				cout << "Searching......record found: "  << value << endl;
				
			}
			else {
				cout << "Searching........record not found" << endl;
			}
		}

		// If the user types a D, this means that they want to delete a record from the hashtable and the vector of student records. The user
		// is prompted to enter a UID to detele. If the deletion was successful then a message saying that the record was deleted is shown, and
		// the record is deleted from both the hashtable and the vector of record objects. If the UID could not be deteled then an error 
		// message is displayed to the user. 
		else if (action == 'D')
		{
			cout << "Enter UID to delete: " << endl;
			int UID;
			cin >> UID;
			if (h3.remove(UID) == true)
			{
				cout << "Record Deleted" << endl;
				students.pop_back();
			}
			else
			{
				cout << "ERROR: Record could not be deleted " << endl;
			}
		}

		// If the user types Q it means that they want to quit the program. So a message saying exiting is displayed an the program stops. 
		else if (action == 'Q')
		{
			cout << "Exiting" << endl;
			quit = 1;
		}
	}

	// Here we are once again testing the alpha and << operator functions to make sure they work properly with both the hashtable and the
	// vector. 
	cout << "The current loading factor is: " << h3.alpha() << endl;
	cout << "This is the current hashtable: " <<  endl;
	cout << h3 << endl;
	return 0;
	system("pause");
}