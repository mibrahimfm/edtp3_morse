#include <iostream>
#include <string>
#include "Tree.hpp"

using std::string;

int main(int argc, char** argv){

    //Atribuição do parâmetro opcional -a    
    string optional;
    if(argc > 1)
	optional = string(argv[1]) == "-a" ? argv[1] : nullptr;
    Tree *morse = new Tree();

    //Criando a árvore com base no arquivo morse.txt
    morse->createTree("morse.txt");
    
    //Traduz menagens de morse para o alfabeto romano
    morse->translate();

    //Verifica se deve imprimir a árvore em pré-ordem
    if(optional == "-a"){
        morse->preOrder(morse->getRoot());
    }

}