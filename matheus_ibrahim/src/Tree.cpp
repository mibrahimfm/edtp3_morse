#include "Tree.hpp"

Tree::Tree(){
    this->root = newNode();
}

struct Node* Tree::getRoot() { return this->root;}

//Cria um nó vazio
struct Node* Tree::newNode(){
    struct Node* helper = new Node;  
    helper->left = nullptr; helper->right = nullptr;
    helper->key = ' ';  helper->code = " ";
    return helper; 
}

void Tree::createTree(string file){
    char input, code, symbol = ' ';
    ifstream operateMorseCode;
    string letterCode;
    struct Node* pos = root;

    operateMorseCode.open(file);

    //Realiza a operação enquanto não chegar ao final do arquivo
    while (!operateMorseCode.eof()){
        //Atribui valor lido no arquivo à variável input
        operateMorseCode >> input; 
        
        //Se entrada não for um símbolo do código morse
        //Atribui o símbolo como chave do nó atual, o código em morse como o código do nó e "reinicia" as variáveis
        if(input != '.' && input != '-'){
            pos->key = symbol;
            pos->code = letterCode;
            letterCode.clear();
            symbol = input;
            pos = this->root;
        }
        //Se entrada for um símbolo do código morse
        //Move na árvore para encontrar o valor recebido pelo arquivo e acrescenta o valor no código.
        else{
            pos = insertNode(input, pos);
            letterCode += input;
        }

    }

    pos->key = symbol;
    pos->code = letterCode;

    operateMorseCode.close();

}

Node* Tree::insertNode(char nodeCode, struct Node* node){
    //Realiza uma verificação se a árvore deve mover-se para a direita ou para a esquerda
    //Se necessário, cria um novo nó
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
    //Para cada valor da letra em morse, verifica se deve mover-se para a esquerda ou a direita na árvore
    for(int i = 0; i < letterCode.length(); i++){
        code = letterCode[i];
        //Se foi inserido um ponto, deve ir para a direita, e se foi inserido um traço, para a esquerda
        pos =  (code == '.' ? pos->right : pos->left);
    }
    //Retorna a letra encontrada para o código recebido
    return pos->key;
}

void Tree::translate(){
    string decoding, letterCode;
    char code;

    while (getline(cin, decoding)){
    //Para cada caracter digitado na mensagem em morse
    for(int i = 0; i < decoding.length(); i++){
        code = decoding[i];
        //Se for um símbolo em morse, adicionar ao código para encontrar a letra
        if(code == '.' || code == '-')
            letterCode += code;
        //Se for um espaço, o código da letra foi digitado, então encontrar a letra
        else if(code == ' '){
            if(!letterCode.empty()){
                cout << this->decodeNode(letterCode);
                letterCode = "";
            }
        //Se for uma barra, a palavra acabou, e deve ser impresso um espaço em branco
            else{
                cout << " ";
            }
        }
    }

    //A última letra da mensagem não possui um espaço ou barra indicando que seu código foi finalizado
    //Então é necessário repetir o bloco para garantir que a última letra seja impressa na tela
    if(!letterCode.empty()){
                cout << this->decodeNode(letterCode);
                letterCode = "";
            }
    cout << "\n";
    }
}

//Função para imprimir a árvore em pré-ordem
void Tree::preOrder(struct Node* coverTree){
    if(coverTree != nullptr){
            cout << coverTree->key <<  " " << coverTree->code << "\n";
            preOrder(coverTree->left);
            preOrder(coverTree->right);
        }
}
