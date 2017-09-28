#include "Node.h"
#include <iostream>
using namespace std;

class BST{
private:
    int length;
    Node* root;
public:
    BST(){
        root = NULL;
    }

    int insert(int key){
        if(root == NULL){
            this->root = new Node(key);
        }
        else{
            Node* current = root;
            while(current != NULL){
                if(key < current->getX()){
                    //Vai para a esquerda
                    if(current->getLeft() == NULL){
                        Node* inserted = new Node(key);
                        inserted->setParent(current);
                        current->setLeft(inserted);
                        return 1;
                    }else{
                        current = current->getLeft();
                    }
                }else if(key > current->getX()){
                    //Vai para a direita
                    if(current->getRight() == NULL){
                        Node* inserted = new Node(key);
                        inserted->setParent(current);
                        current->setRight(inserted);
                        return 1;
                    }else{
                        current = current->getRight();
                    }
                }else{
                    cout << "insert:\tno duplicated vertex allowed." << endl;
                    return 0;
                }
            }
        }
        return 0;          
    }

    Node* remove(int key){
        remove(key, root);
    }

    Node* remove(int key, Node* current){
        if(current == NULL) return current;

        //Se a chave for menor que o valor no nodo atual, roda a função na sub-àrvore à esquerda
        if(key < current->getX()){
            current->setLeft(remove(key, current->getLeft()));
        }
        //Se a chave for menor que o valor no nodo atual, roda a função na sub-àrvore à direita
        else if(key > current->getX()){
            current->setRight(remove(key, current->getRight()));
        }
        //Se a chave for igual ao valor no nodo atual, deleta o nodo atual
        else{
            //Se o nodo só tem um filho, à direita
            if(!current->hasLeft()){
                Node* dellPtr = current->getRight();
                delete dellPtr;
                current->setRight(NULL); //seta o nodo deletado como nulo em seu nodo pai para prevenir segmentarion fault
                dellPtr = NULL;            
                return current;
            }
            //Se o nodo só tem um filho, à esquerda
            else if(!current->hasRight()){
                Node* dellPtr = current->getLeft();
                delete dellPtr;
                current->setLeft(NULL); //seta o nodo deletado como nulo em seu nodo pai para prevenir segmentarion fault
                dellPtr = NULL;
                return current;
            }
            //Se o nodo tem dois filhos
            /*
                else if(current->hasRight() && current->hasLeft())

                nesse caso o if não é nescessário porque as condições anteriores possuem uma instução de retorno
                o código a partir daqui só será executado se nenhuma das condicionais anteriores forem satisfeitas
            */
            //Encontra o menor valor na sub-árvore à direta do nodo
            Node* sucessor = min_value(current->getRight());
            
            //Se o valor a ser deletado não for o nó raiz, faz o nó pai dele apontar para o sucessor
            if(current->hasParent()){
                if(current->getParent()->getX() > sucessor->getX()){
                    current->getParent()->setLeft(sucessor);
                }else{
                    current->getParent()->setRight(sucessor);
                }
            }else{
                root = sucessor;
            }
                        
            sucessor->setLeft(current->getLeft());
            sucessor->setRight(current->getRight());
            
            //Aponta o nó pai do sucessor para nulo conforme a precedência            
            if(sucessor->getParent()->getX() > sucessor->getX()){
                sucessor->getParent()->setLeft(NULL);
            }
            else{
                sucessor->getParent()->setRight(NULL);
            }
        }
        return current;
    }
    Node* min_value(){
        min_value(this->root);
    }

    Node* min_value(Node* current){
        if(current->hasLeft()){
            min_value(current->getLeft());
        }else{
            return current;
        }
    }
    void prefix_left(){
        prefix_left(this->root);}
    void prefix_left(Node* current){
        if(current != NULL){
            cout << current->getX() <<endl;
            prefix_left(current->getLeft());
            prefix_left(current->getRight());
        }
    }

    void prefix_right(){
        prefix_right(this->root);
    }
    void prefix_right(Node* current){
        if(current != NULL){
            cout << current->getX() << endl;
            prefix_right(current->getRight());
            prefix_right(current->getLeft());
        }
    }

    void central_left(){
        central_left(this->root);
    }
    void central_left(Node* current){
        if(current != NULL){
            central_left(current->getLeft());
            cout << current->getX() << endl;
            central_left(current->getRight());
        }
    }

    void central_right(){
        central_right(this->root);
    }
    void central_right(Node* current){
        if(current != NULL){
            central_right(current->getRight());
            cout << current->getX() << endl;
            central_left(current->getLeft());
        }
    }

    void posfix_left(){
        posfix_left(this->root);
    }
    void posfix_left(Node* current){
        if(current != NULL){
            posfix_left(current->getLeft());
            posfix_left(current->getRight());
            cout << current->getX() << endl;
        }
    }

    void posfix_right(){
        posfix_right(this->root);
    }
    void posfix_right(Node* current){
        if(current != NULL){
            posfix_right(current->getRight());
            posfix_right(current->getLeft());
            cout << current->getX() << endl;
        }
    }


};

int main(){
    BST bst;
    bst.insert(50);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    

    cout << "print 1:" << endl;
    bst.prefix_left();

    bst.remove(50);
    cout << "print 2:" << endl;
    bst.prefix_left();
}
