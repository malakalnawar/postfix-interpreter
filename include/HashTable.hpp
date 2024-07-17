#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <iostream>
#include "../include/LinkedList.hpp"

/* HASH TABLE */

/**
 * @class HashTable
 *
 *	The hash table accepts key-value pair nodes.
 *	The first input by the user sets the offset for the hash function.
 *	It starts with a vector of size 3.
 *	Collisions are handled with separate chaining (linked list).
 *	Each element in the vector can have a maximum of 2 additional nodes connected to it before resizing occurs.
 *	Resizing adds 3 to the main vector before rehashing, and the limit of nodes per element remains the same.
 */

/*
CLASS HashTable
1   table //linked list as underlying data structure (KVLinkedList)
2   size //size of buckets
3   offset //offset for hash function
4
5   HASH-FUNCTION(key) //hash function
6
7   RESIZE() //resize table
8   
9   SET-OFFSET(key) //set offset with first input
10   
11  INSERT(key, value) //inset key-value pair into table
12
13  SEARCH(key) //return value by key
14
15  REMOVE(key) //remove value by key
*/

class HashTable {
private:
    std::vector<KVLinkedList> table; //buckets (vector of linked lists)
    int size; //size of buckets
    int offset; //offset for hash function

    //hash function
    int hashFunction(char key);

    //resize and rehash
    void resize();

public:
    //initialize hash table
    HashTable(int initialSize = 3);

    //set the offset to the first user input
    void setOffset(char firstKey);

    //insert key-value pair into hash table
    void insert(char key, double value);

    //search for element by key
    KVNode* search(char key);

    //remove element by key
    void remove(char key);

    //display hash table
    void display();
};

#endif