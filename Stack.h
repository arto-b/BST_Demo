/**
 * @file Stack.h
 * @brief Declaration of the Stack class.
 *
 * @details
 * This header declares the Stack class, which is used as an explicit stack
 * to support non-recursive operations within the binary search tree.
 * Specifically, it is utilized by the destroyTree() method invoked by the
 * BST destructor, as well as by the inorder() traversal method.
 * 
 * Its purpose is to assist in tree traversal and deletion operations while ensuring
 * that all dynamically allocated memory is properly released.
 *
 * Implementation details are defined in Stack.cpp.
 *
 * @author Arto Baltayan
 * @date January 2026
 * @version 1.0
 */

#pragma once

#ifndef STACK_H
#define STACK_H

#include "Node.h"

/**
 * @class Stack
 * @brief Represents an explicit stack used to support non-recursive tree operations.
 * 
 * @details
 * The Stack class implements a simple stack structure composed of node pointers.
 * It is used to support traversal and deletion operations within a binary search
 * tree, including non-recursive in-order traversal and tree destruction.
 * 
 * The Stack does not assume ownership of the tree nodes it stores; it manages
 * only the stack nodes required to support these operations.
 *
 * Supported operations include:
 * - push(): Adds a node pointer to the top of the stack.
 * - pop(): Removes and returns the top node pointer.
 * - isEmpty(): Checks whether the stack is empty.
 */

struct StackNode {
    Node* data;
    StackNode* next;

    /**
     * @brief Constructs a StackNode with the specified node pointer.
     * @param data Pointer to the Node stored in this stack element.
     */
    StackNode(Node* data) : data(data), next(nullptr) {}
};

class Stack {
public:
    /**
     * @brief Constructs an empty Stack.
     * @note Initializes the stack with its top pointer set to nullptr.
     */
    Stack() : top(nullptr) {}

    /**
     * @brief Destroys the Stack.
     */
    ~Stack();

    /**
     * @brief Pushes a node onto the stack.
     * @param n Pointer to the Node being added to the top of the stack.
     */
    void push(Node* n);

    /**
     * @brief Removes and returns the node at the top of the stack.
     * @return Pointer to the node removed from the stack.
     */
    Node* pop();

    /**
     * @brief Checks whether the stack is empty.
     * @return True if the stack contains no elements.
     */
    bool isEmpty() const;

private:
    StackNode* top;
};

#endif // STACK_H
