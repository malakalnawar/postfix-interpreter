#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

/* LINKED LISTS */

/**
 * @struct SNode
 * @brief Represents a node in a singly linked list storing a single string value.
 * 
 * @class SLinkedList
 * @brief Represents a singly linked list that stores nodes containing single string values.
 * 
 * @struct KVNode
 * @brief Represents a node in a linked list storing a key-value pair.
 * 
 * @class KVLinkedList
 * @brief Represents a linked list that stores nodes containing key-value pairs.
 */

/* NODE (SINGLE VALUE) */

/*
STRUCT SNode
1   value //value stored
2   next //next node
*/

struct SNode {

    std::string value; //single string value (token)
    SNode* next; //next node

    //initialize node with single string value and next node (as null pointer)
    SNode(const std::string& v) : value(v), next(nullptr) {}
};

/* LINKED LIST (SINGLE VALUE) */

/*
CLASS SLinkedList
1   head //head node
2   count //number of nodes in the list
3
4   GET-HEAD() //return top node
5 
6   GET-COUNT() //return number of nodes in list
7
8   INSERT(key, value) //insert new node with value
9
10  SEARCH(key) //return node by key
11
12  REMOVE(key) //remove node by key
*/

class SLinkedList {
    private:
        //head
        SNode* head;

    public:
        //initialize linked list
        SLinkedList();

        //retrieve head pointer
        SNode* getHead() const;

        //insert node with a single value
        void insert(const std::string& value);

        //search for node by value
        SNode* search(const std::string& value);

        //remove node by value
        void remove(const std::string& value);

        //display linked list
        void display();
};

/* NODE (KEY-VALUE PAIR) */

/*
STRUCT KVNode
1   key //key identifier
2   value //value stored
3   next //next node
*/

struct KVNode {

    char key;
    double value;
    KVNode* next; //next node

    //initialize node with key-value pair and next node (as null pointer)
    KVNode(char k, double v) : key(k), value(v), next(nullptr) {}
};

/* LINKED LIST (KEY-VALUE PAIR) */

/*
CLASS KVLinkedList
1   head //head node
2   count //number of nodes in the list
3
4   GET-HEAD() //return top node
5 
6   GET-COUNT() //return number of nodes in list
7
8   INSERT(key, value) //insert new node with value
9
10  SEARCH(key) //return node by key
11
12  REMOVE(key) //remove node by key
*/

class KVLinkedList {
private:
    //head
    KVNode* head;
    int count; //number of nodes

public:
    //initialize linked list
    KVLinkedList();

    //retrieve head pointer
    KVNode* getHead() const;

    //return number of nodes
    int getCount() const;

    //insert node with a key-value pair
    void insert(char key, double value);

    //search for node by key
    KVNode* search(char key);

    //remove node by key
    void remove(char key);

    //display linked list
    void display();
};

#endif