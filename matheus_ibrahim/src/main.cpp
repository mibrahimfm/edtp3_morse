#include <iostream>
#include "Tree.hpp"
#include <string>

using std::string;
using std::getline;
using std::cin;

int main(int argc, char** argv){
    
    string optional;
    if(argc > 1)
	optional = string(argv[1]) == "-a" ? argv[1] : nullptr;
    Tree *morse = new Tree();

    morse->createTree("morse.txt");

    morse->translate();

    if(optional == "-a"){
        morse->preOrder(morse->getRoot());
    }

}