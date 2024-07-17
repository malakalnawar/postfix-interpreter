#include "../include/LinkedList.hpp"

/* LINKED LISTS */

/* LINKED LIST (SINGLE VALUE) */

//initialize linked list
SLinkedList::SLinkedList() : head(nullptr) {}

/*
GET-HEAD()
1   return head
*/

//retrieve head pointer
SNode* SLinkedList::getHead() const { return head; }

/*
INSERT(value)
1   newNode ← new SNode
2   newNode.value ← value
2   newNode.next ← head
3   head ← newNode
*/

//insert node with a single value
void SLinkedList::insert(const std::string& value) {
    SNode* newNode = new SNode(value);
    newNode -> next = head;
    head = newNode;
}

/*
SEARCH(value)
1   current ← head
2   while current ≠ NIL
3       do if current.value == value
4              return current
5          current ← current.next
6   return NIL
*/

//search for node by value
SNode* SLinkedList::search(const std::string& value) {
    SNode* current = head;
    while (current != nullptr) {
        if (current -> value == value) {
            return current;
        }
        current = current -> next;
    }
    return nullptr; //not found
}

/*
REMOVE(value)
1   current ← head
2   prev ← NIL
3   
4   while current ≠ NIL
5       do if current.value == value
6              if prev == NIL
7                       head ← current.next
8                   else
9                       prev.next ← current.next
10                  return
11          prev ← current
12          current ← current.next
*/

//remove node by value
void SLinkedList::remove(const std::string& value) {
    SNode* current = head;
    SNode* prev = nullptr;

    while (current != nullptr) {
        if (current -> value == value) {
            if (prev == nullptr) {
                head = current -> next;
            } else {
                prev -> next = current -> next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current -> next;
    }
}

//display linked list
void SLinkedList::display() {
    SNode* current = head;
    while (current != nullptr) {
        std::cout << current -> value;
        if (current -> next != nullptr) {
            std::cout << current -> value << " -> ";
        } 
        current = current -> next;
    }
    std::cout << std::endl;
}

/* LINKED LIST (KEY-VALUE PAIR) */

//initialize linked list
KVLinkedList::KVLinkedList() : head(nullptr), count(0) {}

/*
GET-HEAD()
1   return head
*/

//retrieve head pointer
KVNode* KVLinkedList::getHead() const { return head; }

/*
GET-COUNT()
1   return count
*/

//return number of nodes
int KVLinkedList::getCount() const { return count; }

/*
INSERT(key, value)
1   newNode ← new KVNode
2   newNode.key ← key
3   newNode.value ← value
4   newNode.next ← head
5   head ← newNode
6   count ← count + 1
*/

//insert node with a key-value pair
void KVLinkedList::insert(char key, double value) {
    KVNode* newNode = new KVNode(key, value);
    newNode -> next = head;
    head = newNode;
    count++;
}

/*
SEARCH(key)
1   current ← head
2   while current ≠ NIL
3       do if current.key == key
4              return current
5          current ← current.next
6   return NIL
*/

//linear search for node by key
KVNode* KVLinkedList::search(char key) {
    KVNode* current = head;
    while (current != nullptr) {
        if (current -> key == key) {
            return current;
        }
        current = current -> next;
    }
    return nullptr;
}

/*
REMOVE(key)
1   current ← head
2   prev ← NIL
3   
4   while current ≠ NIL
5       do if current.key == key
6              then if prev == NIL
7                       head ← current.next
8                   else
9                       prev.next ← current.next
10                  count ← count - 1
11                  return
12          prev ← current
13          current ← current.next
*/

//remove node by key
void KVLinkedList::remove(char key) {
    KVNode* current = head;
    KVNode* prev = nullptr;
    while (current != nullptr) {
        if (current -> key == key) {
            if (prev == nullptr) {
                head = current -> next;
            } else {
                prev -> next = current -> next;
            }
            delete current;
            count--;
            return;
        }
        prev = current;
        current = current -> next;
    }
}

//display linked list
void KVLinkedList::display() {
    KVNode* current = head;
    while (current != nullptr) {
        std::cout << "(" << current -> key << "," << current -> value << ") -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}
