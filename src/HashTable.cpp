#include "../include/HashTable.hpp"

/* HASH TABLE */

/*
HASH-FUNCTION(key)
1   return (key - offset) % size
*/

//hash function
int HashTable::hashFunction(char key) {
    return (key - offset) % size;
}

/*
RESIZE()
1   newSize ← size + 3
2   newTable ← new Vector[newSize] of KVLinkedList
3
4   for i ← 0 to size - 1
5       current ← table[i].GET-HEAD()
6       while current ≠ NIL
7           newIndex ← (current.key - offset) % newSize
8           newTable[newIndex].INSERT(current.key, current.value)
9           current ← current.next
10
11  table ← newTable
12  size ← newSize
*/

//resize and rehash
void HashTable::resize() {
    int newSize = size + 3;
    std::vector<KVLinkedList> newTable(newSize);

    for (int i = 0; i < size; ++i) {
        KVNode* current = table[i].getHead();
        while (current != nullptr) {
            int newIndex = (current -> key - offset) % newSize;
            newTable[newIndex].insert(current -> key, current -> value);
            current = current -> next;
        }
    }

    table = newTable;
    size = newSize;
}

//initialize hash table with 3 buckets
HashTable::HashTable(int initialSize) : size(initialSize), table(initialSize), offset(0) {}

/*
SET-OFFSET(firstKey)
1   offset ← firstKey
*/

//set the offset to the first user input
void HashTable::setOffset(char firstKey) {
    offset = firstKey;
}

/*
INSERT(key, value)
1   if offset == 0
2       SET-OFFSET(key)
3   index ← HASH-FUNCTION(key)
4   if table[index].GET-COUNT() ≥ 3
5       RESIZE()
6           index ← HASH-FUNCTION(key)
7   table[index].INSERT(key, value)
*/

//insert key-value pair into hash table
void HashTable::insert(char key, double value) {
    if (offset == 0) {
        setOffset(key);
    }
    int index = hashFunction(key);
    if (table[index].getCount() >= 3) {
        resize();
        index = hashFunction(key);
    }
    table[index].insert(key, value);
}

/*
SEARCH(key)
1   if offset == 0
2       return NIL //offset is not set
3   index ← HASH-FUNCTION(key)
4   return table[index].SEARCH(key)
*/

//search for element by key
KVNode* HashTable::search(char key) {
    if (offset == 0) {
        return nullptr; //offset is not set
    }
    int index = hashFunction(key);
    return table[index].search(key);
}

/*
REMOVE(key)
1   if offset ≠ 0
2       index ← HASH-FUNCTION(key)
3       table[index].REMOVE(key)
*/

//remove element by key
void HashTable::remove(char key) {
    if (offset != 0) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
}

//display hash table
void HashTable::display() {
    for (int i = 0; i < size; ++i) {
        std::cout << "Bucket " << i << ": ";
        table[i].display();
    }
}