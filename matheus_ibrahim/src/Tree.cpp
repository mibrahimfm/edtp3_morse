#include "Tree.hpp"

Tree::Tree(){
    this->root = new Node();
    this->root->key = ' ';
    this->root->code = ' ';
    this->root->left = nullptr;
    this->root->right = nullptr;
}

struct Node* Tree::newNode(){
    struct Node* helper = new Node;  
    helper->left =  helper->right = nullptr; 
    return helper; 
}

void Tree::createTree(string file){
    char input, letter;
    ifstream operateMorseCode;
    string letterCode;
    struct Node* pos = root;
    operateMorseCode.open(file);

    while (!operateMorseCode.eof()){
        operateMorseCode >> input;
        if(input == '/'){
            pos->key = letter;
            pos->code = letterCode;
            letterCode = '"';
            letter = input;
            pos = this->root;
        }
        else{
            pos = insertNode(input, pos);
            letterCode += input;
        }

    }
    
    pos->key = letter;
    pos->code = letterCode;

}

Node* Tree::insertNode(char nodeCode, struct Node* node){
    if(nodeCode == '.'){
        if(node->right == nullptr)
            node->right = newNode();
        return node->right;
    }
    else if(nodeCode == '-'){
        if(node->left == nullptr)
            node->left = newNode();
        return node->left;
    }
    return nullptr;
}