#ifndef MY_HASH_NODE
#define MY_HASH_NODE
#include <iostream>

using namespace std;

class HashNode
{
  unsigned long key;   // The hash node's key
  unsigned long value; // The key's associated data
  HashNode* next;

public:

	HashNode()
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

	unsigned long getKey()
	{
  		return key;
  	}

  	unsigned long getValue()
  	{
  		return value;
  	}

  	void assign(unsigned long key, unsigned long value)
  	{
  		this->key = key;
  		this->value = value;
		this->next = NULL;
  	}

};

#endif
