#include "Tree.hpp"

Tree::Tree(){
    this->root = newNode();
}

struct Node* Tree::newNode(){
    struct Node* helper = new Node;  
    helper->left = nullptr; helper->right = nullptr;
    helper->key = ' ';  helper->code = " ";
    return helper; 
}

void Tree::createTree(string file){
    char input, code, letter = ' ';
    ifstream operateMorseCode;
    string letterCode;
    struct Node* pos = root;

    operateMorseCode.open(file);

    while (!operateMorseCode.eof()){
        operateMorseCode >> input;
        
        if(input != '.' && input != '-'){
            pos->key = letter;
            pos->code = letterCode;
            letterCode.clear();
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

    operateMorseCode.close();

}

Node* Tree::insertNode(char nodeCode, struct Node* node){
    if(nodeCode == '.'){
        if(node->right != nullptr)
            return node->right;
        else{
            node->right = newNode();
            return node->right;
        }
            
    }
    else if(nodeCode == '-'){
        if(node->left != nullptr)
            return node->left;
        else{
            node->left = newNode();
            return node->left;
        }
    }
    return nullptr;
}

char Tree::decodeNode(string letterCode){
    char code;
    struct Node* pos = this->root;
    for(int i = 0; i < letterCode.length(); i++){
        code = letterCode[i];
        pos =  (code == '.' ? pos->right : pos->left);
    }
    return pos->key;
}

struct Node* Tree::getRoot() { return this->root;}

void Tree::preOrder(struct Node* coverTree){
    if(coverTree != nullptr){
            cout << coverTree->key <<  " " << coverTree->code << "\n";
            preOrder(coverTree->left);
            preOrder(coverTree->right);
        }

}

void Tree::translate(){
    string decoding, letterCode;
    char code;

    while (getline(cin, decoding)){
    for(int i = 0; i < decoding.length(); i++){
        code = decoding[i];
        if(code == '.' || code == '-')
            letterCode += code;
        else if(code == ' '){
            if(!letterCode.empty()){
                cout << this->decodeNode(letterCode);
                letterCode = "";
            }
            else{
                cout << " ";
            }
        }
    }
    if(!letterCode.empty()){
                cout << this->decodeNode(letterCode);
                letterCode = "";
            }
    cout << "\n";
    }
}