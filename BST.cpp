/**
 * @file BST.cpp
 * @brief Implementation of the BST (Binary Search Tree) class.
 *
 * @details
 * This file contains the iterative implementation of all BST operations,
 * including insertion, search, deletion, traversal, and cleanup.
 *
 * All algorithms are implemented without recursion, using explicit stack
 * and queue data structures where appropriate. The BST owns all dynamically
 * allocated Node objects and is responsible for their lifetime management.
 *
 * This implementation is intentionally pointer-based and avoids the use of
 * STL containers or smart pointers to demonstrate fundamental memory
 * management concepts in C++.
 */

#include "BST.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>

/**
 * Constructs an empty BST.
 */
BST::BST() : root(nullptr) {}

/**
 * Destroys the BST and releases all dynamically allocated nodes.
 */
BST::~BST() {
    destroyTree();
}

/**
 * Iteratively inserts a value into the BST.
 *
 * The tree is traversed from the root to locate the appropriate insertion
 * point. Duplicate values are detected and ignored to preserve BST invariants.
 */
void BST::insert(int value) {
    Node* newNode = new Node(value);

    // Special case: empty tree
    if (!root) {
        root = newNode;
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    // Traverse the tree to find the insertion point
    while (current) {
        parent = current;

        if (value < current->getValue())
            current = current->getLeft();
        else if (value > current->getValue())
            current = current->getRight();
        else {
            // Duplicate value detected; discard new node
            delete newNode;
            return;
        }
    }

    // Attach the new node to its parent
    if (value < parent->getValue())
        parent->setLeft(newNode);
    else
        parent->setRight(newNode);
}

/**
 * Iteratively searches for a value in the BST.
 *
 * Traverses the tree according to BST ordering rules until the value
 * is found or a null pointer is reached.
 */
bool BST::search(int value) const {
    Node* current = root;

    while (current) {
        if (value == current->getValue())
            return true;
        else if (value < current->getValue())
            current = current->getLeft();
        else
            current = current->getRight();
    }

    return false;
}

/**
 * Performs an iterative inorder traversal.
 *
 * Uses an explicit stack to traverse the tree without recursion and
 * prints values in ascending order.
 */
void BST::inorder() const {
    if (!root) return;

    Stack s;
    Node* current = root;

    while (current || !s.isEmpty()) {
        while (current) {
            s.push(current);
            current = current->getLeft();
        }

        current = s.pop();
        std::cout << current->getValue() << " ";
        current = current->getRight();
    }

    std::cout << std::endl;
}

/**
 * Performs a level-order (breadth-first) traversal.
 *
 * Uses a queue to visit nodes level by level starting from the root.
 */
void BST::levelOrder() const {
    if (!root) return;

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty()) {
        Node* current = q.dequeue();
        std::cout << current->getValue() << " ";

        if (current->getLeft())
            q.enqueue(current->getLeft());
        if (current->getRight())
            q.enqueue(current->getRight());
    }

    std::cout << std::endl;
}

/**
 * Removes a value from the BST if it exists.
 *
 * Handles all three standard BST deletion cases:
 * 1. Node is a leaf
 * 2. Node has one child
 * 3. Node has two children (using inorder successor replacement)
 */
bool BST::remove(int value) {
    Node* parent = nullptr;
    Node* current = root;

    // Locate the node to delete
    while (current && current->getValue() != value) {
        parent = current;
        if (value < current->getValue())
            current = current->getLeft();
        else
            current = current->getRight();
    }

    if (!current)
        return false; // Value not found

    // ------------------------------------------------------------
    // Case 1: Node has no children (leaf)
    // ------------------------------------------------------------
    if (!current->getLeft() && !current->getRight()) {
        if (current == root)
            root = nullptr;
        else if (parent->getLeft() == current)
            parent->setLeft(nullptr);
        else
            parent->setRight(nullptr);

        delete current;
    }

    // ------------------------------------------------------------
    // Case 2: Node has exactly one child
    // ------------------------------------------------------------
    else if (!current->getLeft() || !current->getRight()) {
        Node* child = current->getLeft()
            ? current->getLeft()
            : current->getRight();

        if (current == root)
            root = child;
        else if (parent->getLeft() == current)
            parent->setLeft(child);
        else
            parent->setRight(child);

        delete current;
    }

    // ------------------------------------------------------------
    // Case 3: Node has two children
    // ------------------------------------------------------------
    else {
        // Find inorder successor (leftmost node in right subtree)
        Node* succParent = current;
        Node* successor = current->getRight();

        while (successor->getLeft()) {
            succParent = successor;
            successor = successor->getLeft();
        }

        // Replace current node's value with successor's value
        current->setValue(successor->getValue());

        // Remove successor node (which has at most one child)
        Node* child = successor->getRight();

        if (succParent->getLeft() == successor)
            succParent->setLeft(child);
        else
            succParent->setRight(child);

        delete successor;
    }

    return true;
}

/**
 * Iteratively deletes all nodes in the tree.
 *
 * Uses an explicit stack to traverse and delete each node,
 * ensuring all dynamically allocated memory is released.
 * This method is called internally by the destructor.
 */
void BST::destroyTree() {
    if (!root) return;

    Stack s;
    s.push(root);

    while (!s.isEmpty()) {
        Node* current = s.pop();

        if (current->getLeft())
            s.push(current->getLeft());
        if (current->getRight())
            s.push(current->getRight());

        delete current;
    }

    root = nullptr;
}
