#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include "Node.h"
using namespace std;


class BST{
    private:
        Node* root;
    public:
        BST(Node* treeRoot): root(treeRoot) {}
        BST() : root(nullptr) {}
        Node* insert(string& key, int& index);
        bool remove(string key);
        Node* getRoot();
        Node* find(string key);
        Node* findMin(Node* node);
        bool remove(Node*& node, string key);
        
};

Node* BST::insert(string& key, int& index){
    if(root == nullptr){
        root = new Node(key);
        root -> arrayIndex = index;
        //cout << root -> key << endl;
        return root;
    }
    
    Node* currNode = root;
    while(1){
        if(key > currNode->key){
            
            if(currNode -> right == nullptr){
                currNode -> right = new Node(key);
                currNode -> right -> arrayIndex = index;
                return currNode->right;
            }
            else currNode = currNode -> right;
        }
        if(key < currNode->key){
            
            if(currNode -> left == nullptr){
                currNode -> left = new Node(key);
                currNode ->left -> arrayIndex = index;
                return currNode->left;
            }
            else currNode = currNode -> left;
        }
    }
}
bool BST::remove(Node*& node, string key) {
    if (node == nullptr) {
        return false; // Key not found
    }

    if (key < node->key) {
        return remove(node->left, key); // Key is in the left subtree
    } else if (key > node->key) {
        return remove(node->right, key); // Key is in the right subtree
    } else {
        // Node with key found
        if (node->left == nullptr && node->right == nullptr) {
            // Node is a leaf
            delete node;
            node = nullptr;
        } else if (node->left != nullptr && node->right != nullptr) {
            // Node has two children
            Node* successor = findMin(node->right);
            node->key = successor->key;
            node->arrayIndex = successor->arrayIndex; // If you're keeping arrayIndex in nodes
            return remove(node->right, successor->key); // Remove the successor
        } else {
            // Node has one child
            Node* child = (node->left != nullptr) ? node->left : node->right;
            Node* oldNode = node;
            node = child;
            delete oldNode;
        }
        return true;
    }
} 

Node* BST::findMin(Node* node) {
    if(node == nullptr){
        return nullptr;
    }
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

// Public interface to remove function
bool BST::remove(string key) {
    return remove(root, key);
}


Node* BST::getRoot(){
    return root;
}

Node* BST::find(string key){
    Node* currNode = root;
    while(currNode != nullptr){
        if(key > currNode->key){
                currNode = currNode -> right;
        }
        else if(key < currNode->key){
            currNode = currNode -> left;
        }
        else if(key == currNode->key){ //found
            return currNode;
        }
    }
    return nullptr; //did not find
}
#endif