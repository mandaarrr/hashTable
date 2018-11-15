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
  typedef vector <list<HashNode>> Table;
  Table *table; // size of table is stored in the Table data structure
  size_t num;   // number of entries in the HashTable;

public:

  HashTable()       // constructor, initializes table of size 1;
  {
    table = new std::vector<list<HashNode>>();
    this->num = 11;
  }

  HashTable(size_t temp) // constructor, requires size of table as arg
  {
    this->num = temp;
    table = new Table(num);
  }

  ~HashTable()
  {
  }    // deconstructor

  size_t size() // returns size of the hash table (number of buckets)
  {
    return num;
  }

  size_t hash_function(ulint value)
  {
     size_t key = value % size();
     return key;
  }  // the table's hash function

  ulint getValue(ulint);    // find and return data associated with key

  void insert(ulint key, ulint value)
  {
  } // insert data associated with key into table

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
