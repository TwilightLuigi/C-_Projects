// Sierra Sprungl
// Section Number: 01
// Dr. Rizki 

#include "Sequence.h"

Sequence::Sequence( size_type sz )
{
	numElts = sz;
	elts = new int[sz];
}

Sequence::Sequence( const Sequence& s )
{
	numELts = s.numElts;
	elts = new int[numElts];
	for (int i = 0; i < numElts; i++)
	{
		elts[i] = s.elts[i];
	}
}

Sequence::~Sequence()
{
	cout"Deleting the sequence";
	delete[] elts;
}

Sequence& Sequence::operator=( const Sequence& s )
{
	if (this != &s) {
		delete[]elts;
		numElts = s.numElts;
		elts = new int[numElts];
		for (int i = 0; i < numElts; i++) {
			elts[i] = s.elts[i];
		}
		return *this;
	}
}

Sequence::value_type& Sequence::operator[]( size_type position )
{
	for (unsigned i = 0; i < postion / 2; i++) {
		int temp;
		temp = sequence 
	 }

}

Sequence::value_type& Sequence::at( size_type position )
{


}

void Sequence::push_back( const value_type& value )
{
}

void Sequence::pop_back()
{
}

void Sequence::insert( size_type position, value_type value )
{
}

const Sequence::value_type& Sequence::front() const
{
}

const Sequence::value_type& Sequence::back() const
{
}

bool Sequence::empty() const
{
}

Sequence::size_type Sequence::size() const
{
}

void Sequence::clear()
{
}

void Sequence::erase( size_type position, size_type count )
{
}

ostream& Sequence::print( ostream& os )
{
}


ostream& operator<<( ostream& os, Sequence& s )
{
}