# Binary Search Tree (C++)

An iterative, pointer-based Binary Search Tree (BST) implementation written in C++.  
This project avoids recursion and STL containers by using custom Stack and Queue
structures to support traversal and deletion operations.

**Note:** This is an original portfolio project, designed and implemented by the author.

## Key Features

- Iterative BST operations (no recursion)
- Pointer-based implementation using `new` / `delete` (raw pointers)
- Custom supporting data structures:
  - Stack (used for traversal and tree destruction)
  - Queue (used for level-order traversal)
- Fully documented with Doxygen (API reference generated from source comments)

## Documentation

- **API Reference (Doxygen):** *[Binary Search Tree (C++): Main Page](https://arto-b.github.io/BST_Demo/)*

**Tip:** Start with **Classes → Class List → `BST`** for the main API. Use the built-in **Search** bar to quickly find member functions.

## Build and Run

This project was developed and tested using Microsoft Visual Studio.

1. Open the solution in Visual Studio.
2. Build the solution.
3. Run the program (BinarySearchTree.cpp) to view the BST demonstration output.

## Project Structure

- `BinarySearchTree.cpp` — Demo / entry point
- `BST.h / BST.cpp` — Binary Search Tree implementation
- `Node.h / Node.cpp` — Tree node implementation
- `Stack.h / Stack.cpp` — Explicit stack used for iterative traversal / destruction
- `Queue.h / Queue.cpp` — Explicit queue used for level-order traversal
- `Doxyfile` — Doxygen configuration file
- `docs/` — Generated Doxygen HTML documentation output

## Notes

- The Stack and Queue store pointers to tree nodes and **do not assume ownership**
  of the BST nodes themselves.
- Tree deletion is performed iteratively to ensure all dynamically allocated memory
  is released without relying on recursion.

## Author

Arto Baltayan
