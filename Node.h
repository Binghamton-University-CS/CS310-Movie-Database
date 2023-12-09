#include<iostream>
#ifndef NODE_H
#define NODE_H
class Node{
    public:
    string key; //key is last name33
    Node *left, *right;
    int arrayIndex;
    Node(string k): key(k), left(nullptr), right(nullptr), arrayIndex(-1){}

};
#endif