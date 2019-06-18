#ifndef TREE_H
#define TREE_H

#include <string.h>

using std::string;

struct Node{
    struct Node* left;
    struct Node* right;
    char key;
    string code;
};

class Tree{
private:
    Node* root;
public:
    Tree();
};


#endif