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
                    //Go Left
                    if(current->getLeft() == NULL){
                        current->setLeft(new Node(key));
                        return 1;
                    }else{
                        current = current->getLeft();
                    }
                }else if(key > current->getX()){
                    //Go right
                    if(current->getRight() == NULL){
                        current->setRight(new Node(key));
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
        remove(key, this->root);
    }

    Node* remove(int key, Node* parent){
        if(parent == NULL) return parent;

        //Se a chave for menor que o valor no nodo atual, roda a função na sub-àrvore à esquerda
        if(key < parent->getX()){
            parent->setLeft(remove(key, parent->getLeft()));
        }
        //Se a chave for menor que o valor no nodo atual, roda a função na sub-àrvore à direita
        else if(key > parent->getX())){
            parent->setRight(remove(key, parent->getRight()));
        }
        //Se a chave for igual ao valor no nodo atual, deleta o nodo atual
        else{

        }

    }
    Node* min_value(){
        min_value(this->root);
    }

    Node* min_value(Node* current){
        if(current->hasLeft()){
            min_value(current);
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
    bst.insert(10);
    bst.insert(8);
    bst.insert(11);
    

    cout << "print:\t" << endl;
    bst.prefix_left();

    bst.remove();
    bst.prefix_left();
}