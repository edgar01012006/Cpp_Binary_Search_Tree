#include <iostream>
#include <vector>
#include <string>
#include "BST.hpp"

// Helper function to simplify printing node information
void print_node(const std::string& label, BST::Node* node) {
    std::cout << label << ": ";
    if (node) {
        std::cout << node->getKey() << std::endl;
    } else {
        std::cout << "nullptr" << std::endl;
    }
}

int main() {
    BST tree;

    // 1. Testing Insertion
    // Creating a balanced-ish tree: 
    //        15
    //       /  \
    //      6    18
    //     / \   / \
    //    3   7 17  20
    std::cout << "--- 1. Insertion ---" << std::endl;
    std::vector<int> values = {15, 6, 18, 3, 7, 17, 20};
    for (int val : values) {
        tree.tree_insert(val);
    }
    std::cout << "Inserted: 15, 6, 18, 3, 7, 17, 20" << std::endl;

    // 2. Testing Walk
    // In-order traversal should result in: 3 6 7 15 17 18 20
    std::cout << "\n--- 2. Inorder Walk ---" << std::endl;
    std::cout << "Expected: 3 6 7 15 17 18 20" << std::endl;
    std::cout << "Actual:   ";
    tree.walk(); 
    std::cout << std::endl;

    // 3. Testing Search and Min/Max
    std::cout << "\n--- 3. Search & Extremes ---" << std::endl;
    BST::Node* root = tree.getRoot();
    
    print_node("Tree Minimum (Expected 3)", tree.tree_minimum(root));
    print_node("Tree Maximum (Expected 20)", tree.tree_maximum(root));

    BST::Node* found = tree.tree_search(root, 17);
    print_node("Searching for 17", found);

    // 4. Testing Successor & Predecessor
    std::cout << "\n--- 4. Successor & Predecessor ---" << std::endl;
    
    // Successor of 7 (no right child, goes up to 15)
    BST::Node* node7 = tree.tree_search(root, 7);
    print_node("Successor of 7 (Expected 15)", tree.tree_successor(node7));

    // Predecessor of 18 (left child 17, max of left is 17)
    BST::Node* node18 = tree.tree_search(root, 18);
    print_node("Predecessor of 18 (Expected 17)", tree.tree_predecessor(node18));

    // 5. Testing Deletion
    std::cout << "\n--- 5. Deletion ---" << std::endl;
    
    // Deleting leaf (3)
    // Tree becomes:
    //        15
    //       /  \
    //      6    18
    //       \   / \
    //        7 17  20
    std::cout << "Deleting leaf (3)..." << std::endl;
    tree.tree_delete(3);
    
    // Deleting root with two children (15)
    // Successor (17) should take its place.
    // Tree becomes:
    //        17
    //       /  \
    //      6    18
    //       \     \
    //        7     20
    std::cout << "Deleting root with two children (15)..." << std::endl;
    tree.tree_delete(15);

    // 6. Final Verification
    std::cout << "\n--- 6. Final Walk (After Deletion) ---" << std::endl;
    std::cout << "Expected: 6 7 17 18 20" << std::endl;
    std::cout << "Actual:   ";
    tree.walk();
    std::cout << std::endl;

    return 0;
}