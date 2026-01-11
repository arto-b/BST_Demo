/**
 * @file Stack.cpp
 * @brief Implementation of the Stack class.
 *
 * @details
 * This file contains the implementation of the Stack class member functions,
 * which are used to support non-recursive traversal and deletion operations
 * within a binary search tree, including in-order traversal and tree destruction.
 *
 * The implementation is intentionally pointer-based and avoids the use of
 * STL containers or smart pointers to demonstrate fundamental memory management
 * concepts in C++. 
 */

#include "Stack.h"
#include <iostream>

/**
 * Destroys the stack by removing all remaining nodes.
 */
Stack::~Stack() {
    // Remove all nodes from top to bottom.
    while (!isEmpty()) {
        pop();
    }
}

/**
 * Pushes a new node onto the stack.
 */
void Stack::push(Node* n) {
    StackNode* s = new StackNode(n);
    s->next = top;
    top = s;
}

/**
 * Pops a node off the stack and returns the stored tree node pointer.
 */
Node* Stack::pop() {
    if (!top) return nullptr;
    StackNode* temp = top;
    Node* result = temp->data;
    top = top->next;
    delete temp;
    return result;
}

/**
 * Checks whether the stack is empty.
 */
bool Stack::isEmpty() const {
    return top == nullptr;
}
