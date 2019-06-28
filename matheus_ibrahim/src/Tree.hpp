#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::cout;
using std::cin;
using std::getline;

struct Node{
    struct Node* left;
    struct Node* right;
    char key;
    string code;
};

class Tree{
private:
    struct Node* root;
    struct Node* newNode();
    struct Node* findNode(char, struct Node*);
public:
    Tree();
    Node* insertNode(char,  struct Node*);
    void preOrder(struct Node*);
    void createTree(string);
    char decodeNode(string);
    struct Node* getRoot();
    void translate();
};


#endif