/*
* Name: Mandar Tamhane
* Matriculation Number: 170021792
*/

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

  HashTable()       // constructor, initializes table of size 11;
  {
    table = new Table(11);
    this->num = 0;
  }

  HashTable(size_t temp) // constructor, requires size of table as arg
  {
    table = new Table(temp);
    this->num = 0;
  }

  ~HashTable() // destructor
  {
  }

  size_t size() // returns size of the hash table (number of buckets)
  {
    return table->size();
  }

  size_t hash_function(ulint key) // the table's hash function - Knuth Variant on Division (Source: https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html)
  {
      return key*(key+3) % size();
  }

  ulint getValue(ulint key) // find and return data associated with key
  {
    ulint hashData = hash_function(key);
    
    list<HashNode>::iterator iterator1; // defining an iterator to parse through

    for (iterator1 = table->at(hashData).begin(); iterator1 != table->at(hashData).end(); iterator1++)
      if (iterator1->getKey() == key) // check if the key required exists in the hash table
        return iterator1->getValue();

    return HashTableError(1); // KEY_NOT_FOUND
  }

  void insert(ulint key, ulint value) // insert data associated with key into table
  {
    HashNode temp(key, value); // creating a new node with the key and the value
  
    size_t oldSize = size(); // creating variable to store the size of the table

    if(num/oldSize>0.9) // checking if the hash table is densely populated
    {
      size_t newSize = oldSize*2; // creating a new size for the hash table
      table->resize(newSize); // resizing the old table to the new size
      rehash(newSize); // rehashing the old elements into the table
    }
    
    table->at(hash_function(key)).push_back(temp); // adding the element to the hash table

    num++; // incrementing num pointer
  }


  void erase(ulint key)  // remove key and associated data from table
  {
    ulint temp = hash_function(key);
    list<HashNode>::iterator iterator2; // iterator to iterate through the list
  
    for (iterator2 = table->at(temp).begin(); iterator2 != table->at(temp).end(); iterator2++)
      if (iterator2->getKey() == key) // check if the key exists
        table->at(temp).erase(iterator2); // erase the key
    
    num--;
  }

  void rehash(size_t newSize) // sets a new size for the hash table, rehashes the hash table 
  {
    list<HashNode> tempList;
    list<HashNode>::iterator iterator3;
    ulint oldSize = size();

    /*
    * Loop to transfer the contents of the table to a temporary table
    */
    for(ulint i=0; i<oldSize; i++)
      for (iterator3 = table->at(i).begin(); iterator3 != table->at(i).end(); iterator3++)
       {
        HashNode newNode (iterator3->getKey(), iterator3->getValue());
        tempList.push_back(newNode);
       }

    delete table; // deleting the old table
    table = new Table(newSize); // creating a new table with the new size

    for (iterator3 = tempList.begin(); iterator3 != tempList.end(); iterator3++) // loop to move all the elements back to the table with the new size
    {
      insert(iterator3->getKey(), iterator3->getValue());
    }
  }

};

#endif
