#include "Sequence.h"

Sequence::Sequence( size_type sz )
{

}

Sequence::Sequence( const Sequence& s )
{
}

Sequence::~Sequence()
{
}

Sequence& Sequence::operator=( const Sequence& s )
{
}

Sequence::value_type& Sequence::operator[]( size_type position )
{
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