#include "Tree.hpp"

Tree::Tree(){
    this->root = newNode();
}

struct Node* Tree::newNode(){
    struct Node* helper = new Node;  
    helper->left =  helper->right = nullptr;
    helper->key = ' ';
    helper->code = " ";
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

// struct Node* Tree::findNode(char code, struct Node* node){
//     if(code == '.')
//         return node->left;
//     else if(code == '-')
//         return node->left;
//     return nullptr;
// }

char Tree::decodeNode(string letterCode){
    char code;
    struct Node* pos = this->root;
    for(int i = 0; i < letterCode.length(); i++){
        code = letterCode[i];
        if(code == '.' || code == ',')
            pos = code == '.' ? pos->left : pos ->right;
        else
            pos = nullptr;
    }
    if(pos != nullptr)
      return pos->key;
    return ' ';  
}