/*
* Name: Mandar Tamhane
* Matric Number: 170021792
*/


#ifndef MY_HASH_NODE
#define MY_HASH_NODE
#include <iostream>

using namespace std;

class HashNode
{
  unsigned long key;   // The hash node's key
  unsigned long value; // The key's associated data
  HashNode* next; // The pointer to the next node

public:

	HashNode() // Default Constructor
	{
		this->key = 0;
		this->value = 0;
		this->next = NULL;
	}

	HashNode(unsigned long key, unsigned long value) // Constructor
	{
		this->key = key;
		this->value = value;
		this->next = NULL;
	}

	unsigned long getKey() // Return the key of the node
	{
  		return key;
  	}

  	unsigned long getValue() // Return the value of the node
  	{
  		return value;
  	}

  	void assign(unsigned long key, unsigned long value) // Assign the key and value to the node
  	{
  		this->key = key;
  		this->value = value;
		this->next = NULL;
  	}

};

#endif
