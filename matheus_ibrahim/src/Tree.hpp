#ifndef TREE_H
#define TREE_H

#include <fstream>
#include "string.h"

using std::string;
using std::ifstream;

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
public:
    Tree();
    Node* insertNode(char,  struct Node*);
    void printTree();
    void createTree(string);
    void decodeTree();
    
};


#endif