#include <iostream>
#include <string>

struct Node{
    string key; //key is last name33
    Node *left, *right;
    int arrayIndex;

    Node(string k): key(k), left(nullptr), right(nullptr){}

};

class BST{
    private:
        Node *root;
    public:
        BST(Node treeRoot): root(treeRoot) {}
        void insert(string key);
        bool remove(string key);
        bool getRoot();
        bool getNode(string key);

        //extra, probably wont need:
        void inOrderTraversal();
        void preOrderTraversal();
        void postOrderTraversal();
};

void BST::insert(string key){
    currNode* = root;
    if(key > currNode.key){
        currNode = currNode -> right;
    }
    else if(key < currNode -> left){
        currNode = currNode -> left;
    }
    
}