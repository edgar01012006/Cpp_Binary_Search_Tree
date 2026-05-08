#ifndef BST_HPP
#define BST_HPP

#include <iostream>

class BST {
    public:
        struct Node {
            friend class BST;

            private:
                int key;
                Node* left;
                Node* right;

            public:
                Node(int key = {}, Node* left = {}, Node* right = {}) 
                    : key { key }, left { left }, right { right } {} 

                int getKey() const { return key; }
        };

    private:
        Node* root;

    public:
        BST() : root{} {}

        void inorder_tree_walk(Node* node);
        void walk();

        Node* tree_search(Node* node, int k);
        Node* iterative_tree_search(Node* node, int k);

        Node* tree_minimum(Node* node);
        Node* tree_maximum(Node* node);

        Node* tree_successor(Node* node);
        Node* tree_predecessor(Node* node);

        void tree_insert(int k);
        void tree_delete(int k);

        Node* getRoot() const { return root; }

    private:
        Node* tree_delete(Node* node, int k);
};

#endif