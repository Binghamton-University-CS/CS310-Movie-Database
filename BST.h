#include <iostream>
#include <string>
using namespace std;

struct Node{
    string key; //key is last name33
    Node *left, *right;
    int arrayIndex;

    Node(string k): key(k), left(nullptr), right(nullptr), arrayIndex(-1){}

};

class BST{
    private:
        Node *root;
    public:
        BST(Node* treeRoot): root(treeRoot) {}
        BST() : root(nullptr) {}
        void insert(string key);
        bool remove(string key);
        Node* getRoot();
        Node* find(string key);

        //extra, probably wont need:
        void inOrderTraversal();
        void preOrderTraversal();
        void postOrderTraversal();
};

void BST::insert(string key){
    
    currNode* = root;
    while(1){
        if(key > currNode.key){
            if(currNode -> right == nullptr){
                currNode -> right = new Node(key);
                break;
            }
            else currNode = currNode -> right;
        }
        if(key < currNode.key){
            if(currNode -> left == nullptr){
                currNode -> left = new Node(key);
                break;
            }
            else currNode = currNode -> left;
        }
    }
}
bool BST::remove(string key){  
    currNode* = root;
    while(currNode -> left.key != key && currNode -> right.key != key){
        if(key > currNode.key){
            if(currNode -> right == nullptr){
                return false; //node DNE
            }
            currNode = currNode -> right;
        }
        if(key < currNode.key){
            if(currNode -> left == nullptr){
                return false; //node DNE
            }
            currNode = currNode -> left;
        }
    }
    if(currNode -> left.key == key){
        //case 0: node to be removed is has no children
        if(!currNode -> left && !currNode -> right){
            currNode -> left == nullptr;
        } 
        //case 1: node to be removed has 1 child.
        if(currNode -> left -> left != nullptr && currNode -> left -> right == nullptr){
            //just left child exists
            currNode -> left = currNode -> left -> left;
        }
        else if(currNode -> left -> left == nullptr && currNode -> left -> right != nullptr){
            //just right child exists
            currNode -> left = currNode -> left -> right;
        }
        //case 2: left has 2 children
        if(currNode -> left -> left != nullptr && currNode -> left -> right != nullptr){
            Node* successor = currNode -> left;
            while(successor -> right){
                successor = successor -> right;
            }
            successor -> left = currNode -> left -> left;
            successor -> right = currNode -> left -> right;
            currNode -> left = successor;
        }
    }
    if(currNode -> right.key == key){
        //Copy everything from above into here, but change currNode-> left to right
    }
}

Node* BST::getRoot(){
    return root;
}

Node* BST::find(string key){
    currNode* = root;
    while(currNode != nullptr){
        if(key > currNode.key){
                currNode = currNode -> right;
        }
        else if(key < currNode.key){
            currNode = currNode -> left;
        }
        else if(key == currNode.key){ //found
            return currNode;
        }
    }
    return nullptr; //did not find
}

// Node* BST::insert(string key){
//     currNode* = root;
//     if()
//     if(key > currNode.key){
//         currNode = currNode -> right;
//     }
//     else if(key < currNode -> left){
//         currNode = currNode -> left;
//     }
    
// }