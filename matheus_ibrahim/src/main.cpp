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
    string decoding, letterCode;
    char code;

    morse->createTree("morse.txt");

    while (getline(cin, decoding)){
        for(int i = 0; i < decoding.length(); i++){
            code = decoding[i];
            if(code == '.' || code == '-')
                letterCode += code;
            else if(code == ' '){
                if(!letterCode.empty()){
                    cout << morse->decodeNode(letterCode);
                    letterCode = "";
                }
                else{
                    cout << " ";
                }
            }
        }
        if(!letterCode.empty()){
                    cout << morse->decodeNode(letterCode);
                    letterCode = "";
                }
        cout << "\n";
    }
    
    if(optional == "-a"){
        morse->preOrder(morse->getRoot());
    }

}