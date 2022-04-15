// Sierra Sprungl
// Dr.Raymer
// CS 3100-01
// This class was provided to us. This classeses purpose is to create a slot object, that will be used to hold to the values in the hashtable
// the slot object will also allow us to create a new slot object, kill a slot, meaning that we turn it into a tombstone meaning that the 
// data in that slot has been deleted. We can also get the key and the value that is in a spot, check to see if a spot is empty or normal,
// normal meaning that the slot is not a tomnstone and we can insert a value into it. Lastly, we can check to see if the spot is a tombstone
// and print out the slot object. 
// FILE: Slot.h
// CLASS PROVIDED: Slot

#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// There are three types of slots in a closed hash:
// Normal slots, empty slots, and tombstones
enum SlotType { normalSlot, emptySlot, tombstone };


// Each slot holds an integer key and an integer value.
// The integer value will be used as an index into the
// record store.

class Slot
{
private:
	int key;
	int value;
	SlotType type;

public:

	// The default constructor produces an empty slot.
	Slot()
	{
		key = 0;
		type = emptySlot;
	}

	// This constructor uses an initialization list
	// See "member initialization" at: http://www.cplusplus.com/doc/tutorial/classes/
	Slot(int newkey, int newvalue)
		: key(newkey), value(newvalue)
	{
		type = normalSlot;
	}

	// Convert a slot to a tombstone
	void kill() {
		type = tombstone;
	}

	// Get the integer key of a slot
	int getKey() const {
		return key;
	}

	// Get the value of a slot
	int getValue() const {
		return value;
	}

	// Check if a slot is empty
	bool isEmpty() const {
		return(type == emptySlot);
	}

	// Check if a slot is a normal slot
	bool isNormal() const {
		return(type == normalSlot);
	}

	// Check if a slot is a tombstone
	bool isTombstone() const {
		return (type == tombstone);
	}

	// Overload the << operator for printing slots
	friend ostream& operator<<(ostream& os, const Slot& me) {
		if (me.isTombstone())
			os << "<<Tombstone>>";
		else if (me.isEmpty())
			os << "<<Empty>>";
		else
			os << "Key: " << me.key << ", Value: " << me.value;
		return os;
	}

	// No destructor is needed as Slots don't use any dynamically
	// allocated memory
	~Slot()
	{
	}
};


