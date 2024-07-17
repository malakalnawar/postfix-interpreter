#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include "../include/LinkedList.hpp"

/**
 * @class Stack
 * @brief Represents a stack data structure using a singly linked list (SLinkedList) as the underlying storage.
 */

/* STACK */

/*
CLASS Stack
1   list //linked list as underlying data structure (SLinkedList)
3
4   PUSH() //add to top 
5 
6   POP() //remove top
7
8   TOP(key, value) //return top element
9
10  IS-EMPTY(key) //check if stack is empty
11
12  SIZE(key) //check size of stack
*/

class Stack {
private:
    SLinkedList list; //underlying data structure

public:
    //initialize stack
    Stack();

    //add element to the top of the stack
    void push(const std::string& value);

    //remove top element from the stack
    void pop();

    //return top element of the stack
    const std::string& top();

    //check if empty
    bool isEmpty();

    //return number of elements in the stack
    int size();

    //display stack
    void display();
};

#endif