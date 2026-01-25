/**
 * @file BST.h
 * @brief Declaration of the BST (Binary Search Tree) class.
 *
 * @details
 * This header file declares the BST class, an iterative, pointer-based binary
 * search tree implementation. It includes public method prototypes for
 * insertion, deletion, searching, and tree traversal. Full implementation
 * details are provided in BST.cpp.
 *
 * @author Arto Baltayan
 * @date January 2026
 * @version 1.0
 */

#pragma once

#ifndef BST_H
#define BST_H

#include "Node.h"

/**
 * @class BST
 * @brief Iterative binary search tree storing integer values.
 *
 * @details
 * The BST class is an iterative, pointer-based binary
 * search tree implementation using raw pointers and manual dynamic memory
 * management. The BST owns all allocated nodes and is responsible for their
 * cleanup through its destructor.
 * 
 * The BST class manages dynamically allocated Node objects, forming a binary
 * search tree structure. All operations, including insert, search, delete, and traversal,
 * are implemented iteratively to avoid recursion.
 *
 * The tree maintains standard BST ordering properties:
 * - Left subtree contains values less than the node.
 * - Right subtree contains values greater than the node.
 * - Duplicate values are ignored.
 *
 * Memory Management:
 * The BST owns all its nodes. The destructor invokes a private destroyTree()
 * helper method, ensuring that all nodes are properly freed and preventing
 * memory leaks.
 * 
 * @see Node
 */

class BST {
public:
    /**
     * @brief Constructs an empty BST.
     */
    BST();

    /**
     * @brief Destroys the BST and frees all dynamically allocated nodes.
     */
    ~BST();

    /**
     * @brief Inserts a value into the BST.
     * @param value The integer value to insert.
     * @note Duplicate values are ignored.
     */
    void insert(int value);

    /**
     * @brief Searches for a value in the BST.
     * @param value The value to search for.
     * @return true if the value exists in the tree; otherwise false.
     */
    bool search(int value) const;

    /**
     * @brief Performs an inorder traversal of the tree.
     * @details
     * Prints node values in ascending order using an iterative traversal.
     */
    void inorder() const;

    /**
     * @brief Performs a level-order (breadth-first) traversal of the tree.
     */
    void levelOrder() const;

    /**
     * @brief Removes a value from the BST if it exists.
     * @param value The value to remove.
     * @return true if the value was found and removed; otherwise false.
     */
    bool remove(int value);

private:
    Node* root;

    /**
     * @brief Releases all nodes in the tree.
     * @note Called internally by the destructor.
     */
    void destroyTree();
};

#endif // BST_H
