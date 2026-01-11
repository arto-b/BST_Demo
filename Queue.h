/**
 * @file Queue.h
 * @brief Declaration of the Queue class.
 * 
 * @details
 * This header declares the Queue class, which is used as an explicit queue
 * to support non-recursive operations within a binary search tree.
 * Specifically, it is utilized by the levelOrder() traversal method.
 * 
 * Its purpose is to assist in tree traversal by visiting the nodes
 * level-by-level, starting from the root.
 * 
 * Implementation details are defined in Queue.cpp.
 * 
 * @author Arto Baltayan
 * @date January 2026
 * @version 1.0
 */

#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

/**
 * @class Queue
 * @brief Represents an explicit queue used to support non-recursive tree operations.
 * 
 * @details
 * The Queue class implements a simple queue structure composed of node pointers.
 * It is used to support non-recursive, level-order traversal operations within
 * a binary search tree.
 * 
 * The Queue does not assume ownership of the tree nodes it stores; it manages
 * only the queue nodes required to support these operations.
 * 
 * Supported operations include:
 * - enqueue(): Adds a node pointer to the end of the queue.
 * - dequeue(): Removes and returns a node pointer from the front of the queue.
 * - isEmpty(): Checks whether the queue is empty.
 */

struct QueueNode {
    Node* data;
    QueueNode* next;

    /**
     * @brief Constructs a QueueNode with the specified node pointer.
     * @param data Pointer to the Node stored in this queue element.
     */
    QueueNode(Node* data) : data(data), next(nullptr) {}
};

class Queue {
public:
    /**
     * @brief Constructs an empty queue.
     * @note Initializes the queue with its front and rear pointers set to nullptr.
     */
    Queue() : front(nullptr), rear(nullptr) {}

    /**
     * @brief Destroys the Queue.
     */
    ~Queue();

    /**
     * @brief Adds a node to the end of the queue.
     * @param n Pointer to the Node added to the rear of the queue.
     */
    void enqueue(Node* n);

    /**
     * @brief Removes and returns the node at the front of the queue.
     * @return Pointer to the node removed from the queue.
     */
    Node* dequeue();

    /**
     * @brief Checks whether the queue is empty.
     * @return True if the queue contains no elements.
     */
    bool isEmpty() const;

private:
    QueueNode* front;
    QueueNode* rear;
};

#endif // QUEUE_H
