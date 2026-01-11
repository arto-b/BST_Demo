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
 * Adds a node to the end of the queue.
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
 * Removes a node from the front of the queue and returns the stored tree node pointer.
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
 * Checks whether the queue is empty.
 */
bool Queue::isEmpty() const {
    return front == nullptr;
}
