#ifndef MY_HASH_TABLE
#define MY_HASH_TABLE

#include "HashNode.h"
#include <vector>
#include <list>
#include<iostream>

using namespace std;

enum HashTableError { OUT_OF_MEMORY, KEY_NOT_FOUND, DUPLICATE_KEY }; // extend if necessary

typedef unsigned long ulint;

class HashTable
{
  typedef vector <list<HashNode> > Table;
  Table *table; // size of table is stored in the Table data structure
  size_t num;   // number of entries in the HashTable;

public:

  HashTable()       // constructor, initializes table of size 1;
  {
    table = new Table();
    this->num = 11;
    table->resize(num);
  }

  HashTable(size_t temp) // constructor, requires size of table as arg
  {
    this->num = temp;
    table = new Table(num);
    table->resize(num);
  }

  ~HashTable() // deconstructor
  {
  }

  size_t size() // returns size of the hash table (number of buckets)
  {
    return num;
  }

  size_t hash_function(ulint key) // the table's hash function
  {
     size_t index = key % size();
     return index;
  }

  ulint getValue(ulint data) // find and return data associated with key
  {
    ulint hashData = hash_function(data);
    list<HashNode>::iterator it;

    for (it = table->at(hashData).begin(); it != table->at(hashData).end(); it++)
    {
      if (it->getKey() == data)
      {
        return it->getValue();
      }
    }

    return HashTableError(1);
  }

  void insert(ulint key, ulint value)// insert data associated with key into table
  {
    HashNode temp(key, value);
    table->at(hash_function(key)).push_back(temp);
  }


  void erase(ulint);        // remove key and associated data from table

  void rehash(size_t); // sets a new size for the hash table, rehashes the hash table 

  // extend if necessary
};

/* Implement the 
- Constructors, Destructor
- hash_function, insert, getValue methods
- erase, and rehash methods 
*/

#endif
