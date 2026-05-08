#include "BST.hpp"

void BST::inorder_tree_walk(Node* node) {
    if (node) {
        inorder_tree_walk(node->left);
        std::cout << node->key << " ";
        inorder_tree_walk(node->right);
    }
}

void BST::walk() {
    inorder_tree_walk(root);
}

BST::Node* BST::tree_search(Node* node, int k) {
    if (!node || k == node->key) {
        return node;
    }
    if (k < node->key) {
        return tree_search(node->left, k);
    } else {
        return tree_search(node->right, k);
    }
}

BST::Node* BST::iterative_tree_search(Node* node, int k) {
    while (node && k != node->key) {
        if (k < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return node; 
}

BST::Node* BST::tree_minimum(Node* node) {
    while (node->left) {
        node = node->left;
    }
    return node;
}

BST::Node* BST::tree_maximum(Node* node) {
    while (node->right) {
        node = node->right;
    }
    return node;
}

BST::Node* BST::tree_successor(Node* node) {
    if (!node) { return node; }

    if (node->right) {
        return tree_minimum(node->right);
    }

    Node* curr = root;
    Node *pred = nullptr;    

    while (curr) {
        if (node->key < curr->key) {
            pred = curr;
            curr = curr->left;
        }
        else if (node->key > curr->key) {
            curr = curr->right;
        }
        else {
            break;
        }
    }

    return pred;
}

BST::Node* BST::tree_predecessor(Node* node) {
    if (!node) { return node; }

    if (node->left) {
        return tree_maximum(node->left);
    }
    
    Node* curr = root;
    Node *pred = nullptr;

    while (curr) {                              
        if (node->key < curr->key) {
            curr = curr->left;
        }
        else if (node->key > curr->key) {
            pred = curr;
            curr = curr->right;
        }
        else {
            break;
        }
    }

    return pred;
}

void BST::tree_insert(int k) {
    Node* curr = root;
    Node* pred = nullptr;

    while (curr) {
        pred = curr;
        if (k < curr->key) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    if (pred == nullptr) {
        root = new Node(k);
    }
    else if (k < pred->key) {
        pred->left = new Node(k);
    }
    else {
        pred->right = new Node(k);
    }
}

BST::Node* BST::tree_delete(Node* node, int k) {
    if (!node) { return nullptr; }

    if (k < node->key) {
        node->left = tree_delete(node->left, k);
    }
    else if(k > node->key) {
        node->right = tree_delete(node->right, k);
    }
    else {
        if (!node->left) {
            Node* tmp = node->right;
            delete node;
            return tmp;
        }
        else if (!node->right) {
            Node* tmp = node->left;
            delete node;
            return tmp;
        }
        
        Node* replace = tree_minimum(node->right);
        node->key = replace->key;
        node->right = tree_delete(node->right, replace->key);
    }

    return node;
}

void BST::tree_delete(int k) {
    root = tree_delete(root, k);
}