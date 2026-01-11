/**
 * @file Node.h
 * @brief Declaration of the Node class.
 *
 * @details
 * This header declares the Node class used to represent individual nodes
 * within a binary search tree (BST). The Node class encapsulates a single
 * integer data value along with pointers to its left and right child nodes.
 *
 * Implementation details are defined in Node.cpp.
 *
 * @author Arto Baltayan
 * @date January 2026
 * @version 1.0
 */

#pragma once

#ifndef NODE_H
#define NODE_H

/**
 * @class Node
 * @brief Represents a node within a binary search tree.
 *
 * @details
 * The Node class represents the fundamental unit of an iterative, pointer-based
 * binary search tree. Each node maintains self-referential raw pointers to its
 * left and right child nodes and stores a single integer data value.
 *
 * Encapsulation is enforced through data hiding. All data members are declared
 * as private and may only be accessed or modified through public accessor methods.
 */

class Node {
public:
    /**
     * @brief Constructs a Node with the specified integer value.
     * @param value The integer value stored in the node.
     */
    Node(int value);

    /**
     * @brief Returns the stored integer value.
     */
    int getValue() const;

    /**
     * @brief Sets the stored integer value.
     * @param value The new integer value to store.
     */
    void setValue(int value);

    /**
     * @brief Returns a pointer to the left child node.
     * @return Pointer to the left child, or nullptr if none exists.
     */
    Node* getLeft() const;

    /**
     * @brief Sets the pointer to the left child node.
     * @param left Pointer to the node to be assigned as the left child.
     * @note Ownership of the node is not transferred.
     */
    void setLeft(Node* left);

    /**
     * @brief Returns a pointer to the right child node.
     * @return Pointer to the right child, or nullptr if none exists.
     */
    Node* getRight() const;

    /**
     * @brief Sets the pointer to the right child node.
     * @param right Pointer to the node to be assigned as the right child.
     * @note Ownership of the node is not transferred.
     */
    void setRight(Node* right);

private:
    int value;
    Node* left;
    Node* right;
};

#endif // NODE_H
