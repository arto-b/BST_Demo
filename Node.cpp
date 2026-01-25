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
 * Retrieves the node's stored integer value.
 */
int Node::getValue() const {
	return value;
}

/**
 * Assigns a new integer value to the node.
 */
void Node::setValue(int v) { 
	value = v;
}

/**
 * Fetches the left child pointer; returns nullptr if there is no left child.
 */
Node* Node::getLeft() const {
	return left;
}

/**
 * Assigns the left child pointer.
 */
void Node::setLeft(Node* l) {
	left = l;
}
/**
 * Fetches the right child pointer; returns nullptr if there is no right child.
 */
Node* Node::getRight() const {
	return right;
}

/**
 * Assigns the right child pointer.
 */
void Node::setRight(Node* r) {
	right = r;
}
