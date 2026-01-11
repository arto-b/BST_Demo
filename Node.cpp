/**
 * @file Node.cpp
 * @brief Implementation of the Node class.
 *
 * @details
 * This file contains the implementation of the Node class member functions,
 * including accessor and mutator methods for managing node data and relationships.
 *
 * The implementation is intentionally pointer-based and avoids the use of
 * STL containers or smart pointers to demonstrate fundamental memory
 * management concepts in C++. 
 */

#include "Node.h"

/**
 * Constructs a node initialized with the specified value and
 * null child pointers.
 */
Node::Node(int v) : value(v), left(nullptr), right(nullptr) {}

/**
 * Returns the stored integer value.
 */
int Node::getValue() const {
	return value;
}

/**
 * Sets the stored integer value.
 */
void Node::setValue(int v) { 
	value = v;
}

/**
 * Returns a pointer to the left child, nullptr if none exists.
 */
Node* Node::getLeft() const {
	return left;
}

/**
 * Sets the pointer to the left child.
 */
void Node::setLeft(Node* l) {
	left = l;
}
/**
 * Returns a pointer to the right child, nullptr if none exists.
 */
Node* Node::getRight() const {
	return right;
}

/**
 * Sets the pointer to the right child.
 */
void Node::setRight(Node* r) {
	right = r;
}
