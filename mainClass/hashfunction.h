// Sierra Sprungl
// Dr. Raymer
// CS 3100-01
// This file was given to us, this file provides the function of creating a hash function for us to use in our hashtable.
// FILE: hashfunction.h
// CLASS PROVIDED: NA

#pragma once

// A bitwise hash function written by Justin Sobel
// Code adapted from http://www.partow.net/programming/hashfunctions/#RSHashFunction

unsigned int hash(const int key)
{
	const char* kptr = (char *)&key;
	unsigned int length = sizeof(int);
	unsigned int hash = 1315423911;
	unsigned int i = 0;

	for (i = 0; i < length; ++kptr, ++i)
	{
		hash ^= ((hash << 5) + (*kptr) + (hash >> 2));
	}

	return hash;
}
