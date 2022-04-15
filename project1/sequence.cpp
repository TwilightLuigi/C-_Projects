// Sierra Sprungl
// CS 3100-01
// Dr. Raymer
// This class will serve the function of creating a sequence object, in which the test harness will perform actions on it.
// This class will perform the following actions: create a sequence, copy and delete a sequence, assign a sequence  to a sequence,
// return a reference to the item at a index position in the sequence, add an element to the end of the sequence, 
//remove item at the end of the sequence, insert a item in the sequence at a index position, returns a reference to the first item 
//in the sequence,  returns a reference to the last item in the sequence,tests to see if the sequence is empty, 
//clears the sequnce making it empty, delete elements in a location in the sequence, and print the sequence. 
//This sequence will be implamented using an array. 

#include "sequence.h"

// This function creates a sequence object with sz size given by the test harness. This is the constuctor for the class. 
Sequence::Sequence(size_type sz)
{
	numElts = sz;
	elts = new int[sz];
	for (size_type i = 0; i < sz; ++i)
	{
		elts[i] = sz;
	}
}

// This function is the copy constuctor, it serves to create a sequence from an existing sequence s given by the test harness. 
Sequence::Sequence(const Sequence& s)
{
	numElts = s.numElts;
	elts = new int[numElts];
	for (int i = 0; i < numElts; i++)
	{
		elts[i] = s.elts[i];
	}
}

// This is the deconstuctor, it's job is to destory the sequence and release the memory associated with the sequence. 
Sequence::~Sequence()
{
	delete[]elts;
}

// This function serves the prupose as the assignment operator, it's job is to release the current sequence and create a deep copy 
//of sequence seq 
Sequence& Sequence::operator=(const Sequence& s)
{
	if (this != &s)
	{
		delete[]elts;
		numElts = s.numElts;
		elts = new int[numElts];
		for (int i = 0; i < numElts; i++)
		{
			elts[i] = s.elts[i];
		}
	}
	return *this;
}

// This function serves the prupose to return a reference to the item at the index position given by the test harness
Sequence::value_type& Sequence::operator[](size_type position)
{
	if (position < 0 || position >= elts[numElts])
	{
		return elts[position];
	}
	return elts[position];
}

// This function serves the prupose to return a reference to the item at the index position given by the test harness
Sequence::value_type& Sequence::at(size_type position)
{
	if (position < 0 || position >= elts[numElts])
	{
		return elts[position];
	}
	return elts[position];
}

// This function will add values to the sequence from the back of the sequence, while increasing the size to allow of more values 
// to be added
void Sequence::push_back(const value_type& value)
{
	int* tmpElts = new int[numElts + 1];
	for (int i = 0; i < numElts; i++)
	{
		tmpElts[i] = elts[i];
	}
	tmpElts[numElts] = value;
	delete[] elts;
	elts = tmpElts;
	numElts++;
}

// This function will delete values in the sequence from the back of the sequence. An exception is thrown if the sequence is empty. 
void Sequence::pop_back()
{
	if (!elts[numElts] == NULL)
	{
		int* tmpElts = new int[numElts + 1];
		for (int i = 0; i < numElts; i++)
		{
			tmpElts[i] = elts[i];
		}
		numElts--;
	}
	if (numElts == 0)
	{
		throw exception("The sequence is empty, can't call pop_back on an empty sequence");
	}
}

// This function inserts a value into the seqeunce at the given position and then shifts everything to the right to make room for the 
// new value. An expection is thrown if the postion given is out of the bounds of the sequence. 
void Sequence::insert(size_type position, value_type value)
{
	if (position > numElts - 1)
	{
		throw exception("That position is out of the bounds of the sequence");
	}
	else if (position < numElts)
	{
		elts[position] = value;
	}
	else
	{
		int* tmpElts = new int[numElts + 1];
		for (int i = 0; i < numElts; i++)
		{
			tmpElts[i] = elts[i];
		}
		tmpElts[numElts] = value;
		numElts++;
		delete[] elts;
		elts = tmpElts;
	}
}

// This function returns the value in the leading postion in the sequence, the [0] position. 
// If the sequence is empty an exception is thrown 
const Sequence::value_type& Sequence::front() const
{
	if (numElts == 0)
	{
		throw exception("Can't call frount on an empty sequence");
	}
	else
	{
		return elts[0];
	}
}

// This function returns the value at the end of the sequence, the [numElts -1] position. An expection is thrown if the sequence is empty 
const Sequence::value_type& Sequence::back() const
{
	if (numElts == 0)
	{
		throw exception("Can't call back on an empty sequence");
	}
	else
	{
		return elts[numElts - 1];
	}
}

// This function tests to see if the squence is empty or not, it returns 1 if empty and 0 if not empty. 
bool Sequence::empty() const
{
	if (numElts == 0)
	{
		return true;
	}
	if (numElts != 0)
	{
		return false;
	}

}

// This function returns the size of the sequence.
Sequence::size_type Sequence::size() const
{
	return numElts;
}

// This function deletes all the elements in the sequence, returning it to an empty state. 
void Sequence::clear()
{
	if (elts[numElts] != NULL)
	{
		int* tmpElts = new int[numElts + 1];
		for (int i = 0; i < numElts; i++)
		{
			tmpElts[i] = elts[i];
			numElts--;
		}
		numElts--;
		numElts--;
	}
}

// This function deletes n number values starting at the postion picked by the test harness. An excpetion is thrown if the 
// position picked is invalid.
void Sequence::erase(size_type position, size_type count)
{
	if (position > numElts - 1)
	{
		throw exception("That postion is out of bounds of the sequence");
	}
	else
	{
		for (int i = position; i < numElts; i++)
		{
			elts[i];
			if (position >= 0 && position + count < numElts)
			{
				elts[i] = elts[i + 1];
			}
			numElts--;
		}
	}
}

// Prints out the sequence, with all elements being seprated by a comma 
ostream& Sequence::print(ostream& os)
{
	os << "<";
	size_t last = numElts - 1;
	for (size_t i = 0; i < numElts; i++)
	{
		os << elts[i];
		if (i != last)
		{
			os << ", ";
		}
	}

	os << ">";
	return os;
}

// Prints out the sequence, with all elements being seprated by a comma 
ostream& operator<<(ostream& os, Sequence& s)
{
	os << "<";
	size_t last = s.numElts - 1;
	for (size_t i = 0; i < s.numElts; i++)
	{
		os << s[i];
		if (i != last)
		{
			os << ", ";
		}
	}
	os << ">";
	return os;
}