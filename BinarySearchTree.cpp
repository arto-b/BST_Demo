/**
 * @file BinarySearchTree.cpp
 * @brief Entry point for the Binary Search Tree demonstration program.
 *
 * @details
 * This file contains the main entry point for a console-based application
 * that demonstrates the functionality of an iterative, pointer-based
 * Binary Search Tree (BST).
 * 
 * The BST implementation uses raw pointers and manual dynamic memory
 * management. All allocated nodes are properly destroyed, ensuring that no
 * memory leaks are introduced and demonstrating good fundamental coding
 * practices.
 * 
 * Users may insert, delete, search, and traverse integer values using a
 * simple text-based menu. The program serves both as an educational example
 * and as a usage demonstration for the BST API.
 * 
 * Although this project includes a complete and functioning BST, its primary
 * purpose is to showcase the author's documentation style and technique,
 * rather than to emphasize advanced coding features.
 *
 * @note This application uses system("CLS") to clear the console, which is
 * specific to Windows environments.
 *
 * @author Arto Baltayan
 * @date January 2026
 * @version 1.0
 *
 * @see BST
 * @see Node
 */



#include <iostream>
#include <limits>
#include "BST.h"

void clearScreen() {
    system("CLS");  // Windows console clear
}

void pauseForUser() {
    std::cout << "\nPress Enter to continue...";

    // Clear the input buffer.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cin.get();
}

int main() {
    BST tree;
    int choice = 0; // User's menu selection.

    while (true) {
        clearScreen();

        std::cout << "--- Binary Search Tree Menu ---\n";
        std::cout << "1. Insert a value\n";
        std::cout << "2. Delete a value\n";
        std::cout << "3. Search for a value\n";
        std::cout << "4. Inorder traversal\n";
        std::cout << "5. Level-order traversal\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (!std::cin) { // Handle non-numeric or otherwise invalid input.
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input.\n";
            pauseForUser();
            continue;
        }

        if (choice == 6) {
            clearScreen();
            std::cout << "Exiting program...\n";
            break;
        }

        int value;

        clearScreen();  // Clear before showing the operation output

        // Process the user's menu selection.
        switch (choice) {
        case 1:
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            tree.insert(value);                 // Insert the value, ignoring duplicates.
            std::cout << "Value inserted.\n";
            break;

        case 2:
            std::cout << "Enter value to delete: ";
            std::cin >> value;
            if (tree.remove(value))
                std::cout << "Value deleted.\n";
            else
                std::cout << "Value not found.\n";
            break;

        case 3:
            std::cout << "Enter value to search for: ";
            std::cin >> value;
            if (tree.search(value))
                std::cout << "Value found in the tree.\n";
            else
                std::cout << "Value NOT found.\n";
            break;

        case 4:
            std::cout << "Inorder traversal:\n";
            tree.inorder();
            break;

        case 5:
            std::cout << "Level-order traversal:\n";
            tree.levelOrder();
            break;

        default:
            std::cout << "Invalid choice.\n";
        }

        pauseForUser();
    }

    return 0;
}
