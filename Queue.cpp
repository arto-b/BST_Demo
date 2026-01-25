/**
 * @file Queue.cpp
 * @brief Implementation of the Queue class.
 * 
 * @details
 * This file contains the implementation of the Queue class member functions,
 * which are used to support non-recursive, level-order traversal operations
 * within a binary search tree.
 * 
 * The implementation is intentionally pointer-based and avoids the use of
 * STL containers or smart pointers to demonstrate fundamental memory management
 * concepts in C++. 
 */

#include "Queue.h"
#include <iostream>

/**
 * Destroys the queue by removing all remaining nodes.
 */
Queue::~Queue() {
    // Remove all nodes from front to rear.
    while (!isEmpty()) {
        dequeue();
    }
}

/**
 * Appends a node to the queue.
 */
void Queue::enqueue(Node* n) {
    QueueNode* q = new QueueNode(n);
    if (!rear) {
        front = rear = q;
    }
    else {
        rear->next = q;
        rear = q;
    }
}

/**
 * Dequeues the front element and returns the associated tree node pointer.
 */
Node* Queue::dequeue() {
    if (!front) return nullptr;
    QueueNode* temp = front;
    Node* result = temp->data;
    front = front->next;
    if (!front) rear = nullptr;
    delete temp;
    return result;
}

/**
 * Determines whether the queue has any elements.
 */
bool Queue::isEmpty() const {
    return front == nullptr;
}
