#include "../include/Stack.hpp"

/* STACK */

//initialize stack
Stack::Stack() {}

/*
PUSH(value)
1   list.INSERT(value)
*/

//add element to the top of the stack
void Stack::push(const std::string& value) {
    list.insert(value);
}

/*
POP()
1   if not IS-EMPTY()
2       list.REMOVE(GET-HEAD())
3   else
4       error "Stack is empty"
*/

//remove top element from the stack
void Stack::pop() {
    //check if empty
    if (!isEmpty()) {
        //remove head node
        list.remove(list.getHead() -> value);
    } else {
        std::cout << "Stack is empty" << std::endl;
    }
}

/*
TOP()
1   if not IS-EMPTY()
2       list.GET-HEAD()
3   else
4       error "Stack is empty"
*/

//return top element of the stack
const std::string& Stack::top() {
    // Check if empty
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty");
    }
    return list.getHead()->value;
}

/*
IS-EMPTY()
1   return list.GET-HEAD() == NIL
*/

//check if empty
bool Stack::isEmpty() {
    return list.getHead() == nullptr;
}

/*
SIZE()
1   count ← 0
2   current ← list.GET-HEAD()
3   while current ≠ NIL
4       count ← count + 1
5       current ← current.next
6   return count
*/

//return number of elements in the stack
int Stack::size() {
    int count = 0;
    SNode* current = list.getHead();
    while (current != nullptr) {
        count++;
        current = current -> next;
    }
    return count;
}

//display stack
void Stack::display() {
    list.display();
}
